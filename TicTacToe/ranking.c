#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "cores.h"
#include "funcoes.h"
#include "funcaux.h"
#include "ranking.h"

//Funções de auxílio para o Ranking
Usuario* alocaVetor(int tam){

    //Alocação do vetor de jogadores para o Ranking
    Usuario *usuarios;

    usuarios = malloc(tam * sizeof(Usuario));

    return usuarios;
}

void liberaVetor(Usuario *jogadores){

    //Liberação do vetor alocado
    free(jogadores);
}

void ordenaVetor(Usuario *vetor,int n){
    
    /*Ordenação dos vetores priorizando o número de vitórias 
    e o próximo critério,o empate.
    Verifica cada posição comparando e trocando a posição no vetor*/
    Usuario aux;                                                                 

    int maiorAtual;                                                             

    for(int i = 0; i < n; i++){                                                                       
        //Verificação de quem tem o maior número de vitórias
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
        //Troca de suas posições no vetor
        if(maiorAtual != i) {                                                   

            aux = vetor[i];                                                     

            vetor[i] = vetor[maiorAtual];                                       

            vetor[maiorAtual] = aux;                                            

        }

    }

}

void escreveNovoRanking(Usuario *jogadores,int tam){

    //Função de atualização do Ranking
    FILE *arquivo = fopen("velha.ini","w");
    
    
    fprintf(arquivo,"%d\n",tam);

    for(int i = 0;i < tam;i++){

        fprintf(arquivo,"%s\n",jogadores[i].nome);
        fprintf(arquivo,"%d %d %d\n",jogadores[i].vitoria,jogadores[i].empate,jogadores[i].derrota);
    }
}

int checaJogadores(Usuario *jogadores,int tam,Usuario jogador){

    /*Procura a posição no Ranking,onde está o player e retorna sua posição
    ou retorna -1,significando que o player é novo*/ 
    for(int i = 0;i < tam;i++){

        if(strcmp(jogador.nome,jogadores[i].nome) == 0){

            
            return i;

        }
    }

    return -1;
}

int posicaoRanking(Usuario *jogadores,char *jogador){

    /*Procura a posição do player nos 10 primeiros jogadores do vetor
    e retorna sua posição ou -1,mostrando que não está posicionado no ranking*/
    for(int i = 0;i < 10;i++){

        if(strcmp(jogadores[i].nome,jogador) == 0){

            return i + 1;
        }
    }

    return -1;
}

//Ranking e suas funções 
void atualizaEstatisticas(Usuario *jogadores,Usuario jgdr1,Usuario jgdr2,int *tam){

    int posicao1 = checaJogadores(jogadores,*tam,jgdr1);
    int posicao2 = checaJogadores(jogadores,*tam,jgdr2);

    //Incrementação e criação de novos usuários no Ranking
    //Se a função retornar -1,um novo jogador vai ser criado
    if(posicao1 == -1){

        strcpy(jogadores[*tam].nome,jgdr1.nome);
        jogadores[*tam].vitoria = jgdr1.vitoria;
        jogadores[*tam].empate = jgdr1.empate;
        jogadores[*tam].derrota = jgdr1.derrota;
        
        *tam = *tam + 1;
    }
    else{
        //Se retornar diferente de -1,vai colocar na posição somente o incremento
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
    
    
    //ordenação do vetor do Ranking
    ordenaVetor(jogadores,*tam);
    
}

void imprimeRanking(Usuario *jogadores,int tam){

    //Controlador do Ranking
    int controlador = 1;
    
    //Impressão do Ranking com as informações dos jogadores
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
