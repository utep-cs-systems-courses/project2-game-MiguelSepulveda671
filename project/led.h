#ifndef led_include
#define led_include
#include <msp430.h>

#define LED_RED BIT0  // p1.0

#define LED_GREEN BIT6    // p1.6

#define LEDS (BIT0 | BIT6)


void led_init(); //initialize LEDS
void led_update(); // update LEDs

//these are boolenas
extern unsigned char led_changed, green_on, red_on

  #endif


  
