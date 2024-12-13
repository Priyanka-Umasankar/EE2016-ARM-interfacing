#include "LPC214x.H"                      
#include "led.h"
#include "delay.h"

#define DIP_SW_D0 (1 << 16) // P0.16
#define DIP_SW_D1 (1 << 17) // P0.17
#define DIP_SW_D2 (1 << 18) // P0.18
#define DIP_SW_D3 (1 << 19) // P0.19

#define DIP_SW_D4 (1 << 22) // P0.22
#define DIP_SW_D5 (1 << 23) // P0.23
#define DIP_SW_D6 (1 << 24) // P0.24
#define DIP_SW_D7 (1 << 25) // P0.25

#define DIP_SW_DIR IO1DIR
#define DIP_SW_PIN IO1PIN

#define DIP_SW_DATA_MASK (DIP_SW_D7 | DIP_SW_D6 | DIP_SW_D5 | DIP_SW_D4 | DIP_SW_D3 | DIP_SW_D2 | DIP_SW_D1 | DIP_SW_D0)

void set_dipswitch_port_input( void )
{
DIP_SW_DIR &= ~(DIP_SW_DATA_MASK);
}

unsigned long read_dip_switch( void )
{
return DIP_SW_PIN;
}


int main (void)
{
unsigned long sw_status, n1, n2;

set_led_port_output();
set_dipswitch_port_input();

while(1)
{
sw_status = read_dip_switch();
n1 = sw_status;
n2 = (sw_status >> 6) & 0x000F0000;
n1 &= 0x000F0000;
sw_status = n1*n2;

if(sw_status & DIP_SW_D7>>2){ LED8_ON;} else{ LED8_OFF;}
if(sw_status & DIP_SW_D6>>2){ LED7_ON;} else{ LED7_OFF;}
if(sw_status & DIP_SW_D5>>2){ LED6_ON;} else{ LED6_OFF;}
if(sw_status & DIP_SW_D4>>2){ LED5_ON;} else{ LED5_OFF;}

if(sw_status & DIP_SW_D3){ LED4_ON;} else{ LED4_OFF;}
if(sw_status & DIP_SW_D2){ LED3_ON;} else{ LED3_OFF;}
if(sw_status & DIP_SW_D1){ LED2_ON;} else{ LED2_OFF;}
if(sw_status & DIP_SW_D0){ LED1_ON;} else{ LED1_OFF;}

delay_mSec(10);
}
}
