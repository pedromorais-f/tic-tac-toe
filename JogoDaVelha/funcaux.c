#include "funcoes.h"
#include "cores.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include "funcaux.h"

//titulo
void titulo(){

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

//visualização de vitória,derrota ou empate
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

//remocao do \n 
void remocao_salto(char *nome){

    int tamanho = strlen(nome);

    for(int i = 0;i < tamanho;i++){

        if(nome[i] == '\n'){

            nome[i] = '\0';
        }
    }
}

//Impressão de resultados
void ganhou(char *jogador){


    printf(BOLD(GREEN("██    ██ ██████  ██████ ██████     ██████  ██████ ██    █ ██   ██ ██████ ██    ██ █ █ \n")));
    printf(BOLD(GREEN("██    ██ █    █  █    █ █         ██       █   ██ ███   █ ██   ██ █    █ ██    ██ █ █  \n")));
    printf(BOLD(GREEN("██    ██ █    █  █      ████      ██   ██  ██████ █ ██  █ ███████ █    █ ██    ██ █ █  \n")));
    printf(BOLD(GREEN("██    ██ █    █  █    █ █         ██    █  █   ██ █  ██ █ ██   ██ █    █ ██    ██      \n")));
    printf(BOLD(GREEN("  ████   ██████  ██████ ██████     ██████  █   ██ █   ███ ██   ██ ██████ ████████ █ █  \n")));
            
    printf("\n 🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉\n ");
    printf("\nParabéns %s!\n",jogador);
    printf(BOLD("Digite qualquer tecla para continuar!\n"));

}
void empate(){

    printf(BOLD(YELLOW("█████ ██      ██ ██████ ██████ ████  ███████ \n")));
    printf(BOLD(YELLOW("██    ████  ████ █   ██ █   ██  ██   ██      \n")));
    printf(BOLD(YELLOW("█████ ██ ████ ██ ██████ ██████  ██   █████   \n")));
    printf(BOLD(YELLOW("██    ██  ██  ██ █      █   ██  ██   ██      \n")));
    printf(BOLD(YELLOW("█████ ██      ██ █      █   ██  ██   ███████ \n")));
    
    printf(BOLD(CYAN("Digite qualquer tecla para continuar!\n")));
}

//leitura de dados
void nomejogadores(char cor[6],char jogador[20],int n){

    char verificacao[20];
    
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
void teclamenu(){

    char tecla;

    scanf("%c",&tecla);
    getchar();
}
void comandos(char comando[30],char *jogador,char cor[6]){

    printf("\x1b[0m%s\n%s,digite o comando:",cor,jogador);
    fgets(comando,30,stdin);
    remocao_salto(comando);
    
}


