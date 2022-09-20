#include <msp430.h> 
#include <ADC.h>
#include <Afficheur.h>

unsigned int i = 0;
unsigned int c;


int main(void)
{
     WDTCTL = WDTPW | WDTHOLD;    // stop watchdog timer

     //Pour les leds XIN et XOUT, on force les P2SEL
     P2SEL &= ~(0xC0);
     P2SEL2  &= ~(0xC0);

     //Sorties pour les leds
     P2DIR  |= 0xF0;

     //Entrées pour les interrupteurs
     P2DIR &= ~(0x0F);

     //Initialisation à 0 des sorties
     P2OUT &= ~(0xF0);

     //Pour gérer pull up ou pull down
     P2REN |= 0x0F;
     P2OUT |= 0x0F;

    while(1) // Boucle infinie, on n’arrête pas le microP
    {
        if( ( P2IN | ~BIT0 ) == ~BIT0) // Test si la broche est à l’état bas (poussoir appuyé)
        {
            P2OUT  &= ~BIT6;// éteint la LED
        }else { P2OUT|= BIT6;} //allume la LED

        if( ( P2IN | ~BIT1 ) == ~BIT1) // Test si la broche est à l’état bas (poussoir appuyé)
        {
            P2OUT &= ~BIT7; //etteind la LED
        }else { P2OUT |= BIT7;} // on allume la LED

        if( ( P2IN | ~BIT2 ) == ~BIT2) // Test si la broche est à l’état bas (poussoir appuyé)
        {
            P2OUT &= ~BIT5; //etteind la LED
        }else { P2OUT |= BIT5;}  // on allume la LED

        if( ( P2IN | ~BIT3 ) == ~BIT3) // Test si la broche est à l’état bas (poussoir appuyé)
        {
            P2OUT &= ~BIT4; //etteind la LED
        }else { P2OUT |= BIT4;} // on allume la LED
    }


}
