#ifndef _FUNCOES_H
#define _FUNCOES_H

//ESTRUTURA
typedef struct{

    char nome[100];
    int vitoria;
    int derrota;                         
    int empate;

}Usuário;

//Ranking
//void ranking
//void ordenar
//void ler

//Jogo
void umplayer(char **,char*,char*,int,int);
void doisplayers(char **,char*,char*,int,int);

//tabuleiro
void tabuleiro();
void liberaMatriz(char** matriz, int linha);
char** criaMatriz(int m, int n);

//inteligencia computador
void inteligenciacomp(char**);

//salvamento e carregamento de dados do jogo
void escrevejogo(char **,char *,char,int,int,int,char *,char*);
int lerJogo(char **,char *,char *,char[20],char,int,int);

#endif