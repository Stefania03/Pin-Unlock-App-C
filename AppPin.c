/******************************************************************************
 *                           PINUL UNEI APLICATII                             *

Setam pinul de acces intr-o aplicatie cu 1999.
Utilizatorul trebuie sa introduca pinul pentru a debloca aplicatia si este
avertizat ca acesta trebuie sa fie format din 4 cifre.
Are 3 incercari la dispozitie.

Daca introduce din greseala un pin cu mai mult sau mai putin de 4 cifre, se
genereaza mesaj de eroare "Codul pin are format gresit. Te rog, reincearca!"
si nr de incercari ramase scade.

Daca introduce un pin diferit de 1999(pinul setat din program), se genereaza
mesaj de eroare "COD PIN introdus gresit. Te rog, reincearca!" si nr de
incercari ramase scade.

Daca pinul introdus este corect, se geenreaza mesajul "Cod pin corect!
Aplicatia se deschide..."

Daca pinul se introduce gresit de 3 ori, aplicatia se va inchide.

 *****************************************************************************/
#include <stdio.h>

int main() {
 
    int pin, incercari = 3;

    printf("Te rog, introdu pin-ul pe care il doresti pentru aceasta aplicatie!\n");
    printf("Nota, pin-ul va fi format din 4 cifre!\n");

    while (1) {
        printf("Introdu pin-ul: ");
        scanf("%d", &pin);

        int auxPin = pin;
        int nr_cifre = 0;

        while(auxPin != 0) {
            nr_cifre++;
            auxPin /= 10;
        }

        if (nr_cifre < 4 || nr_cifre > 4) {
            printf("Codul pin are format gresit. Te rog, reincearca!\n");
            printf("Mai ai %d incercari\n", --incercari);
        } else if (pin != 1999) {
            printf("COD PIN introdus gresit. Te rog, reincearca!\n");
            printf("Mai ai %d incercari\n", --incercari);
        } else if (pin == 1999) {
            printf("Cod pin corect! Aplicatia se deschide...\n");
            return 0;
        }

        if (incercari == 0) {
            printf("Ai epuizat numarul de incercari!\n");
            break;
        }
    }

    return 0;
}