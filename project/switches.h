#ifndef switch_include
#define switches_include

#define SW1 BIT0  //switch1 is p2.0
#define SW2 BIT1  //switch2 is p2.1
#define SW3 BIT2  //swtich3 is p2.2
#define SW4 BIT3  // switch is p2.3

#define SWITCHES (SW1 | SW2 | SW3 | SW4) // 4 swtiches on board

void switch_init();
void Switch_iterrupt_handler();

extern char super_state;

#endif
