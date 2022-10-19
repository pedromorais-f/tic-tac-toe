#ifndef _FUNCAUX_H
#define _FUNCAUX_H


//leitura de dados
void nomejogadores(char[6],char[20],int);
void teclamenu();
void comandos(char[30],char*,char[6]);

//validações
int posicaomarcada(char**,int,int);

//impressão de resultados
void ganhou(char*);
void empate();

//remoção do \n
void remocao_salto(char*);

//visualização de vitória,derrota ou empate
int checagem();

//titulo
void titulo();

#endif