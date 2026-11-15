#include "tic-tac-toe.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int main(){
    char **plateau = creation_plateau();
    int tour = 0; // 0 pour le joueur ('X') et 1 pour l'ordinateur ('O')
    bool victoire = false;
    bool egalite = false;
    int multi = mode_multi();
    afficher_plateau(plateau);
    while (victoire == false && egalite == false) // tant qu'il n'y a ni victoire, ni égalité on continue la boucle de jeu
    {   
        if (tour == 0) // tour du joueur 1
        {
            tour_joueur(plateau, 'X');
            victoire = verification_victoire(plateau, 'X');
            tour = 1; // donne le tour à l'ordinateur
        }
        else{ // tour de l'ordinateur ou du joueur 2
            if (multi == 1)
            {
                tour_bot(plateau);
            }
            else
            {
                tour_joueur(plateau, 'O');
            }
            victoire = verification_victoire(plateau, 'O');
            tour = 0; // donne le tour au joueur
        }
        egalite = verification_egalite(plateau);
        sleep(1); // fais une pause de une seconde pour l'affichage
    }
    system("clear"); // permet de rafraichir le terminal
    if (victoire == true && tour == 1) // affichage des messages de fin en fonction du résultat
    {   
        if (multi == 1)
        {
            printf("C'est gagné!\n");
        }
        else
        {
            printf("C'est gagné pour le joueur X!\n");
        }
        
    }
    else if (victoire == true && tour == 0)
    {
        if (multi == 1)
        {
            printf("C'est perdu!\n");
        }
        else
        {
            printf("C'est gagné pour le joueur O!\n");
        }
    }
    else
    {
        printf("Match nul!\n");
    }
    free_tab(plateau); // libération de la mémoire allouée pour le plateau
    return 0;
}