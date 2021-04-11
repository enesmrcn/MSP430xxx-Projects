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


#include "io430.h"


int main( void )
{
 
  // stop watchdog timer
  WDTCTL = WDTPW | WDTHOLD;
 
  P1DIR |= 0x01;        //
  
  volatile unsigned int i = 50000;      // variable for generating some delay
    
   while (1)
   {
   
    P1OUT ^= 0x01;      // toggle the led
      
      // mcu will wait while processing below
      do {
       
      --i;
      
     } while(i != 0);
   }
   
  return 0;
}
