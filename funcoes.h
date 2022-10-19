#ifndef _FUNCOES_H
#define _FUNCOES_H

//ESTRUTURAS
/*typedef struct{

    char nome[100];
    int vitoria = 0;
    int derrota = 0;
    int empate = 0;
}Usuário;*/

//Ranking
//Ranking ranking();

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
void escrevejogo(char **,char *,int,int,int,int,char *,char*);
void lerJogo(char **,char *,char *,char[20],int,int,int);

#endif