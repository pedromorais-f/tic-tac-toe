#ifndef _RANKING_H
#define _RANKING_H



//Ranking
void atualizaEstatisticas(Usuario *,Usuario,Usuario,int*);
void imprimeRanking(Usuario *,int);

//Funções de auxílio para o Ranking
Usuario* alocaVetor(int);
void liberaVetor(Usuario *);
void escreveNovoRanking(Usuario*,int);
void ordenaVetor(Usuario*,int);
int checaJogadores(Usuario *,int,Usuario);
int posicaoRanking(Usuario *,char *);


#endif
