#include "tic-tac-toe.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char **plateau = creation_plateau();
    free_tab(plateau);
    return 0;
}