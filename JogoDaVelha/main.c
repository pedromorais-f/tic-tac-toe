#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "cores.h"
#include "funcoes.h"
#include "funcaux.h"

//função principal main
int main(){

    char **jogovelha;
    
    char opcao;
    char opcaojg;
    
    char jogador1[20];
    char jogador2[20];
    char nomearq[20];
    
    int contadorjogadas = 0;
    int jogadas = 1;
    int controladormenu = 0;
    int controlatudo = 1;

    //Alocação e leitura do arquivo
    Usuario *usuarios = alocaVetor(100);
    lerRanking(usuarios);

    FILE *arquivo = fopen("velha.ini","r");
    int tam;

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
                    fscanf(arquivo,"%d",&tam);
                    //Atualização do arquivo
                    escreveNovoRanking(usuarios,tam);
                    fclose(arquivo);
                    liberaVetor(usuarios);
                    return 0;
                case '1':
                    printf(BOLD(CYAN("\nDigite o número de jogadores(1 ou 2):")));
                    scanf("%c",&opcaojg);
                    getchar();
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
                    fscanf(arquivo,"%d",&tam);
                    imprimeRanking(usuarios,tam);
                    break;  
        
                default:
                    printf(BOLD(RED("\nOpção Inválida!\n")));
                    controladormenu = 0;           
            }
        }
        if(opcaojg == '1'){

            umplayer(jogovelha,jogador1,"Computador",contadorjogadas,jogadas,usuarios);
            liberaMatriz(jogovelha,3);
            controladormenu = 0;    
        }
        else if(opcaojg == '2'){
        
            doisplayers(jogovelha,jogador1,jogador2,contadorjogadas,jogadas);
            liberaMatriz(jogovelha,3);
            controladormenu = 0;
        }
    }

    return 0;
}


