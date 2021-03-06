#include <msp430.h>
#include "stateMachines.h"

char super_state = 0;
void
__interrupt_vec(WDT_VECTOR) WDT()  // 250 INTERRUPS/SEC
{
  static char s1Count = 0;
  static char s2Count = 0;


  //every half of a second
  if(super_state == 1)
    {
      if(++ s1Count == 125)
	{
	  state_advance();
	  s1Count = 0;
	}
    }
  // every 1/10 if a second interrupts and changes states every econf
  else if(super_state == 2)
    {
      if((++ s2Count % 25) == 0) buzzer_advance();
      if(s2Count == 250)
	{
	  state_advance();
	  s2Count = 0;
	}
    }
  // always interrupted
  else
    {
      state_advance();
    }
}
