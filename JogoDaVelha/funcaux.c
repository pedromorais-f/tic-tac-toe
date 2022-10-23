#include "funcoes.h"
#include "cores.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include "funcaux.h"

//FUNÇÕES AUXILIARES DO JOGO


//Titulo
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

//Visualização de vitória,derrota ou empate dos players
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

//Remocao do \n em strings
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

//Leitura de dados
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

//Tabuleiro
char** criaMatriz(int linha, int coluna){

    char **matriz;

    matriz = malloc(linha * sizeof(char*));
    for(int j = 0;j < linha;j++){

        matriz[j] = malloc(coluna * sizeof(char));
    }

    //inicializa a matriz com espaços vazios
    for(int i = 0;i < linha;i++){

        for(int j = 0;j < coluna;j++){

            matriz[i][j] = ' ';
        }
    }

        return matriz;

}
void liberaMatriz(char** matriz, int linha){

    for(int q = 0;q < linha;q++){

        free(matriz[q]);
    }
    free(matriz);
}

//Inteligencia do computador
void inteligenciaComp(char **jogovelha){

    int linha_comp;
    int coluna_comp;

    //vitória computador horizontal
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
    
    //vitória computador vertical
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
    
    //possibildades de vitória horizontal
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

    //POssibilidades de vitória vertical
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


    //Possibilidades diagonais
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
     
    
    //vitória no meio
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
    

    //vitória nos cantos meio
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

    //jogadas iniciais
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
    
    //jogadas sem efeito
    else{

        do{
            srand(time(NULL));
            linha_comp = rand() % 3;
            coluna_comp = rand() % 3;

        }while(jogovelha[linha_comp][coluna_comp] != ' ');

        jogovelha[linha_comp][coluna_comp] = 'O';
    }
}    

//Funções de auxílio para o Ranking
/*int contaJogadores(Usuario *jogador){

    FILE *arquivo = fopen("velha.ini","r");

    int contajogadores = 0;
    
    
    while(!feof(arquivo)){

        fscanf(arquivo,"%s ",jogador[contajogadores].nome);
        fscanf(arquivo,"%d %d %d",&jogador[contajogadores + 1].vitoria,&jogador[contajogadores + 1].empate,&jogador[contajogadores + 1].derrota);
        contajogadores = contajogadores + 2;
    }

    fclose(arquivo);
    
    return contajogadores;
}*/
Usuario* alocaVetor(int tam){

    Usuario *usuarios;

    usuarios = malloc(tam * sizeof(Usuario));

    return usuarios;
}
void liberaVetor(Usuario *jogadores){

    free(jogadores);
}
void lerRanking(Usuario *jogadores){

    FILE *ranking = fopen("velha.ini","r");
    int tam;

    fscanf(ranking,"%d",&tam);

    for(int i = 0;i < tam;i++){

        fgets(jogadores[i].nome,100,ranking);
        jogadores[i].nome[strlen(jogadores[i].nome) - 1] = '\0';
        fscanf(ranking,"%d %d %d",&jogadores[i].vitoria,&jogadores[i].empate,&jogadores[i].derrota);

    }    
}
void ordenaVetor(Usuario *vetor,int n){
    
    Usuario aux;                                                                 

    int maiorAtual;                                                             

    for(int i = 0; i < n; i++){                                                                       

        maiorAtual = i;                                                         

        for (int j = i + 1; j < n;j++) {                                       

            if (vetor[j].vitoria > vetor[maiorAtual].vitoria){                        

                maiorAtual = j;
            }
            else if((vetor[j].vitoria = vetor[maiorAtual].vitoria)){

                if(vetor[j].empate > vetor[maiorAtual].empate){

                    maiorAtual = j;
                }
            }                                                
        }                                                                       

        if(maiorAtual != i) {                                                   

            aux = vetor[i];                                                     

            vetor[i] = vetor[maiorAtual];                                       

            vetor[maiorAtual] = aux;                                            

        }

    }

}
void escreveNovoRanking(Usuario *jogadores,int tam){

    FILE *arquivo = fopen("velha.ini","w");
    
    lerRanking(jogadores);
    
    fprintf(arquivo,"%d\n",tam);

    for(int i = 0;i < tam;i++){

        fprintf(arquivo,"%s\n",jogadores[i].nome);
        fprintf(arquivo,"%d %d %d\n",jogadores[i].vitoria,jogadores[i].empate,jogadores[i].derrota);
    }

    fclose(arquivo);
}
int checaJogadores(Usuario *jogadores,int tam,Usuario j1,Usuario j2){

    FILE *arquivo = fopen("velha.ini","r");
    int contador = 0;
    fscanf(arquivo,"%d",&tam);
    //printf("%d\n",tam);
    //printf("%s\n",j1.nome);
    //printf("%s\n",j2.nome);

    for(int i = 0;i < tam;i++){

        fgets(jogadores[i].nome,100,arquivo);
        jogadores[i].nome[strlen(jogadores[i].nome) - 1] = '\0';
        fscanf(arquivo,"%d %d %d",&jogadores[i].vitoria,&jogadores[i].empate,&jogadores[i].derrota);
        printf("%s",jogadores[0].nome);
        if(strcmp(j1.nome,jogadores[i].nome) == 0){

            //strcpy(jogadores[i].nome,j1.nome);
            jogadores[i].vitoria += j1.vitoria;
            jogadores[i].empate += j1.empate;
            jogadores[i].derrota += j1.derrota;
            printf("JA%d\n",i);
            contador = contador + 1;
        }
        if(strcmp(j2.nome,jogadores[i].nome) == 0){

            //strcpy(jogadores[i].nome,j2.nome);
            jogadores[i].vitoria += j2.vitoria;
            jogadores[i].empate += j2.empate;
            jogadores[i].derrota += j2.derrota;
            printf("JB%d\n",i);
            contador = contador + 2;
        }
    }
    printf("C%d\n",contador);
    return contador;
}
int posicaoRanking(Usuario *jogadores,char *jogador){

    lerRanking(jogadores);

    for(int i = 0;i < 10;i++){

        if(strcmp(jogadores[i].nome,jogador) == 0){

            return i + 1;
        }
        else{

            return -1;
        }
    }

    return 0;
}

