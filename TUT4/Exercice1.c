#include <msp430.h>

unsigned long int c = 0;

void main(void)
{
    // Desactivation Watch Dog Timer
    WDTCTL = WDTPW | WDTHOLD;

    // Frequence d’horloge 1MHz
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    // Source SMCLK et prédivision (ID_0 -- ID_3 => 1 -- 8)
    TA0CTL = TASSEL_2 | ID_3;

    // Comptage en mode up
    TA0CTL |= MC_1;

    // Autorisation interruption TAIE
    TA0CTL |= TAIE;

    // Temps mesuré en us
    TA0CCR0 = 62500;

    // Clignotement
    P1DIR |= 0x01;
    P1OUT = 0x01;
    // -----------

    // Resistance interne
    P1REN |= 0x08;
    P1OUT |= 0x08;

    // Interruption Bouton
    P1IE |= 0x08;
    P1IES |= 0x08;
    P1IFG &= ~(0x08);

    __enable_interrupt();

    //Boucle infinie
    while(1);
}

#pragma vector=TIMER0_A1_VECTOR //voir diaporama seance precedente
__interrupt void ma_fnc_timer(void)
{
    if(c == 1){
        //Extinction de la LED
        P1OUT &= ~BIT0;

        //Clear du timer
        TA0CTL |= BIT2;

        //RAZ du double compteur
        c = 0;
    }
    else c = 1;

    //RAZ TAIFG
    TA0CTL &= ~TAIFG;
}

#pragma vector=PORT1_VECTOR
__interrupt void detect_bouton(void){

    // Allumage de LED
    P1OUT |= BIT0;

    // Prédivision (ID_0 -- ID_3 => 1 -- 8)
    TA0CTL |= ID_3;

    // Comptage en mode up
    TA0CTL |= MC_1;

    // Compteur TA0CCR0
    TA0CCR0 = 62500;

    // RAZ du double compteur
    c = 0;

    // RAZ P1IFG
    P1IFG &= ~(0x08);

}