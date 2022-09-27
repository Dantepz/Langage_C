// Exemple de cours sans interruption
#include <msp430g2553.h>

void attente_timer() {
    while(!(TA0CTL & TAIFG));
    TA0CTL &= ~TAIFG;
}

void main( void ) {
    WDTCTL = WDTPW | WDTHOLD;       // Arrêt du WDT

    BCSCTL1 = CALBC1_1MHZ;           // Frequence d'horloge 1MHz
    DCOCTL = CALDCO_1MHZ;            // Idem

    P1DIR |= BIT0;                  // Bit 0 du port 1 (Led rouge) en sortie
    TA0CTL = 0|(TASSEL_2 | ID_0);   // Source SMCLK, pas de predivision ID_0
    TA0CTL |= MC_1;                 // Comptage en moden up
    TA0CCR0 = 27776;

    while(1) {
        P1OUT ^= BIT0;              // Changement d'état de la LED rouge
        attente_timer();            // Attente utilisant le timer
    }
}

// Exemple du cours avec interruption
#include <msp430g2553.h>

void main( void ) {
    WDTCTL = WDTPW | WDTHOLD;       // Arrêt du WDT

    BCSCTL1 = CALBC1_1MHZ;           // Frequence d'horloge 1MHz
    DCOCTL = CALDCO_1MHZ;            // Idem

    P1DIR |= BIT0;                  // Bit 0 du port 1 (Led rouge) en sortie
    TA0CTL = 0|(TASSEL_2 | ID_0);   // Source SMCLK, pas de predivision ID_0
    TA0CTL |= MC_1;                 // Comptage en moden up
    TA0CTL |= TAIE;                 // Autorisation interruption TAIE
    TA0CCR0 = 27776;

    __enable_interrupt();

    while(1);
}

#pragma vector=TIMER0_A1_VECTOR
__interrupt void ma_fnc_timer(void) {
    P1OUT ^= BIT0;                  // Changement d'état de la LED rouge
    TA0CTL &= ~TAIFG;               // RAZ TAIFG
}
