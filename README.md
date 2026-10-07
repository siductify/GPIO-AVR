# GPIO-AVR
Baremetal GPIO driver for AVR based Arduino Uno Dev-Board
This has 2 main sections, main.c and main.h: The main.h is the header folder. It contains:

MAIN.h
|
|
|____ define HIGH, LOW, INPUT, OUTPUT, INPUT PULLUP
|
|
|____ Enumeration for Ports from PA_0 to PF_7
|
|
|____ pinmode
|____ digitalWrite
|____ digitalToggle
|____ digitalPWM
|____ digitalRead

MAIN.c
|
|
|____ pinmode logic
|____ digitalWrite logic
|____ digitalToggle logic
|____ digitalPWM logic
|____ digitalRead logic
