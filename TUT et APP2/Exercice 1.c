#include <msp430.h> 
#include <ADC.h>
#include <Afficheur.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;    // stop watchdog timer
    
    P1DIR |= 0x41;
    P1OUT = 0x01;

    Init_USI_SPI();

    while(1){
        P1OUT ^= 0x41;
        __delay_cycles(500000);
    }
}
