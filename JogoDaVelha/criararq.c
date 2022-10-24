#include <stdio.h>
#include <stdlib.h>

int main(){

    /*Código para a criação do velha.ini com 1 jogador,Computador e 
    as vitórias,empates e derrotas com 0*/
    
    FILE *arquivo = fopen("velha.ini","w");

    fprintf(arquivo,"1\n");
    fprintf(arquivo,"Computador\n");
    fprintf(arquivo,"0 0 0\n");

    fclose(arquivo);

    return 0;
}
