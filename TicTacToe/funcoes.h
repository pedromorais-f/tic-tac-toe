#ifndef _FUNCOES_H
#define _FUNCOES_H


//RANKING STRUCTURE
typedef struct{

    char nome[100];
    int vitoria;
    int derrota;                         
    int empate;

}Usuario;

//MAIN FUNCTIONS OF THE GAME

//Jogo
void umplayer(char **,char*,char*,int,int,Usuario*,int*);
void doisplayers(char **,char*,char*,int,int,Usuario*,int*);

//BOARD
void tabuleiro();

//SAVE AND LOAD GAME FUNCTIONS
void escreveJogo(char **,char *,char,int,int,int,char *,char*);
int lerJogo(char **,char *,char *,char[100],char,int,int);
int lerJogoEmAndamento(char **,char *,char *,char[20],char,int,int);

#endif
