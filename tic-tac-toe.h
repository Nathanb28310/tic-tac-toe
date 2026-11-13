#ifndef __TIC_TAC_TOE__
#define __TIC_TAC_TOE__

void free_tab(char **plateau);
char ** creation_plateau();
void afficher_plateau(char **plateau);
char ** tour_joueur(char** plateau);

#endif