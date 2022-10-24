#ifndef _FUNCAUX_H
#define _FUNCAUX_H

//FUNÇÕES AUXILIARES DO JOGO

//Leitura de dados
void nomejogadores(char[6],char[20],int);
void teclamenu();
void comandos(char[30],char*,char[6]);

//Impressão de resultados
void ganhou(char*);
void empate();
void perdeu();

//Remoção do \n
void remocao_salto(char*);

//Visualização de vitória,derrota ou empate
int checagem();

//Titulo
void titulo();

//Tabuleiro
void liberaMatriz(char** matriz, int linha);
char** criaMatriz(int m, int n);

//inteligencia computador
void inteligenciaComp(char**);

#endif