/*This first part is to make sure the Header is only included once*/
#ifndef BRADPITT_AVR_GPIO_H
#define BRADPITT_AVR_GPIO_H
/*This part here is not for the user, but for the program to understand which microcontroller is being used */
#include <avr/io.h>

 #if defined(__AVR_ATmega328P__)
   #define MICRO_TYPE "ATmega328"

 #elif defined(__AVR_ATmega2560__)
   #define MICRO_TYPE "ATmega2560"  

 #elif defined (__AVR_ATmega32__)
   #define MICRO_TYPE "ATmega32"

 #else
   #define MICRO_TYPE "Unknown"
#endif
/*This is for defining the pin mode in english so that the user need not remember the values while using HAL*/
#define HIGH 1
#define LOW 0
#define INPUT 0
#define OUTPUT 1
#define INPUT_PULLUP 2
/*This is the section for C++ compatibility*/
#ifdef __cplusplus
extern "C" {
#endif
/*This section is for enumerating the pins from 0 to 47*/
typedef enum{
    PA_0, PA_1, PA_2, PA_3, PA_4, PA_5, PA_6, PA_7,
    PB_0, PB_1, PB_2, PB_3, PB_4, PB_5, PB_6, PB_7,
    PC_0, PC_1, PC_2, PC_3, PC_4, PC_5, PC_6, PC_7,
    PD_0, PD_1, PD_2, PD_3, PD_4, PD_5, PD_6, PD_7,
    PE_0, PE_1, PE_2, PE_3, PE_4, PE_5, PE_6, PE_7,
    PF_0, PF_1, PF_2, PF_3, PF_4, PF_5, PF_6, PF_7
} pin_t;

void pinMode (pin_t pin, uint8_t pinmodeval);

void digitalWrite (pin_t pin, uint8_t pinvalue);

void digitalToggle (pin_t pin);

void digitalPWM(pint_t pin, uint8_t dutyscycle);

int8_t digitalRead (pin_t pin);

#ifdef __cplusplus
}
#endif
#endif
