#include <msp430.h>
#include <ADC.h>
#include <Afficheur.h>

unsigned int c;


int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;    // stop watchdog timer

    // Clignotement
    P1DIR |= 0x41;
    P1OUT = 0x01;
    // -----------

    //Pour les leds XIN et XOUT, on force les P2SEL
    P2SEL &= ~(0xC0);
    P2SEL2  &= ~(0xC0);

    //Sorties pour les leds et entrée pour les interrupteurs
    P2DIR  = 0xF0;

    //Initialisation à 0 des sorties et activation des resistances
    P2OUT = 0x0F;

    //Pour gérer pull up ou pull down
    P2REN |= 0x0F;

    //Init Afficheur
    Aff_Init();

    while(1)
    {
        // Clignotement
        P1OUT ^= 0x41;
        __delay_cycles(1000000);
        // ----------------

        P2REN ^= 0x0F;

        c = convert_Hex_Dec(P2IN & 0x0F);
        Aff_Efface();
        Aff_valeur(c);

        P2OUT &= 0x0F;

        P2OUT |= (P2IN & 0x01)<<6;
        P2OUT |= (P2IN & 0x02)<<6;
        P2OUT |= (P2IN & 0x04)<<3;
        P2OUT |= (P2IN & 0x08)<<1;

    }
}