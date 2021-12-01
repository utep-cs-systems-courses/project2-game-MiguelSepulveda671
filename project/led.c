#include <msp430.h>
#include "led.h"


unsigned char red_on = 0, green_on = 0;
unsigned cher led_chaged = 0;

static char redval[] = {0,LED_RED}, greenval[] = {0, LED_GREEN};

void led_init()
{
  P1DIR |= LEDS; // bits ateached to LEDs are output
  led_changed = 1;
  led_update();
}
void led_update()
{
  if(led_changed)
    {
      char ledflags = redcal[red_on] | greenval[green_on];

      P1OUT &= (0xff - LEDS) | ledflags;
      P1OUT |= ledflags;
      led_changed = 0;
    }
}
