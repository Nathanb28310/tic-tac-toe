#include <stdio.h>
#include <stdlib.h>

int size = 3;

void free_tab(char **plateau)
{
    int i = 0;

    while (i < 3)
    {
        free(plateau[i]);
        i = i + 1;
    }
    free(plateau);
}

char** creation_plateau(){
    char ** plateau = malloc(size * sizeof(char*));
    int i = 0;
    int j = 0; 
    while (i < size)
    {
        plateau[i] = malloc(size * sizeof(char));
        j = 0;
        while (j < size)
        {
            plateau[i][j] = ' ';
            j++;
        }
        i++;
    }
    return plateau;
}