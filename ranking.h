#ifndef _RANKING_H
#define _RANKING_H

//RANKING
void atualizaEstatisticas(Usuario *,Usuario,Usuario,int*);
void imprimeRanking(Usuario *,int);

//RANKING FUNCTIONS
Usuario* alocaVetor(int);
void liberaVetor(Usuario *);
void escreveNovoRanking(Usuario*,int);
void ordenaVetor(Usuario*,int);
int checaJogadores(Usuario *,int,Usuario);
int posicaoRanking(Usuario *,char *);


#endif
