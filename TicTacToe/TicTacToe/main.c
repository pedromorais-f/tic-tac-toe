#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "cores.h"
#include "funcoes.h"
#include "funcaux.h"
#include "ranking.h"


//The principal locate of the code
int main(){
    
    //Tic Tac Toe matrix
    char **jogovelha;
    
    //Menu options
    char opcao;
    char opcaojg;
    
    char jogador1[20];
    char jogador2[20];
    char nomearq[100];
    char jogoarq[] = "jogoEmAndamento.txt";
    
    //Game counters
    int contadorjogadas;
    int jogadas;
    //Menu Counters
    int controladormenu = 0;
    int controlatudo = 1;
    
    //Use a array to put the informations of the players and read the file
    Usuario *usuarios = alocaVetor(100);
    
    FILE *ranking = fopen("velha.ini","r");
    int tam;

    fscanf(ranking,"%d ",&tam);

    for(int i = 0;i < tam;i++){

        fgets(usuarios[i].nome,100,ranking);
        usuarios[i].nome[strlen(usuarios[i].nome) - 1] = '\0';
        fscanf(ranking,"%d %d %d ",&usuarios[i].vitoria,&usuarios[i].empate,&usuarios[i].derrota);
    }    
    
    //MAIN MENU
    while(controlatudo){
        
        jogovelha = criaMatriz(3,3);
        contadorjogadas = 0;
        jogadas = 1;
        
        while(controladormenu == 0){

            
            titulo();
        
            printf(BOLD(CYAN("(0) SAIR DO JOGO\n")));
            printf(BOLD(CYAN("(1) COMEÇAR NOVO JOGO\n")));
            printf(BOLD(CYAN("(2) CONTINUAR JOGO SALVO\n")));
            printf(BOLD(CYAN("(3) VOLTAR PARA JOGO EM ANDAMENTO\n")));
            printf(BOLD(CYAN("(4) EXIBIR RANKING\n")));
            printf(BOLD(CYAN("Durante o jogo digite 'voltar' para retornar ao menu")));
            
            printf(BOLD(CYAN("\n\nESCOLHA A OPÇÃO:")));
            scanf("%c",&opcao);
            getchar();
            
            if(opcao == '0'){

                escreveNovoRanking(usuarios,tam);
                fclose(ranking);
                liberaVetor(usuarios);
                return 0;
            }
            else if(opcao == '1'){

                printf(BOLD(CYAN("\nDigite o número de jogadores(1 ou 2):")));
                scanf("%c",&opcaojg);
                getchar();
                
                //Some validations for the options of the game
                while(((opcaojg != '2') && (opcaojg != '1'))){

                    printf(BOLD(RED("\nAVISO,QUANTIDADE INVÁLIDA\n")));
                    printf(BOLD(CYAN("\nDigite o número de jogadores(1 ou 2):")));
                    scanf("%c",&opcaojg);
                    getchar();
                }
                
                //Reading players name
                if(opcaojg == '1'){

                    nomejogadores("\x1b[32m",jogador1,1);
                    controladormenu = 1;
                }
                else if(opcaojg == '2'){

                    nomejogadores("\x1b[32m",jogador1,1);
                    nomejogadores("\x1b[31m",jogador2,2);
                    controladormenu = 1;
                }
            }
            else if(opcao == '2'){
            
                printf(BOLD(CYAN("Digite o nome do arquivo salvo:")));
                fgets(nomearq,100,stdin);
                nomearq[strlen(nomearq) - 1] = '\0';
            
            
                //Checking if the file exists or not
                if(lerJogo(jogovelha,jogador1,jogador2,nomearq,opcaojg,3,3) == -1){

                    printf(BOLD(RED("ARQUIVO NÃO ENCONTRADO!!!\n")));
                    controladormenu = 0;
                }   
                else{
                    
                    FILE *arquivo = fopen(nomearq,"r");
                    fscanf(arquivo,"%c ",&opcaojg);
                    
                    for(int k = 0;k < 3;k++){
                    
                        for(int m = 0;m < 3;m++){

                            if(jogovelha[k][m] != ' '){

                                contadorjogadas += 1;
                                jogadas += 1;
                            }
                        }
                    }
                    fclose(arquivo);
                    controladormenu = 1;   
                }
            }
            else if(opcao == '3'){

                if(lerJogoEmAndamento(jogovelha,jogador1,jogador2,jogoarq,opcaojg,3,3) == -1){

                        printf(BOLD(RED("ARQUIVO NÃO ENCONTRADO!!!\n")));
                        controladormenu = 0;
                }   
                else{
                    
                    FILE *arquivo = fopen(jogoarq,"r");
                    fscanf(arquivo,"%c ",&opcaojg);
                    
                    for(int k = 0;k < 3;k++){

                        for(int m = 0;m < 3;m++){

                            if(jogovelha[k][m] != ' '){

                                contadorjogadas += 1;
                                jogadas += 1;
                            }
                        }
                    }
                    fclose(arquivo);
                    controladormenu = 1;   
                }
            }
            else if(opcao == '4'){

                //Ranking exhibition
                imprimeRanking(usuarios,10);
            }
            else{
                
                while(((opcao < 0) || (opcao > 4))){

                    printf(BOLD(RED("OPÇÃO INVÁLIDA!!!\n")));
                    controladormenu = 0;
                    break;
                }
            }    
        }
        
        if(opcaojg == '1'){
            
            //Start the game against the machine
            umplayer(jogovelha,jogador1,"Computador",contadorjogadas,jogadas,usuarios,&tam);
            liberaMatriz(jogovelha,3);
            controladormenu = 0;    
        }
        else if(opcaojg == '2'){

            //Start the game player vs player
            doisplayers(jogovelha,jogador1,jogador2,contadorjogadas,jogadas,usuarios,&tam);
            liberaMatriz(jogovelha,3);
            controladormenu = 0;
        } 
    }

    return 0;
}


