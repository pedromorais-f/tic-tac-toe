#ifndef _FUNCAUX_H
#define _FUNCAUX_H


//FUNÇÕES AUXILIARES DO JOGO

//READING INFORMATIONS
void nomejogadores(char[6],char[20],int);
void teclamenu();
void comandos(char[30],char*,char[6]);

//PRINTING THE RESULTS
void ganhou(char*);
void empate();
void perdeu();

//REMOVING \n
void remocao_salto(char*);

//CHECKING THE RESULTS OF THE MATCH
int checagem();

//GAME TITLE
void titulo();

//BOARD CREATION
void liberaMatriz(char** matriz, int linha);
char** criaMatriz(int m, int n);

//COMPUTER INTELLINGENCE
void inteligenciaComp(char**);

//CLEANING THE SCREEN
void screenClear();


#endif
