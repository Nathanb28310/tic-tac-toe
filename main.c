#include "tic-tac-toe.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char **plateau = creation_plateau();
    afficher_plateau(plateau);
    free_tab(plateau);
    return 0;
}