#ifndef _FUNCOES_H
#define _FUNCOES_H


//ESTRUTURA DO RANKING
typedef struct{

    char nome[100];
    int vitoria;
    int derrota;                         
    int empate;

}Usuario;

//FUNÇOES PRINCIPAIS PARA O FUNCIONAMENTO DO JOGO

//Jogo
void umplayer(char **,char*,char*,int,int,Usuario*,int*);
void doisplayers(char **,char*,char*,int,int,Usuario*,int*);

//Tabuleiro
void tabuleiro();

//Salvamento e carregamento de dados do jogo
void escreveJogo(char **,char *,char,int,int,int,char *,char*);
int lerJogo(char **,char *,char *,char[20],char,int,int);

#endif
