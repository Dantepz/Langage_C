#include <msp430.h>
#include <ADC.h>
#include <Afficheur.h>

unsigned int i = 0;
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

        P2OUT &= 0x0F;

        switch(i){

            case 1: P2OUT = 0x4F; break;
            case 2: P2OUT = 0x8F; break;
            case 3: P2OUT = 0x2F; break;
            case 4: P2OUT = 0x1F; break;
            default : break;

        }

        c = convert_Hex_Dec(i);
        Aff_Efface();
        Aff_valeur(c);

        if((P2IN & 0x01) == 0x01){
            i++;
        }else{
            i--;
        }

        if(i>=5){
            i = 1;
        }
        if(i<=0){
            i = 4;
        }
    }
}