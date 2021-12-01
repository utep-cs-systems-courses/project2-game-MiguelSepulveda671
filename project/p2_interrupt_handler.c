#include <msp430.h>
#include "switch.h"

// swithces on p2
void

___interrupt_vec(PORT2_VECTOR) port_2()
{
  if (P2IFG & switches) // did a button 
    {
      P2IFG &= ~SWITCHES;  // clear ththe pendin switches interrupst
      switch_iterrupt_handler(); // a single handler for all the switches
      
    }
}
