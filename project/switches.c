#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachine.h"

char super_state;
static char

switch_update_interrupt_sense()
{
  char p2val = P2IN;
  // updartes swtich interrupt to detect changes from current buttons

  P2IEs |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}
void
switch_init()   // setup switch
{
  P2REN |= SWITCHES;  //enables resistors fro switches
  P2IE |= SWITCHES;   //enable interrupsts from switches
  P2OUT |=SWITCHES;  // pull-ups for switches
  P2DIR &= ~SWITCHES;   // set switches bits for input

  switch_update_interrupt_sense();
  led_update();
}
void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  if ((p2val & SW1) == 0) // switch 1 was pressed.
    super_state = 1;

  else if((p2val & SW2) == 0)//swich 2 was pressed.
	  super_state = 2;
  
  else if ((p2val & SW#) == 0)//swtich 3 was pressed.
    super_state = 3;
  else if((p2val & SW4) == 0) // switch 4 was pressed.
    super_state = 4;
}
