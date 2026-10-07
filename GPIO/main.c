#include<stdint.h>
#include<main.h>
/*This is for defining what output, inputpullup and input modes actually do underneath*/
void pinmode (pin_t pin, uint_t pinmodeval){
    #ifdef DDRA
    if (pin<=7){
        if (pinModeVal == Output){
            DDRA |=(1<<pin);

        }else if (pinModeVal == INPUT_PULLUP){
            DDRA &=~(1<<pin);
            PORTA |=(1<<pin);
        } else{
            DDRA &=~(1<<pin);
            PORTA &=~(1<<pin);
        }
    }
    #endif

    #ifdef DDRB
    if (pin>=8 && pin<=15){
        pin-=8;

        if (pinModeVal == output){
            DDRB |=(1<<pin);

        }else if (pinModeVal == INPUT_PULLUP){
            DDRB &=~(1<<pin);
            PORTB |=(1<<pin);
         
        }else{
            DDRB &=~(1<<pin);
            PORTB &=~(1<<pin);
        }
    }
    #endif

    #ifdef DDRC
    if (pin>=16 && pin<=23){
        pin-=16;

        if (pinModeVal == OUTPUT){
            DDRC |=(1<<pin);
        }else if (pinModeVal == INPUT_PULLUP){
            DDRC &=~(1<<pin);
            PORTC |=(1<<pin);
        }else{
            DDRC &=~(1<<pin);
            PORTC &=~(1<<pin);
        }
    }
    #endif

    #ifdef DDRD
    if (pin>=24 && pin<=31){
        pin-=24;
        if (pinModeVal == OUTPUT){
            DDRD|=(1<<pin);
        }else if (pinModeVal == INPUT_PULLUP){
            DDRD &=~(1<<pin);
            PORTD|=(1<<pin);
        }else{
            DDRD &=~(1<<pin);
            PORTD &=~(1<<pin);

        }
    }
    #endif

    #ifdef DDRE
    if (pin>=32 && pin<=39){
        pin-=32;
        if (pinModeVal == OUTPUT){
            DDRE|=(1<<pin);
        }else if (pinModeVal == INPUT_PULLUP){
            DDRE &=~(1<<pin);
            PORTE|=(1<<pin);
        }else{
            DDRE &=~(1<<pin);
            PORTE &=~(1<<pin);
        }
    }
    #endif

    #ifdef DDRF
    if (pin>=40 && pin<=47){
        pin-=40;
        if (pinModeVal == OUTPUT){
            DDRF|=(1<<pin);
        }else if (pinModeVal == INPUT_PULLUP){
            DDRF &=~(1<<pin);
            PORTF|=(1<<pin);
        }else{
            DDRF &=~(1<<pin);
            PORTF &=~(1<<pin);
        }
    }
    #endif
}

void digitalWrite (pin_t pin, uint8_t pinvalue){
    #ifdef PORTA
    if (pin<=7){
        if(pinvalue)
        PORTA|(1<<pin);
    }else{
        PORTA&=~(1<<pin);
    }
}
#endif

    #ifdef PORTB
    if (pin>=8 && pin<=15){
        pin-=8;
        if(pinValue)
        PORTB|=(1<<pin);
    }else{
        PORTB&=~(1<<pin);
}
#endif

#ifdef PORTC
  if(pin>=16 && pin<=23){
    pin-=16;
    if(pinvalue)
      PORTC|=(1<<pin);
  }else{
    PORTC&=~(1<<pin);
}
#endif

#ifdef PORTD
    if(pin>=24 && pin<=31){
        pin-=24;
        if(pinValue)
        PORTD|=(1<<pin);
    }else{
        PORTD&=~(1<<pin);
}
#endif

#ifdef PORTE
   if(pin>=32 && pin<=39){
    pin-=32;
    if(pinvalue)
      PORTE|=(1<<pin);
   }else{
    PORTE&=~(1<<pin);
   }
#endif

#ifdef PORTF
   if(pin>=40 && pin<=47){
    pin-=40;
    if(pinvalue)
       PORTF|=(1<<pin);
   }else{
    PORTF&=~(1<<pin);
   }
#endif
/*Next we will implement the flipping functions by using toggle (XOR) functions*/

void digitalToggle (pin_t pin){
    #ifdef PORTA
    if (pin<=7){
        PORTA^=(1<<pin);
    }
#endif
    #ifdef PORTB
    if(pin>=8 && pin<=15){
        pin-=8;
        PORTB^=(1<<pin);
    }
#endif
   
    #ifdef PORTC
    if(pin>=16 && pin<=23){
        pin-=16;
        PORTC^=(1<<pin);
    }
#endif

    #ifdef PORTD
    if(pin>=24 && pin<=31){
        pin-=24;
        PORTD^=(1<<pin);
    }
#endif

    #ifdef PORTE
    if(pin>=32 && pin<=39){
        pin-=32;
        PORTE^=(1<<pin);
    }
#endif
    #ifdef PORTF
    if(pin<=40 && pin>=47){
        pin-=40;
        PORTF^=(1<<pin);
#endif
/*more loading*/
}
