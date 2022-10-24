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

//Funções de auxílio para o Ranking
int contaJogadores(Usuario *);
Usuario* alocaVetor(int);
void lerRanking(Usuario *);
void liberaVetor(Usuario *);
void escreveNovoRanking(Usuario*,int);
void ordenaVetor(Usuario*,int);
int checaJogadores(Usuario *,int,Usuario);
int posicaoRanking(Usuario *,char *);

#endif