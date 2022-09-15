#include <stdio.h>
#define BIT0    0x01
#define BIT1    0x02
#define BIT2    0x04
#define BIT3    0x08
#define BIT4    0x10

int main()
{
  unsigned char PIN=0;
  int choix;
  while(1)
  {
     printf("Simulation d'un microcontroleur :\n");
     printf("1 - Allumage lampes L1 et L2 (Fermeture interrupteur)\n");
     printf("2 - Extinction lampes L1 et L2 (Ouverture interrupteur)\n");
     printf("3 - Allumage/extinction lampe L3 (Appui bouton-poussoir)\n");
     printf("4 - Quitter\n");
     scanf("%d", &choix);
     PIN &= ~BIT1;          //reinit bouton poussoir
     switch(choix)
     {
         case 1 :       //interrupteur sur bit 0 du port
             PIN |= BIT0; //inverse
             break;
         case 2 :
             PIN &= ~BIT0;
             break;
         case 3 :       //bouton-poussoir sur bit 1 du port
             PIN |= BIT1;
             break;
         default :
             return 0;
     }
     if((PIN&BIT0) == BIT0)   //interrupteur / lampes L1
     {
        PIN |= BIT2;              //allumage lampe L1
        PIN |= BIT3;              //allumage lampe L2
     } else
     {
        PIN &= ~BIT2;        //extinction lampe L1
        PIN &= ~BIT3;           //extinction lampe L2
     }
     if((PIN&BIT1) == BIT1)           //bouton-poussoir / lampe L3
     {
        PIN ^= BIT4;            //changement d'etat lampe L3
     }
     //visualisation
     if((PIN&BIT2) == BIT2)       //lampe 1
        printf("lampe L1 allumee\n");
     else
        printf("lampe L1 eteinte\n");

    if((PIN&BIT3) == BIT3)       //lampe 2
        printf("lampe L2 allumee\n");
     else
        printf("lampe L2 eteinte\n");
    if((PIN&BIT4) == BIT4)       //lampe 3
        printf("lampe L3 allumee\n");
     else
        printf("lampe L3 eteinte\n");
     printf("-------------------------------------------\n\n");
     getchar();
  }
}