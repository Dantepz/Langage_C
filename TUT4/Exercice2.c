#include <msp430.h>
#include <Afficheur.h>

unsigned int select = 0;
unsigned long int time = 0;
unsigned long int convert = 0;

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
    TA0CCR0 = 12500;

    // Resistance interne
    P1REN |= 0x08;
    P1OUT |= 0x08;

    // Interruption Bouton
    P1IE |= 0x08;
    P1IES |= 0x08;
    P1IFG &= ~(0x08);

    // Afficheur
    Init_USI_SPI();
    Aff_Init();

    __enable_interrupt();

    //Boucle infinie
    while(1);
}

#pragma vector=TIMER0_A1_VECTOR //voir diaporama seance precedente
__interrupt void ma_fnc_timer(void){

    if(select == 0){
        time++;
        if(time>5999){
            time = 0;
        }
        convert = (time/600)*1000+(time%600);
        convert = convert_Hex_Dec(convert);
        Aff_Efface();
        Aff_Points(0x05);
        Aff_valeur(convert);

    }

    //RAZ TAIFG
    TA0CTL &= ~TAIFG;
}

#pragma vector=PORT1_VECTOR
__interrupt void detect_bouton(void){

    select++;

    if(select == 2){
        select = 0;
    }

    if(select == 0){
        time = 0;
    }


    // RAZ P1IFG
    P1IFG &= ~(0x08);

    __delay_cycles(10000);

}