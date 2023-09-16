#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int value;

int continuation() {
    printf("Voulez vous continuer le jeu? 1.oui 2.non\n");
    scanf(" %d",&value);
    if (value != 1 && value != 2){
        printf("Erreur\n");
    } else if (value == 2) {
        return 0;
    }
}

int main() {
    srand(time(NULL));
    int randomprice = rand() %1000 + 1;

    printf("Bienvenu au juste prix ! Le but de ce jeu est de deviner un prix exact, compris entre 1 et 1000 euros. Si vous devinez le prix, vous le remportez ! A chaque tentative, vous proposez un nombre, et je vous indique s'il est supérieur ou inférieur au prix à deviner. Bonne chance !\n");

    int playerprice;
    while (value != 2){
        printf("Essayez de deviner le juste prix :\n");
        scanf(" %d",&playerprice);

        if (playerprice <= 1 || playerprice >=1000){
            printf("Veuillez donner un nombre compris entre 1 et 1000.\n");
        } else if (playerprice < randomprice ){
            printf("C'est plus !\n");
            continuation();
        } else if (playerprice > randomprice ){
            printf("C'est moins !\n");
            continuation();
        } else if (playerprice == randomprice){
            printf("Bravo, vous avez trouvé le juste prix !\n");
            return 0;
        }

    }
}

