#include <msp430.h> 
#include <ADC.h>
#include <Afficheur.h>

unsigned int i = 0;
unsigned int c;


int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;    // stop watchdog timer

     //Affichage des leds
    P1DIR |= 0x41;
    P1OUT = 0x01;

    Init_USI_SPI();
    Aff_Init();
    Aff_Luminosite(255);

    while(1){
        P1OUT ^= 0x41; // Inversion des leds
        __delay_cycles(1000000);
        Aff_Efface();

        c = convert_Hex_Dec(i);
        Aff_valeur(c);
        if(i == 9999){
            i=0;
        }else i++;
    }

}
