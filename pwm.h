#ifndef __LANTERN_PWN_H__
#define __LANTERN_PWN_H__

#include "pwm.h"

// AS IS ; it is designed for ATmega328 (aka "arduino uno" hardware or look-alikes)
// NOTE : _DO_NOT_ use in an "arduino sketche/project" (unless you know what you're _EXACTLY_ doing : "Arduino API" use some timers on it's own, this will interfere) 

// All counters are prescaled to 256 for now (so tick frequency is 16MHz /256 for arduino uno == 62500 and PWM freq is 62500/256 about 244Hz. Maybe flies will see the blinking, but none of us)
// _ALL_ counter are set to have a top of OxFF, meaning we do NOT take advantage of 16-bit timer 1, just use it as 8-bit one
// Also _ALL_ timers are set in PWM "phase-coorect mode" (hum, I guess is divides the frequency by 2). Fast PWM mode would do the job anyway...
// See : http://www.atmel.com/Images/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf pp 138 and following


class PWM {
  public:
    static const nbTimer = 3; // SHOULD be conditionned by the acual chip we compile for ; to allow more portability. 
      
    PWM(unit8_t timerNumber);
    ~PWM();
    
    bool setDuty(uint8_t value); // True when duty correctly set. NB : Should never return false, unless !valid()
    
    inline bool isValid(); // true if the object is operationnal, if false it's unreliable (channel already allocated, ...)
    
  protected:
    bool _valid;
    uint8_t _timerNumber;

    // class ("static") members
    static uint8_t allocatedTimers; // bit-map. If channel N is allocated, corresponding bit is set.
//# hu-humm seems useless
//  static bool firstInitDone; // the first PWM object initialise global 
};



bool PWM::valid() {
    return _valid;
}

#endif
