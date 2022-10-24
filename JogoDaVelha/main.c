#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "cores.h"
#include "funcoes.h"
#include "funcaux.h"

//função principal main
int main(){
    
    //Matriz do jogo da velha
    char **jogovelha;
    
    //Opções do menu e da escolha de 1 ou 2 jogadores
    char opcao;
    char opcaojg;
    
    char jogador1[20];
    char jogador2[20];
    char nomearq[20];
    
    //Contadores do jogo
    int contadorjogadas = 0;
    int jogadas = 1;
    //Controladores do jogo como um todo e do menu principal
    int controladormenu = 0;
    int controlatudo = 1;
    
    //Alocação e leitura do arquivo
    Usuario *usuarios = alocaVetor(100);
    
    FILE *ranking = fopen("velha.ini","r");
    int tam;

    fscanf(ranking,"%d ",&tam);

    for(int i = 0;i < tam;i++){

        fgets(usuarios[i].nome,100,ranking);
        usuarios[i].nome[strlen(usuarios[i].nome) - 1] = '\0';
        fscanf(ranking,"%d %d %d ",&usuarios[i].vitoria,&usuarios[i].empate,&usuarios[i].derrota);
    }    
    while(controlatudo){
        
        jogovelha = criaMatriz(3,3);
        
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
            
            switch(opcao){
                case '0':
                    escreveNovoRanking(usuarios,tam);
                    fclose(ranking);
                    liberaVetor(usuarios);
                    return 0;
                case '1':
                    printf(BOLD(CYAN("\nDigite o número de jogadores(1 ou 2):")));
                    scanf("%c",&opcaojg);
                    getchar();
                    //Validação das opções de jogabilidade
                    while(((opcaojg != '2') && (opcaojg != '1'))){

                        printf(BOLD(RED("\nAVISO,QUANTIDADE INVÁLIDA\n")));
                        printf(BOLD(CYAN("\nDigite o número de jogadores(1 ou 2):")));
                        scanf("%c",&opcaojg);
                        getchar();
                    }
                    if(opcaojg == '2'){
        
                        nomejogadores("\x1b[32m",jogador1,1);
                        nomejogadores("\x1b[31m",jogador2,2);
                    }
                    else if(opcaojg == '1'){

                        nomejogadores("\x1b[32m",jogador1,1);
                    }
                    controladormenu = 1;
                    break;
                case '2':
                    printf(BOLD(CYAN("Digite o nome do arquivo salvo:")));
                    fgets(nomearq,20,stdin);
                    remocao_salto(nomearq);
                    //Validação se o arquivo em questão existe ou não
                    if(lerJogo(jogovelha,jogador1,jogador2,nomearq,opcaojg,3,3) == -1){

                        printf(BOLD(RED("ARQUIVO NÃO ENCONTRADO!!!\n")));
                        controladormenu = 0;
                    }    
                    else{
                        for(int k = 0;k < 3;k++){

                            for(int m = 0;m < 3;m++){

                                if(jogovelha[k][m] != ' '){

                                    contadorjogadas += 1;
                                    jogadas += 1;
                                }
                            }
                        }   
                        controladormenu = 1;
                    }    
                    break;
                case '3':  
                    //Validação se o arquivo em questão existe ou não
                    if(lerJogo(jogovelha,jogador1,jogador2,nomearq,opcaojg,3,3) == -1){

                        printf(BOLD(RED("ARQUIVO NÃO ENCONTRADO!!!\n")));
                        controladormenu = 0;
                    }    
                    else{
                        for(int k = 0;k < 3;k++){

                            for(int m = 0;m < 3;m++){

                                if(jogovelha[k][m] != ' '){

                                    contadorjogadas += 1;
                                    jogadas += 1;
                                }
                            }
                        }   
                        controladormenu = 1;
                    }    
                    break;
                case '4':
                    //Impressão do Ranking dos 10 melhores jogadores
                    imprimeRanking(usuarios,tam);
                    break;  
        
                default:
                    printf(BOLD(RED("\nOpção Inválida!\n")));
                    controladormenu = 0;           
            }
        }
        if(opcaojg == '1'){

            //Início do jogo de 1 jogador
            umplayer(jogovelha,jogador1,"Computador",contadorjogadas,jogadas,usuarios,&tam);
            liberaMatriz(jogovelha,3);
            controladormenu = 0;    
        }
        else if(opcaojg == '2'){
        
            //Início do jogo de 2 jogadores
            doisplayers(jogovelha,jogador1,jogador2,contadorjogadas,jogadas,usuarios,&tam);
            liberaMatriz(jogovelha,3);
            controladormenu = 0;
        }
    }

    return 0;
}


