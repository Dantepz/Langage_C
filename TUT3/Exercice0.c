#include <msp430g2553.h>

unsigned int bouton = 0;

#pragma vector=PORT1_VECTOR
__interrupt void detect_bouton(void) {
    P1OUT ^= (BIT0) ;
    if(bouton == 0)
        bouton = 1;
    else
        bouton = 0;
    __delay_cycles(100000);
    P1IFG &= ~(0x08);       // RAZ flag d’interruption
}

void main( void ) {
    WDTCTL = WDTPW | WDTHOLD; // arrêt du Watchdog

    P1DIR |= 0x41;          // led verte BIT6 et led rouge BIT0
    P1DIR &= ~(0x08);       //entrée-sortie

    P1OUT |= 0x08;          // détection du bouton BIT3

    P1REN |= 0x08;          // activation résistance interne
    P1OUT |= 0x08;          // mode pull-up force à 1

    P1IE |= 0x08;           // initialisation de l'interruption
    P1IES |= 0x08;          // interruption sur front descendant
                            // donc appui car bouton connecte a la masse
    P1IFG &= ~(0x08);       // RAZ flag d’interruption

    __enable_interrupt();   // activation générale des interruptions

    while(1) {
        P1OUT ^= 0x40;
        if(bouton == 0)
                __delay_cycles(125000); //4Hz
        else
                __delay_cycles(250000); //2Hz
    }
}