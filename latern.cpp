#include <avr/io.h>
#include <avr/interrupts.h>

#include "adc.h"
#include "pwm.h"
#include "prng.h"


const uint8_t NB_CANDLES = 3;

void main(void) {
    uint8_t red[NB_CANDLES] = {0};
    uint8_t yellow[NB_CANDLES] = {0};
    
    int seed = sensor_read(0);
    // init random() with seed
    init_PWM();
    
    while(1) {
        for (uint8_t i=0; i<NB_CANDLES; i++) {
            red[i] = RED_BASE + random(RED_AMPLITUDE);
            yellow[i] = YELLOW_BASE + random(YELLOW_AMPLITUDE);
        }
    }
}
