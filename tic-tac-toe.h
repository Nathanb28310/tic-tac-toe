#ifndef __TIC_TAC_TOE__
#define __TIC_TAC_TOE__
#include <stdbool.h>

void free_tab(char **plateau);
char ** creation_plateau();
void afficher_plateau(char **plateau);
bool verification_victoire(char** plateau, char symbole);
bool verification_egalite(char** plateau);
int tour_joueur(char** plateau);
void **tour_bot(char** plateau);

#endif