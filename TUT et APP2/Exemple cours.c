#include <msp430.h> 
#include <ADC.h>
#include <Afficheur.h>

int main(void)
{
     WDTCTL = WDTPW | WDTHOLD;    // stop watchdog timer

    // Le numéro après le P indique la voie utilisée
    P1SEL &= ~(0x09); // Met les bits à 0 pour initialiser les ports P1.0 et P1.3
    P1SEL2 &= ~(0x09); // Idem

    P1DIR &= ~(0x08); // Définit le port numéro 3 à 0 pour l'entrée
    P1DIR |= 0x01; // Définit le port numéro 0 à 1 pour la sortie

    P1OUT &= ~(0x01); // Définition de la led eteinte par défaut

    P1REN |= 0x08;
    P1OUT |= 0x08;

    while(1){
        // Si notre bouton est à 1 alors on allume la LED
        if((P1IN | ~0x08) ==  ~0x08) {
            P1OUT |= 0x01;
        }else {
            P1OUT &= ~(0x01);
        }
    }
}
