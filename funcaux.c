#include "funcoes.h"
#include "cores.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include "funcaux.h"
#include "ranking.h"

//AUXILIARY FUNCTIONS OF THE GAME


//Game Title
void titulo(){

    //Printing game title
    printf(BOLD(CYAN("     ██╗ ██████╗  ██████╗  ██████╗ \n")));
    printf(BOLD(CYAN("     ██║██╔═══██╗██╔════╝ ██╔═══██╗\n")));
    printf(BOLD(BLUE("     ██║██║   ██║██║  ███╗██║   ██║\n")));
    printf(BOLD(BLUE("██   ██║██║   ██║██║   ██║██║   ██║\n")));
    printf(BOLD(BLUE("╚█████╔╝╚██████╔╝╚██████╔╝╚██████╔╝\n")));
    printf(BOLD(BLUE(" ╚════╝  ╚═════╝  ╚═════╝  ╚═════╝ \n")));
    printf(BOLD(BLUE("██████╗  █████╗ \n")));
    printf(BOLD(CYAN("██╔══██╗██╔══██╗\n")));
    printf(BOLD(BLUE("██║  ██║███████║\n")));
    printf(BOLD(BLUE("██║  ██║██╔══██║\n")));
    printf(BOLD(BLUE("██████╔╝██║  ██║\n")));
    printf(BOLD(BLUE("╚═════╝ ╚═╝  ╚═╝\n")));
    printf(BOLD(CYAN("██╗   ██╗███████╗██╗     ██╗  ██╗ █████╗ \n")));
    printf(BOLD(BLUE("██║   ██║██╔════╝██║     ██║  ██║██╔══██╗\n")));
    printf(BOLD(BLUE("██║   ██║█████╗  ██║     ███████║███████║\n")));
    printf(BOLD(CYAN("╚██╗ ██╔╝██╔══╝  ██║     ██╔══██║██╔══██║\n")));
    printf(BOLD(CYAN(" ╚████╔╝ ███████╗███████╗██║  ██║██║  ██║\n")));
    printf("\n\n");    
}

//Checking the ṕossibilities of victory,draw or defeat
int checagem(char **jogovelha){

    //HORIZONTAL "X"
    if((jogovelha[0][0] == 'X') && (jogovelha[0][1] == 'X') && (jogovelha[0][2] == 'X')){

        return 1;
    }
    else if((jogovelha[1][0] == 'X') && (jogovelha[1][1] == 'X') && (jogovelha[1][2] == 'X')){

        return 1;
    }
    else if((jogovelha[2][0] == 'X') && (jogovelha[2][1] == 'X') && (jogovelha[2][2] == 'X')){

        return 1;
    }

    //VERTICAL "X"
    if((jogovelha[0][0] == 'X') && (jogovelha[1][0] == 'X') && (jogovelha[2][0] == 'X')){

        return 1;
    }
    else if((jogovelha[0][1] == 'X') && (jogovelha[1][1] == 'X') && (jogovelha[2][1] == 'X')){

        return 1;
    }
    if((jogovelha[0][2] == 'X') && (jogovelha[1][2] == 'X') && (jogovelha[2][2] == 'X')){

        return 1;
    }

    //DIAGONAL "X"
    if((jogovelha[0][0] == 'X') && (jogovelha[1][1] == 'X') && (jogovelha[2][2] == 'X')){

        return 1;
    }
    else if((jogovelha[0][2] == 'X') && (jogovelha[1][1] == 'X') && (jogovelha[2][0] == 'X')){

        return 1;
    }



    //HORIZONTAL "O"
    if((jogovelha[0][0] == 'O') && (jogovelha[0][1] == 'O') && (jogovelha[0][2] == 'O')){

        return 2;
    }
    else if((jogovelha[1][0] == 'O') && (jogovelha[1][1] == 'O') && (jogovelha[1][2] == 'O')){

        return 2;
    }
    else if((jogovelha[2][0] == 'O') && (jogovelha[2][1] == 'O') && (jogovelha[2][2] == 'O')){

        return 2;
    }

    //VERTICAL "O"
    if((jogovelha[0][0] == 'O') && (jogovelha[1][0] == 'O') && (jogovelha[2][0] == 'O')){

        return 2;
    }
    else if((jogovelha[0][1] == 'O') && (jogovelha[1][1] == 'O') && (jogovelha[2][1] == 'O')){

        return 2;
    }
    if((jogovelha[0][2] == 'O') && (jogovelha[1][2] == 'O') && (jogovelha[2][2] == 'O')){

        return 2;
    }

    //DIAGONAL "O"
    if((jogovelha[0][0] == 'O') && (jogovelha[1][1] == 'O') && (jogovelha[2][2] == 'O')){

        return 2;
    }
    else if((jogovelha[0][2] == 'O') && (jogovelha[1][1] == 'O') && (jogovelha[2][0] == 'O')){

        return 2;
    }

    return 0;
}

//Removing \n
void remocao_salto(char *nome){

    int tamanho = strlen(nome);

    for(int i = 0;i < tamanho;i++){

        if(nome[i] == '\n'){

            nome[i] = '\0';
        }
    }
}

//Printing the results
void ganhou(char *jogador){


    printf(BOLD(GREEN("██    ██  ██████   ██████ ███████      ██████   █████  ███    ██ ██   ██  ██████  ██    ██ \n")));
    printf(BOLD(GREEN("██    ██ ██    ██ ██      ██          ██       ██   ██ ████   ██ ██   ██ ██    ██ ██    ██ \n")));
    printf(BOLD(GREEN("██    ██ ██    ██ ██      █████       ██   ███ ███████ ██ ██  ██ ███████ ██    ██ ██    ██ \n")));
    printf(BOLD(GREEN(" ██  ██  ██    ██ ██      ██          ██    ██ ██   ██ ██  ██ ██ ██   ██ ██    ██ ██    ██ \n")));
    printf(BOLD(GREEN("  ████    ██████   ██████ ███████      ██████  ██   ██ ██   ████ ██   ██  ██████   ██████  \n")));
            
    printf("\n 🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉\n ");
    printf("\nParabéns %s!\n",jogador);
    printf(BOLD("Digite qualquer tecla para continuar!\n"));

}

void empate(){

    printf(BOLD(YELLOW("██    ██ ███████ ██      ██   ██  █████  \n")));
    printf(BOLD(YELLOW("██    ██ ██      ██      ██   ██ ██   ██ \n")));
    printf(BOLD(YELLOW("██    ██ █████   ██      ███████ ███████ \n")));
    printf(BOLD(YELLOW(" ██  ██  ██      ██      ██   ██ ██   ██ \n")));
    printf(BOLD(YELLOW("  ████   ███████ ███████ ██   ██ ██   ██ \n")));
    printf("\n😕😕😕😕😕😕😕😕😕\n");
    
    printf(BOLD(CYAN("Digite qualquer tecla para continuar!\n")));
}

void perdeu(){

    printf(BOLD(RED("██    ██  ██████   ██████ ███████     ██████  ███████ ██████  ██████  ███████ ██    ██ \n")));
    printf(BOLD(RED("██    ██ ██    ██ ██      ██          ██   ██ ██      ██   ██ ██   ██ ██      ██    ██ \n")));
    printf(BOLD(RED("██    ██ ██    ██ ██      █████       ██████  █████   ██████  ██   ██ █████   ██    ██ \n")));
    printf(BOLD(RED(" ██  ██  ██    ██ ██      ██          ██      ██      ██   ██ ██   ██ ██      ██    ██ \n")));
    printf(BOLD(RED("  ████    ██████   ██████ ███████     ██      ███████ ██   ██ ██████  ███████  ██████  \n")));
    printf("\n😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭😭\n");

    printf(BOLD(CYAN("Digite qualquer tecla para continuar!\n")));  
}

//Reading informations
void nomejogadores(char cor[6],char jogador[20],int n){

    char verificacao[20];
    //Validating if the player choose the name "Computador"
    do{
        printf("\x1b[1m%sDigite o nome do Jogador %d:",cor,n);
        fgets(jogador,20,stdin);
        remocao_salto(jogador);

        strcpy(verificacao,jogador);
        for(int i = 0;i < strlen(verificacao);i++){

            verificacao[i] = toupper(verificacao[i]);
        }

        if(strcmp(verificacao,"COMPUTADOR") == 0){

            printf(BOLD(RED("NOME INVÁLIDO\n")));
        }

    }while(strcmp(verificacao,"COMPUTADOR") == 0);

}

//Key to return to the main menu
void teclamenu(){

    char tecla;

    scanf("%c",&tecla);
    getchar();
}

void comandos(char comando[30],char *jogador,char cor[6]){

    //Reading the commands of the game
    printf("\x1b[0m%s\n%s,digite o comando:",cor,jogador);
    fgets(comando,30,stdin);
    remocao_salto(comando);
    
}

//Board
char** criaMatriz(int linha, int coluna){

    //Creating the board and inicializing him with empty spaces
    char **matriz;

    matriz = malloc(linha * sizeof(char*));
    for(int j = 0;j < linha;j++){

        matriz[j] = malloc(coluna * sizeof(char));
    }

    //Inicialize the matrix
    for(int i = 0;i < linha;i++){

        for(int j = 0;j < coluna;j++){

            matriz[i][j] = ' ';
        }
    }

        return matriz;

}

//Free the matrix
void liberaMatriz(char** matriz, int linha){

    for(int q = 0;q < linha;q++){

        free(matriz[q]);
    }
    free(matriz);
}

//Computer intelligence
void inteligenciaComp(char **jogovelha){

    int linha_comp;
    int coluna_comp;

    //Computer win horizontal
    if(jogovelha[0][0] == 'O' && jogovelha[0][1] == 'O' && jogovelha[0][2] == ' '){

        jogovelha[0][2] = 'O';
    }
    else if(jogovelha[1][0] == 'O' && jogovelha[1][1] == 'O' && jogovelha[1][2] == ' '){

        jogovelha[1][2] = 'O';
    }
    else if(jogovelha[2][0] == 'O' && jogovelha[2][1] == 'O' && jogovelha[2][2] == ' '){

        jogovelha[2][2] = 'O';
    }
    else if(jogovelha[2][2] == 'O' && jogovelha[2][1] == 'O' && jogovelha[2][0] == ' '){

        jogovelha[0][0] = 'O';
    }
    else if(jogovelha[1][0] == ' ' && jogovelha[1][1] == 'O' && jogovelha[1][2] == 'O'){

        jogovelha[1][0] = 'O';
    }
    else if(jogovelha[0][2] == 'O' && jogovelha[0][1] == 'O' && jogovelha[0][0] == ' '){

        jogovelha[0][0] = 'O';
    }
    
    //Computer win vertical
    else if(jogovelha[0][0] == 'O' && jogovelha[1][0] == 'O' && jogovelha[2][0] == ' '){

        jogovelha[2][0] = 'O';
    }
    else if(jogovelha[0][1] == 'O' && jogovelha[1][1] == 'O' && jogovelha[2][1] == ' '){

        jogovelha[2][1] = 'O';
    }
    else if(jogovelha[0][2] == 'O' && jogovelha[1][2] == 'O' && jogovelha[2][2] == ' '){

        jogovelha[2][2] = 'O';
    }
    else if(jogovelha[2][1] == 'O' && jogovelha[1][1] == 'O' && jogovelha[0][1] == ' '){

        jogovelha[0][1] = 'O';
    }
    else if(jogovelha[0][0] == ' ' && jogovelha[1][0] == 'O' && jogovelha[2][0] == 'O'){

        jogovelha[0][0] = 'O';
    }
    else if(jogovelha[2][2] == 'O' && jogovelha[1][2] == 'O' && jogovelha[0][2] == ' '){

        jogovelha[0][2] = 'O';
    }

     
    //vitoria diagonais
    else if(jogovelha[0][0] == 'O' && jogovelha[1][1] == 'O' && jogovelha[2][2] == ' '){

        jogovelha[2][2] = 'O';
    }
    else if(jogovelha[0][2] == 'O' && jogovelha[1][1] == 'O' && jogovelha[2][0] == ' '){

        jogovelha[2][0] = 'O';
    }
    else if(jogovelha[2][0] == 'O' && jogovelha[1][1] == 'O' && jogovelha[0][2] == ' '){

        jogovelha[0][2] = 'O';
    }
    else if(jogovelha[2][2] == 'O' && jogovelha[1][1] == 'O' && jogovelha[0][0] == ' '){

        jogovelha[0][0] = 'O';
    }

    //vitoria meio
    else if(jogovelha[0][0] == 'O' && jogovelha[1][1] == ' ' && jogovelha[2][2] == 'O'){

        jogovelha[1][1] = 'O';
    }
    else if(jogovelha[0][2] == 'O' && jogovelha[1][1] == ' ' && jogovelha[2][1] == 'O'){

        jogovelha[1][1] = 'O';
    }
    else if(jogovelha[0][1] == 'O' && jogovelha[1][1] == ' ' && jogovelha[2][1] == 'O'){

        jogovelha[1][1] = 'O';
    }
    else if(jogovelha[1][0] == 'O' && jogovelha[1][1] == ' ' && jogovelha[1][2] == 'O'){

        jogovelha[1][1] = 'O';
    }


    //vitória nos cantos meio
    else if(jogovelha[0][0] == 'O' && jogovelha[0][1] == ' ' && jogovelha[0][2] == 'O'){

        jogovelha[0][1] = 'O';
    }
    else if(jogovelha[2][0] == 'O' && jogovelha[2][1] == ' ' && jogovelha[2][2] == 'O'){

        jogovelha[2][1] = 'O';
    }
    else if(jogovelha[0][2] == 'O' && jogovelha[2][2] == 'O' && jogovelha[1][2] == ' '){

        jogovelha[1][2] = 'O';
    }
    else if(jogovelha[0][0] == 'O' && jogovelha[1][0] == ' ' && jogovelha[2][0] == 'O'){

        jogovelha[1][0] = 'O';
    }
    
    //possibildades de vitória do Jogador 1 horizontal
    else if(jogovelha[0][0] == 'X' && jogovelha[0][1] == 'X' && jogovelha[0][2] == ' '){

        jogovelha[0][2] = 'O';
    }
    else if(jogovelha[1][0] == 'X' && jogovelha[1][1] == 'X' && jogovelha[1][2] == ' '){

        jogovelha[1][2] = 'O';
    }
    else if(jogovelha[2][0] == 'X' && jogovelha[2][1] == 'X' && jogovelha[2][2] == ' '){

        jogovelha[2][2] = 'O';
    }
    else if(jogovelha[2][2] == 'X' && jogovelha[2][1] == 'X' && jogovelha[2][0] == ' '){

        jogovelha[2][0] = 'O';
    }
    else if(jogovelha[1][0] == ' ' && jogovelha[1][1] == 'X' && jogovelha[1][2] == 'X'){

        jogovelha[1][0] = 'O';
    }
    else if(jogovelha[0][2] == 'X' && jogovelha[0][1] == 'X' && jogovelha[0][0] == ' '){

        jogovelha[0][0] = 'O';
    }

    //POssibilidades de vitória do Jogador 1 vertical
    else if(jogovelha[0][0] == 'X' && jogovelha[1][0] == 'X' && jogovelha[2][0] == ' '){

        jogovelha[2][0] = 'O';
    }
    else if(jogovelha[0][1] == 'X' && jogovelha[1][1] == 'X' && jogovelha[2][1] == ' '){

        jogovelha[2][1] = 'O';
    }
    else if(jogovelha[0][2] == 'X' && jogovelha[1][2] == 'X' && jogovelha[2][2] == ' '){

        jogovelha[2][2] = 'O';
    }
    else if(jogovelha[2][1] == 'X' && jogovelha[1][1] == 'X' && jogovelha[0][1] == ' '){

        jogovelha[0][1] = 'O';
    }
    else if(jogovelha[0][0] == ' ' && jogovelha[1][0] == 'X' && jogovelha[2][0] == 'X'){

        jogovelha[0][0] = 'O';
    }
    else if(jogovelha[2][2] == 'X' && jogovelha[1][2] == 'X' && jogovelha[0][2] == ' '){

        jogovelha[0][2] = 'O';
    }


    //Possibilidades do Jogador 1 diagonais
    else if(jogovelha[0][0] == 'X' && jogovelha[1][1] == 'X' && jogovelha[2][2] == ' '){

        jogovelha[2][2] = 'O';
    }
    else if(jogovelha[0][2] == 'X' && jogovelha[1][1] == 'X' && jogovelha[2][0] == ' '){

        jogovelha[2][0] = 'O';
    }
    else if(jogovelha[2][0] == 'X' && jogovelha[1][1] == 'X' && jogovelha[0][2] == ' '){

        jogovelha[0][2] = 'O';
    }
    else if(jogovelha[2][2] == 'X' && jogovelha[1][1] == 'X' && jogovelha[0][0] == ' '){

        jogovelha[0][0] = 'O';
    }
     
    
    //vitória do Jogador 1 no meio
    else if(jogovelha[0][0] == 'X' && jogovelha[1][1] == ' ' && jogovelha[2][2] == 'X'){

        jogovelha[1][1] = 'O';
    }
    else if(jogovelha[0][2] == 'X' && jogovelha[1][1] == ' ' && jogovelha[2][1] == 'X'){

        jogovelha[1][1] = 'O';
    }
    else if(jogovelha[0][1] == 'X' && jogovelha[1][1] == ' ' && jogovelha[2][1] == 'X'){

        jogovelha[1][1] = 'O';
    }
    else if(jogovelha[1][0] == 'X' && jogovelha[1][1] == ' ' && jogovelha[1][2] == 'X'){

        jogovelha[1][1] = 'O';
    }
    

    //vitória do Jogador 1 nos cantos meio
    else if(jogovelha[0][0] == 'X' && jogovelha[0][1] == ' ' && jogovelha[0][2] == 'X'){

        jogovelha[0][1] = 'O';
    }
    else if(jogovelha[2][0] == 'X' && jogovelha[2][1] == ' ' && jogovelha[2][2] == 'X'){

        jogovelha[2][1] = 'O';
    }
    else if(jogovelha[0][2] == 'X' && jogovelha[2][2] == 'X' && jogovelha[1][2] == ' '){

        jogovelha[1][2] = 'O';
    }
    else if(jogovelha[0][0] == 'X' && jogovelha[1][0] == ' ' && jogovelha[2][0] == 'X'){

        jogovelha[1][0] = 'O';
    }

    //jogadas iniciais da Máquina
    else if(jogovelha[0][0] == 'X' && jogovelha[0][1] == ' ' && jogovelha[0][2] == ' ' && jogovelha[1][0] == ' ' && jogovelha[1][1] == ' ' && jogovelha[1][2] == ' ' && jogovelha[2][0] == ' ' && jogovelha[2][1] == ' ' && jogovelha[2][2] == ' '){

        jogovelha[1][1] = 'O';
    }
    else if(jogovelha[0][0] == ' ' && jogovelha[0][1] == ' ' && jogovelha[0][2] == 'X' && jogovelha[1][0] == ' ' && jogovelha[1][1] == ' ' && jogovelha[1][2] == ' ' && jogovelha[2][0] == ' ' && jogovelha[2][1] == ' ' && jogovelha[2][2] == ' '){

        jogovelha[1][1] = 'O';
    }
    else if((jogovelha[0][0] == ' ' && jogovelha[0][1] == ' ' && jogovelha[0][2] == ' ' && jogovelha[1][0] == ' ' && jogovelha[1][1] == ' ' && jogovelha[1][2] == ' ' && jogovelha[2][0] == 'X' && jogovelha[2][1] == ' ' && jogovelha[2][2] == ' ')){

        jogovelha[1][1] = 'O';
    }
    else if((jogovelha[0][0] == ' ' && jogovelha[0][1] == ' ' && jogovelha[0][2] == ' ' && jogovelha[1][0] == ' ' && jogovelha[1][1] == ' ' && jogovelha[1][2] == ' ' && jogovelha[2][0] == ' ' && jogovelha[2][1] == ' ' && jogovelha[2][2] == 'X')){

        jogovelha[1][1] = 'O';
    }
    else if((jogovelha[0][0] == ' ' && jogovelha[0][1] == ' ' && jogovelha[0][2] == ' ' && jogovelha[1][0] == ' ' && jogovelha[1][1] == 'X' && jogovelha[1][2] == ' ' && jogovelha[2][0] == ' ' && jogovelha[2][1] == ' ' && jogovelha[2][2] == ' ')){

        jogovelha[0][0] = 'O';
    }
    
    //jogadas que não resultam em vitória ou derrota da máquina
    else{

        do{
            srand(time(NULL));
            linha_comp = rand() % 3;
            coluna_comp = rand() % 3;

        }while(jogovelha[linha_comp][coluna_comp] != ' ');

        jogovelha[linha_comp][coluna_comp] = 'O';
    }
}    

void screenClear(){

    for(int i = 0;i < 50;i++){

        printf("\n");
    }
}
