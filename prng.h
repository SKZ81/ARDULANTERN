#ifndef __LANTERN_ADC_H__
#define __LANTERN_ADC_H__

// This class makes use of random() and srandom() specific function of AVR-libc  
// indeed : libc defines rand() to return an int which is 16 bit in our case... Which is probably still usable, anyway, but the more code, the more fun !! Do you disagree ?

class PseudoRandom {
    PseudoRandom(ADC& adc);         // create a generator Object, tighted to a given ADC 
    uint32_t fetchValue();          // generate random value
    void resetSeed();               // reinitialize ramdomly[*] the Pseudo-rNG sequence 
};


// [*] randomly here, means by reading low bits (that greatly varies du to EM fields noizes in the surrounding).
// It is _NOT_ trustable random, like in a quantum RNG -- but will remain OK for most applications 

#endif
