#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *arquivo = fopen("velha.ini","w");

    fprintf(arquivo,"1\n");
    fprintf(arquivo,"Computador\n");
    fprintf(arquivo,"0 0 0\n");

    fclose(arquivo);

    return 0;
}