#define      _DELAY          500     //      maxium : 

#include "io430.h"
#include <stdbool.h>
#include <stdint.h>

void delay(void);

void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;

  P1SEL |= 0x00;         // Input/output function activated
  
  P1DIR=0x41;   //set p1.0 and p1.6 as output for led while p1.3 as input for switch

  
  while (true)
  {
  
      if( (P1IN & 0x08) != 0x08)   // check if switch is pressed or not 
      {
        P1OUT ^= 0x41;      //if pressed toggle the state of led 
        delay();
      }
  
      
     
  }
  
}

void delay(void)
{
  
  uint16_t time = (uint16_t) _DELAY;
  uint8_t  repeat = 100;
  
  while(--time)
    while(--repeat)
      ;;
}