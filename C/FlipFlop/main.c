/*
*
*       BLINKY LED
*
*       Author  -->      Enes Mercan, Turkiye
*       Date    -->      11 April, 2021
*
*       Device  -->     MSP430G2553
*       Complier    -->         Embedded IAR
*/

#define _DELAY  500000

#include "io430.h"
#include <stdint.h>
#include  <stdbool.h>


void main( void )
{
  
  WDTCTL = WDTPW | WDTHOLD;     // disable watchdog timer
  
  volatile uint16_t delay = (uint16_t)_DELAY;   // define varible for delay
  
  // i/o function is enabled
   P1SEL  &= ~(0x65);   // pullup/pulldown resistors are disabled
   
   P1DIR |= 0x01;       //  set green led as output
   P1DIR |= 0x64;       //  set red led as input
   
  
  
  while (true)
  {
     P1OUT ^= 0x01;     // toggle the green led
     P1OUT ^= 0x64;     // toggle the red led
    
     
     while (--delay)    // delay little bit
       ;;  
  }
    
   
}
