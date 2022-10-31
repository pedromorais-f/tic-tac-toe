#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "cores.h"
#include "funcoes.h"
#include "funcaux.h"
#include "ranking.h"

//Auxiliary functions for the ranking
Usuario* alocaVetor(int tam){

    //Creating the array and return him
    Usuario *usuarios;

    usuarios = malloc(tam * sizeof(Usuario));

    return usuarios;
}

void liberaVetor(Usuario *jogadores){

    //Free the array
    free(jogadores);
}

void ordenaVetor(Usuario *vetor,int n){
    
    /*Organize the array,looking for the player with the highest number of victories,if this number be equal between
    two players,the number of draws will be considered*/
    Usuario aux;                                                                 

    int maiorAtual;                                                             

    for(int i = 0; i < n; i++){                                                                       
        //Verifying who have the highest number of victories
        maiorAtual = i;                                                         

        for (int j = i + 1; j < n;j++) {                                       

            if (vetor[j].vitoria > vetor[maiorAtual].vitoria){                        

                maiorAtual = j;
            }
            else if((vetor[j].vitoria == vetor[maiorAtual].vitoria)){

                if(vetor[j].empate > vetor[maiorAtual].empate){

                    maiorAtual = j;
                }
            }                                                
        }                                                                       
        //Changing the positions
        if(maiorAtual != i) {                                                   

            aux = vetor[i];                                                     

            vetor[i] = vetor[maiorAtual];                                       

            vetor[maiorAtual] = aux;                                            

        }

    }

}

void escreveNovoRanking(Usuario *jogadores,int tam){

    //Updating the ranking
    FILE *arquivo = fopen("velha.ini","w");
    
    
    fprintf(arquivo,"%d\n",tam);

    for(int i = 0;i < tam;i++){

        fprintf(arquivo,"%s\n",jogadores[i].nome);
        fprintf(arquivo,"%d %d %d\n",jogadores[i].vitoria,jogadores[i].empate,jogadores[i].derrota);
    }
}

int checaJogadores(Usuario *jogadores,int tam,Usuario jogador){

    /*This function makes a search if the player already exists in the ranking,if the player
    exist,the function will return the position of him,if the player do not exist,will return -1*/ 
    for(int i = 0;i < tam;i++){

        if(strcmp(jogador.nome,jogadores[i].nome) == 0){

            
            return i;

        }
    }

    return -1;
}

int posicaoRanking(Usuario *jogadores,char *jogador){

    /*This function makes a search in the array and return the position of the player*/
    for(int i = 0;i < 10;i++){

        if(strcmp(jogadores[i].nome,jogador) == 0){

            return i + 1;
        }
    }

    return -1;
}

//Main Functions 
void atualizaEstatisticas(Usuario *jogadores,Usuario jgdr1,Usuario jgdr2,int *tam){

    int posicao1 = checaJogadores(jogadores,*tam,jgdr1);
    int posicao2 = checaJogadores(jogadores,*tam,jgdr2);

    /*Update the stats of each player in the match,even that they exists or not*/
    if(posicao1 == -1){

        strcpy(jogadores[*tam].nome,jgdr1.nome);
        jogadores[*tam].vitoria = jgdr1.vitoria;
        jogadores[*tam].empate = jgdr1.empate;
        jogadores[*tam].derrota = jgdr1.derrota;
        
        *tam = *tam + 1;
    }
    else{
        //If the function returns -1,she will only add +1 in the stats
        strcpy(jogadores[posicao1].nome,jgdr1.nome);
        jogadores[posicao1].vitoria += jgdr1.vitoria;
        jogadores[posicao1].empate += jgdr1.empate;
        jogadores[posicao1].derrota += jgdr1.derrota;
    }
    if(posicao2 == -1){

        strcpy(jogadores[*tam].nome,jgdr2.nome);
        jogadores[*tam].vitoria = jgdr2.vitoria;
        jogadores[*tam].empate = jgdr2.empate;
        jogadores[*tam].derrota = jgdr2.derrota;

        *tam = *tam + 1;
    }
    else{

        strcpy(jogadores[posicao2].nome,jgdr2.nome);
        jogadores[posicao2].vitoria += jgdr2.vitoria;
        jogadores[posicao2].empate += jgdr2.empate;
        jogadores[posicao2].derrota += jgdr2.derrota;
    }
    
    
    //Organize the array
    ordenaVetor(jogadores,*tam);
    
}

void imprimeRanking(Usuario *jogadores,int tam){

    //Ranking controller
    int controlador = 1;
    
    //Print the rank with the informations of the players like,name,position and the stats
    while(controlador){
        
        printf(BOLD(CYAN("\n\n\nRANKING\n")));

        printf(BOLD(CYAN("Ordem: Posição - Nome - Vitória - Empate - Derrota\n\n")));

        for(int i = 0;i < tam;i++){

            printf("\x1b[37m\x1b[1m\u2503 %d.%s  %d  %d  %d \n",i + 1,jogadores[i].nome,jogadores[i].vitoria,jogadores[i].empate,jogadores[i].derrota);
            for(int j = 0;j < 70;j++){

                printf("\u2501");
            }
            printf("\n");
        }

        printf(BOLD(CYAN("\n\nPressione qualquer tecla para voltar!\n")));
        teclamenu();
        break;
    }
}
