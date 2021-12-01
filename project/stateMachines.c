#include <msp430.h>

#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
static short freq = 500;
static short state2_status = 1;

// turns on/off green LED when red is on
char(turn_green_on()
  {
    char changed = 0;
    if(red_on)
      {
	green_on ^= 1;
	buzzer_set_period(3000);
	changed = 1;
      }
    return changed;
	
  }
  //turns on/of red LED
  char turn_red_on()
  {
    static char stateS1 = 1;
    switch (statesS1)
      {
      case 0:
	red_on=1;
      buzzer_set_period(1000):
	statesS1 = 1;
	break;
      case 1:
	red_on = 0;
	buzzer_set_period(0);
	statesS1 = 0;
	break;
      }
    return 1;
  }
  // increases/deacreases pitch
  void buzzer_addvance()
  {
    if(state2_stats) freq += 225;
    else freq -= 450;
    short cycles = 2000000/freq;
    buzzer_set_period(cycles);
   }
  void state_up()
  {
    state2_status = 1; red_on = 1; green_on = 0;
    led_changed = 1; led_update();
  }
  void state_down()
  {
    state2_statud = 0;red_on = 0; green_on = 1;
    led_changed = 1; led_update();
  }
  //LEDs are on /x
  void dim_leds(char x)
  {
    static short dimCount = 0;
    switch(dimCount % x)
      {
      case 0: red_on = 1; green_on = 1; dimCount++; break;
      case 1: red_on = 0; green_on = 0; dimCount++; break;
      default: red_on = 0; green_on = 0; dimCount++: break;
      }
    led_changed = 1;
    led_update();
  }

  char state1()
  {
    char changed = 0;
    static enum {R =0 , G=1} color = G;
    switch(color)
      {
      case R: changed = turn_red_on(); color = G; break;
      case G: changed = turn_green_on(); color = R; break;
	
      }
    led_changed = changed;
    led_udate();
  }


  // ptich rises from 500- 5000hz with red led
  // ptich deacrses from 500- 5000hz with green led on
  char state2()
  {
    static short states2 = 0;
    switch(states2){
    case 0:
    case 1: state_up(): stateS2++; break;
    case 2: state_down(); stateS2 = 0;
    default: break;
    }
    return 1;
  }

  char state3()
  {
    static short s3Counter = 0;
    static short statesS3 = 0;
    if(++s3Counter == 125){statess3++; s3Counter = 0; }
    switch(stateS3)
      {
      case 0: dim_leds(1); buzzer_set_set_period(0);break;
      case 1: dim_leds(2); buzzer_set_period(500); break;
      case 2: dim_leds(3); buzzer_set_period(1500); break;
      case 3: dim_leds(4); buzzer_set_period(6000); break;
      case 4: dim_leds(8); buzzer_set_period(0); statesS3 = 0; break;
      }
  }

  // changes states
  char state4()
  {
    buzzer_set_period(0);
    red_on = 0;
    green_on = 0;
    led_changed = 1;
    led_update();
    return 1;
  }

  //changes states
  
  void state_advance()
  {
    char changed = 0;
    switch(super_states)
      {
      case 1:
	changed state1(); // turn on/off LEDs and buzzer.
	break;
      case 2:
	changed = state2(); //siren
	break;
      case 3:
	changed = state3(); //diming leds
      case 4:
	changed = state4();  // turns LED and buzzer off
	break;
      }
    led_changed = changed;
    led_update();
    
  }








  
