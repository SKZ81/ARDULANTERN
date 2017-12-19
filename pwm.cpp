#include "pwm.h"

PWM::PWM(unit8_t timerNumber) 
  : _timerNumber(timerNumber) 
{
    // once again, straight forward / immediate coding assuming we have 3 timer on ATmega328.
    // set phase correct PWM, 8 bit counting, even on 
    if (allocatedTimers & (1 << timerNumber)) {
        _valid = false;
        // output error on UART
    } else {
        switch (timerNumber) {
            case 0:
                PRR |= 1 << PRTIM0; 
                TCCR0A = 0b10100001; // non inverting mode for both outputs A & B, phase correct mode
                TCCR0B = 0b00001100; // WGM02 is set for phase correct, and prescaler bit '100' => 1/256 
                break;
            case 1:
                PRR |= 1 << PRTIM1;
                TCCR1A = 0b10100001; // non inverting mode for both outputs A & B, phase correct mode (8-bit)
                TCCR1B = 0b00000100; // still 8-bit, prescaling 1/256
                TCCR1C = 0b00000000; // probably useless, doesn't eat much bread
                break;
            case 2:
                PRR |= 1 << PRTIM2;
                TCCR2A = 0b10100001; // non inverting mode for both outputs A & B, phase correct mode 
                TCCR2B = 0b00001100; // WGM22 is set for phase correct, and prescaler bit '100' => 1/256 
                
                break;
            default:
                _valid = false;
                break;
        }
    }
    // reserve allocation in the bitmap if successful
    if (_valid) {
        allocatedTimers |= (1 << timerNumber);
    }
}


PWM::~PWM() {
    // I will write proper deallocation later, not a functionnal priority, as never properly called in given appliance
    // As for now, just stop the counter power

    if (_valid) {
        allocatedTimers &= ~(1 << timerNumber);
        switch(_timerNumber) {
            case 0:
                PPR &= ~(1 << PRTIM0);
                break;
            case 1:
                PPR &= ~(1 << PRTIM1);
                break;
            case 2:
                PPR &= ~(1 << PRTIM2);
                break;                
        }
    }
}


bool PWM::setDuty() {
    if (!_valid) {return false} 
    
    switch(_timerNumber) {
        case 0:
            
    }
