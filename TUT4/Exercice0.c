#include <msp430g2553.h>

#pragma vector=TIMER0_A1_VECTOR
__interrupt void ma_fnc_timer(void) {
    P1OUT ^= BIT0;                  // Changement d'état de la LED rouge
    TA0CTL &= ~TAIFG;               // RAZ TAIFG
}

#pragma vector=PORT1_VECTOR
__interrupt void detect_bouton(void) {
    P1OUT ^= (BIT0);
    P1IFG &= ~(0x08);       // RAZ flag d’interruption

    if(TA0CCR0 == 31250) {
        P1OUT |= 0x40;
        TA0CCR0 = 15625;
    }
    else{
        TA0CCR0 = 31250;
        P1OUT &= ~(0x40);
    }
}

void main( void ) {
    WDTCTL = WDTPW | WDTHOLD;       // arrêt du Watchdog

    BCSCTL1 = CALBC1_1MHZ;          // Frequence d'horloge 1MHz
    DCOCTL = CALDCO_1MHZ;           // Idem

    P1DIR |= 0x41;                  // Bit 0 du port 1 (Led rouge) en sortie
    TA0CTL = 0|(TASSEL_2 | ID_3);   // Source SMCLK, pas de predivision ID_0
    TA0CTL |= MC_1;                 // Comptage en mode up
    TA0CTL |= TAIE;                 // Autorisation interruption TAIE
    TA0CCR0 = 31250;

    P1DIR |= BIT0;                  // led rouge BIT0
    P1DIR &= ~(BIT3);               // entrée-sortie

    P1OUT |= BIT3;                  // détection du bouton BIT3
    P1REN |= BIT3;                  // activation résistance interne
    P1OUT |= BIT3;                  // mode pull-up force à 1

    P1IE |= BIT3;                   // initialisation de l'interruption
    P1IES |= BIT3;                  // interruption sur front descendant
                                    // donc appui car bouton connecte a la masse
    P1IFG &= ~(BIT3);               // RAZ flag d’interruption

    __enable_interrupt();           // activation générale des interruptions

    while(1);
}
