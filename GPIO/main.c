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
}
#endif
   #ifdef PORTG
        if (pin>=48 && pin<=55){
            pin-=48;
            PORTF^=(1<<pin);
        }
#endif
}

/*Next we will define at the digital PWM functions*/

void digitalPWM (pin_t pin, uint8_t dutycycle)
if (dutycycle>100) dutycycle =100;   /*dutycycle is always 100 even if the user sets its value greater than 100*/
dutycylce = dutycycle * 255/100;     /*The duty cycle should be scaled to a 8 bit value*/
#if defined (__AVR_ATMega32A__)      /*only for ATMega32A*/
   if (pin == PB_3){
       pinMode (pin, OUTPUT);                /*COM0 AND COM1 are internal switches that control the PWM output*/
       if (dutycycle == 0){
        TTCR0 &=~(1<<COM01) | (1<<COM00);
        digitalWrite (pin, LOW);
        return;
       }
      OCR0 = dutycycle;                  /*this is for the timer0 to have something to compare against*/
      TTCR0 |=(1<<WGM00) | (1<<WGM01) |(1<<CS01) | (1<<COM01);

   }else if(pin == PD_5){
      pinMode (pin, OUTPUT);
       if(dutycycle == 0){
        TCCR1A &=~(1<<COM1A1)|(1<<COM1A0);
        digitalWrite (pin, LOW);
        return;
       }
       
       OCR1A = dutycycle;
			TCCR1A |= (1 << COM1A1) | (1 << WGM10);
			TCCR1B |= (1 << WGM12) | (1 << CS11);
   }else if(pin == PD_4){
       pinMode (pin, OUTPUT);
       
       if(dutycycle == 0){
				TCCR1A &= ~((1 << COM1B1) | (1 << COM1B0));       
				digitalWrite(pin, LOW);
				
				return;
       }
       OCR1B = dutycycle;
       TCCR1A |= (1<<COM1B1)|(1<<WGM10);
       TCCR1B |= (1<<WGM12)|(1<<CS11);
   }else if(pin == PD_7){
    pinMode (pin,OUTPUT);
    if(dutycycle == 0){
        TCCR2 &=~(1<<COM21)|(1<<COM20);
        digitalWrite(pin, LOW);
        return;
    }
    OCR2 = dutycycle;
    TCCR2 |=(1<<WGM20)|=(1<<WGM21)|(1<<CS21)|(1<<COM21);
   }
   #elif defined (__AVR_ATMega328P__) //this code is only applicable if the device is ATMega328P
   if (pin == PD_6){
    pinMode (pin, OUTPUT);
    if(dutycycle == 0){
        TCCR0A &=~(1<<COM0A1)|(1<<COM0A0);
       digitalWrite (pin, LOW);
        return;
    }
    OCR0A = dutycycle;
    TCCR0A |=(1<<WGM00)|(1<<WGM01)|(1<<COM0A1);
    TCCR0B |=(1<<CS01);
   }else if (pin == PD_5){
    pinMode (pin, OUTPUT);
    if (dutycycle == 0){
        TCCR0A &=~(1<<COM0B1)|(1<<COM0B0);
        digitalWrite (pin, LOW);
        return;
    }
    OCR0B = dutycycle;
    TCCR0A |=(1<<COM0B1)|(1<<WGM00)|(1<<WGM01);
    TCCR0B |=(1<<CS01);
   }else if (pin == PB_1){
    pinMode (pin. OUTPUT)
    if (dutycycle == 0){
        TCCR1A &=~(1<<COM1A1)|(1<<COM1A0);
        digitalWrite (pin, LOW);
        return;
    }
    OCR1A = dutycycle;
    TCCR1A |=(1<<COM1A1)|(1<<WGM10);
    TCCR1B |=(1<<CS11)|(1<<WGM12)|(1<<CS10);
   }else if(pin == PB_2){
    //This is yet to be implemented
   }
