#include "funcoes.h"
#include "cores.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "funcaux.h"

//FUNÇOES PRINCIPAIS PARA O FUNCIONAMENTO DO JOGO


//Jogo 1 ou 2 jogadores
void umplayer(char **jogovelha,char *jogador1,char *jogador2,int contadorjogadas,int jogadas,Usuario *jogadores){
    
    char comando[30];
    char *comando1;
    char *comando2;
    char *nomearq;

    int linha;
    int coluna;


    //Inicialização da struct
    //Jogador1
    Usuario jgdr1;
    strcpy(jgdr1.nome,jogador1);
    jgdr1.vitoria = 0;
    jgdr1.empate = 0;
    jgdr1.derrota = 0;

    //Jogador2
    Usuario jgdr2;
    strcpy(jgdr2.nome,jogador2);
    jgdr2.vitoria = 0;
    jgdr2.empate = 0;
    jgdr2.derrota = 0;
    
    while(contadorjogadas <= 9){

        printf("\n");
        tabuleiro(jogovelha);

        
        //jogador 1
        if(jogadas % 2 != 0){

            comandos(comando,jogador1,"\x1b[32m");
            
            comando1 = strtok(comando," ");
            comando2 = strtok(NULL," ");
            
            //validação do comando
            while((strcmp("marcar",comando1) != 0) && (strcmp("salvar",comando1) != 0) && (strcmp("voltar",comando1) != 0)){
               
                printf(BOLD(RED("Comando incorreto!!!\n")));
                comandos(comando,jogador1,"\x1b[32m");

                comando1 = strtok(comando," ");
                comando2 = strtok(NULL," ");
            }
    
            if(strcmp("marcar",comando1) == 0){

                linha = comando2[0] - '0';
                coluna = comando2[1] - '0';
                while(((linha > 3) || (linha <= 0)) || ((coluna > 3) || (coluna <= 0)) || (jogovelha[linha-1][coluna-1] != ' ')){

                    printf(BOLD(RED("CASAS INVÁLIDAS!!!\n")));
                    printf(BOLD(YELLOW("Digite as casas novamente!!")));
                    comandos(comando2,jogador1,"\x1b[32m");
                    linha = comando2[0] - '0';
                    coluna = comando2[1] - '0';
                }
                   
                jogovelha[linha - 1][coluna - 1] = 'X';
                jogadas++; 
            }            
            
            else if(strcmp("salvar",comando1) == 0){

                nomearq = comando2;
                escreveJogo(jogovelha,nomearq,'1',3,3,jogadas,jogador1,"Computador");
                printf("\x1b[1m\x1b[37mArquivo '%s' salvo com sucesso!\n",nomearq);
                contadorjogadas = contadorjogadas - 1; 
            }

            if(strcmp("voltar",comando1) == 0){
               
                escreveJogo(jogovelha,"jogoEmAndamento.txt",'1',3,3,jogadas,jogador1,"Computador");
                break;
            } 
        }
        
        //computador
        else if(jogadas % 2 == 0){
            
            printf("\x1b[31m\nVez do %s!\n",jogador2);
            inteligenciaComp(jogovelha);
            jogadas++;
        }
        
       //checagem de resultados da partida
        if(checagem(jogovelha) == 1){

            tabuleiro(jogovelha);
            
            //Contabilização das estatísticas
            ganhou(jogador1);
            jgdr1.vitoria++;
            jgdr2.derrota++;

            //Posição no Ranking
            if(posicaoRanking(jogadores,jogador1) == -1){

                printf(BOLD(YELLOW("\nSua posição está fora do Ranking\n")));
            }
            else{

                printf("\n\x1b[1mSua posição no Ranking:%d\n",posicaoRanking(jogadores,jogador1));
            }

            //Atualização e ordenação do ranking
            atualizaEstatisticas(jogadores,jgdr1,jgdr2);

            teclamenu();

            printf("\n");
            break;  
        }
        if(checagem(jogovelha) == 2){

            tabuleiro(jogovelha);
            
            //Contabilização das estatísticas
            perdeu();
            jgdr1.derrota++;
            jgdr2.vitoria++;

            //Posição no Ranking
            if(posicaoRanking(jogadores,jogador2) == -1){

                printf(BOLD(YELLOW("\nSua posição está fora do Ranking\n")));
            }
            else{

                printf("\n\x1b[1mSua posição no Ranking:%d\n",posicaoRanking(jogadores,jogador2));
            }

            //Atualização e ordenação do ranking
            atualizaEstatisticas(jogadores,jgdr1,jgdr2);

            teclamenu();

            printf("\n");
            break;
            
        }
        
        contadorjogadas++;

        //caso de empate
        if(contadorjogadas == 9){

            tabuleiro(jogovelha);
            
            //Contabilização das estatísticas
            empate();
            jgdr1.empate++;
            jgdr2.empate++;

            //Atualização e ordenação do ranking
            atualizaEstatisticas(jogadores,jgdr1,jgdr2);

    
            teclamenu();
            printf("\n");
            break;      
        }
    }
}
void doisplayers(char **jogovelha,char *jogador1,char *jogador2,int contadorjogadas,int jogadas){

    //Comandos do jogo
    char comando[30];
    char *comando1;
    char *comando2;
    char *nomearq;

    int linha;
    int coluna;


    while(contadorjogadas <= 9){

        printf("\n");
        tabuleiro(jogovelha);

        //JOGADOR 1
        if(jogadas % 2 != 0){

            comandos(comando,jogador1,"\x1b[32m");
            
            comando1 = strtok(comando," ");
            comando2 = strtok(NULL," ");
            
            //validação do comando
            while(((strcmp("marcar",comando1) != 0) && (strcmp("salvar",comando1) != 0) && (strcmp("voltar",comando1) != 0))){
               
                printf(BOLD(RED("Comando incorreto!!!\n")));
                comandos(comando,jogador1,"\x1b[32m");

                comando1 = strtok(comando," ");
                comando2 = strtok(NULL," ");
            }
    
            if(strcmp("marcar",comando1) == 0){
    
                linha = comando2[0] - '0';
                coluna = comando2[1] - '0';
                while(((linha > 3) || (linha < 0)) || ((coluna > 3) || (coluna < 0)) || (jogovelha[linha-1][coluna-1] != ' ')){

                    printf(BOLD(RED("CASAS INVÁLIDAS!!!\n")));
                    printf(BOLD(YELLOW("Digite as casas novamente!!")));
                    comandos(comando2,jogador1,"\x1b[32m");
                    linha = comando2[0] - '0';
                    coluna = comando2[1] - '0';
                }
                   
                jogovelha[linha - 1][coluna - 1] = 'X';
                jogadas++; 
            }
                        
            else if(strcmp("salvar",comando1) == 0){

                nomearq = comando2;
                escreveJogo(jogovelha,nomearq,'2',3,3,jogadas,jogador1,jogador2);
                printf("\x1b[1m\x1b[37mArquivo '%s' salvo com sucesso!\n",nomearq);
                contadorjogadas = contadorjogadas - 1;
            }

            if(strcmp("voltar",comando1) == 0){
               
                escreveJogo(jogovelha,"jogoEmAndamento.txt",'2',3,3,jogadas,jogador1,jogador2);
                break;
            } 
            
        }       
        
        //JOGADOR 2
        else if(jogadas % 2 == 0){

            comandos(comando,jogador2,"\x1b[31m");

            comando1 = strtok(comando," ");
            comando2 = strtok(NULL," ");
               
            //validação do comando
            while(((strcmp("marcar",comando1) != 0) && (strcmp("salvar",comando1) != 0) && (strcmp("voltar",comando1) != 0))){
               
                printf(BOLD(RED("Comando incorreto!!!\n")));
                comandos(comando,jogador2,"\x1b[31m");

                comando1 = strtok(comando," ");
                comando2 = strtok(NULL," ");
            }
            if(strcmp("marcar",comando1) == 0){
                   
                linha = comando2[0] - '0';
                coluna = comando2[1] - '0';
                while(((linha > 3) || (linha < 0)) || ((coluna > 3) || (coluna < 0)) || (jogovelha[linha-1][coluna-1] != ' ')){

                    printf(BOLD(RED("CASAS INVÁLIDAS!!!\n")));
                    printf(BOLD(YELLOW("Digite as casas novamente!!")));
                    comandos(comando2,jogador2,"\x1b[31m");
                    linha = comando2[0] - '0';
                    coluna = comando2[1] - '0';
                }
                   
                jogovelha[linha - 1][coluna - 1] = 'O';
                jogadas++; 
            }
                        
            else if(strcmp("salvar",comando) == 0){

                nomearq = comando2;
                escreveJogo(jogovelha,nomearq,'2',3,3,jogadas,jogador1,jogador2);
                printf("\x1b[1m\x1b[37mArquivo '%s' salvo com sucesso!\n",nomearq);
                contadorjogadas = contadorjogadas - 1;
            }

            if(strcmp("voltar",comando1) == 0){
                
                escreveJogo(jogovelha,"jogoEmAndamento.txt",'2',3,3,jogadas,jogador1,jogador2);
                break;
            } 
        }
        
        //checagem de resultados da partida
        if(checagem(jogovelha) == 1){

            tabuleiro(jogovelha);
                
            ganhou(jogador1);
            
            //Posição no Ranking
            /*if(posicaoRanking(jogadores,jogador1) == -1){

                printf(BOLD(YELLOW("\nSua posição está fora do Ranking\n")));
            }
            else{

                printf("\n\x1b[1mSua posição no Ranking:%d\n",posicaoRanking(jogadores,jogador1));
            }*/
            
            
            teclamenu();

            printf("\n");
                
            break;  
        }
        else if(checagem(jogovelha) == 2){

            tabuleiro(jogovelha);
                
            ganhou(jogador2);

            //Posição no Ranking
            /*if(posicaoRanking(jogadores,jogador1) == -1){

                printf(BOLD(YELLOW("\nSua posição está fora do Ranking\n")));
            }
            else{

                printf("\n\x1b[1mSua posição no Ranking:%d\n",posicaoRanking(jogadores,jogador1));
            }*/
            

            teclamenu();

            printf("\n");

            break;
                
        }
        
        contadorjogadas++;

        //caso de empate
        if(contadorjogadas == 9){

            tabuleiro(jogovelha);
                
            empate();

            //contadores de estatisticas
            
                
            teclamenu();

            printf("\n");

            break;      
        }
        
    } 
}

//Salvamento e carregamento do jogo
void escreveJogo(char **jogovelha,char *arquivo,char opcaojg,int l,int c,int jogadas,char *jogador1,char*jogador2){

    FILE *jogo1 = fopen(arquivo,"w");

    fprintf(jogo1,"%c\n",opcaojg);

    fprintf(jogo1,"%s\n",jogador1);
    fprintf(jogo1,"%s \n",jogador2);
    for(int i = 0;i < l;i++){

        for(int j = 0;j < c;j++){
 
            if(jogovelha[i][j] == ' '){

                fprintf(jogo1,"- ");
            }
            else{
                fprintf(jogo1,"%c ",jogovelha[i][j]);
            }
        }
        fprintf(jogo1,"\n");
    } 
    if(jogadas % 2 != 0){

        opcaojg = '1';
        fprintf(jogo1,"%c\n",opcaojg);
    }
    if(jogadas % 2 == 0){

        fprintf(jogo1,"%c\n",opcaojg);
    }
    fclose(jogo1);      
}
int lerJogo(char **jogovelha,char *jogador1,char *jogador2,char arquivo[20],char opcaojg,int l,int c){

    
    FILE *jogo1 = NULL;
    
    jogo1 = fopen(arquivo,"r");
    if(jogo1 == NULL){

        
        return -1;
    }

    fscanf(jogo1,"%c ",&opcaojg);
    fgets(jogador1,20,jogo1);
    jogador1[strlen(jogador1) - 1] = '\0';
    fgets(jogador2,20,jogo1);
    jogador2[strlen(jogador2) - 1] = '\0';
    
    for(int i = 0;i < l;i++){

        for(int j = 0;j < c;j++){

            if(jogovelha[i][j] == ' '){

                fscanf(jogo1,"%c ",&jogovelha[i][j]);
            }
            else{
                fscanf(jogo1,"%c ",&jogovelha[i][j]);
            } 
        }
    }

    for(int k = 0;k < l;k++){

        for(int m = 0;m < c;m++){

            if(jogovelha[k][m] == '-'){

                jogovelha[k][m] = ' ';
            }
        }
    }
    fclose(jogo1);

    return 1;
}


//Tabuleiro
void tabuleiro(char **jogovelha){

    printf("\u250F");
    for(int i = 0; i < 4; i++){
        printf("\u2501\u2501\u2501");
        if(i != 3)
            printf("\u2533");
        else{
            printf("\u2513");
        }
    }
    printf("\n");
    printf("\u2503   ");
    for(int i = 0; i < 3; i++){
        printf("\u2503 %d ", i+1);
    }
    printf("\u2503");
    printf("\n");

    printf("\u2523");
    for(int i = 0; i < 4; i++){
        printf("\u2501\u2501\u2501");
        if(i != 3)
            printf("\u254B");
        else{
            printf("\u252B");
        }
    }
    printf("\n");

    for(int i = 0; i < 3; i++){
        printf("\u2503 %d ", i+1);
        for(int j = 0; j < 3; j++){
            printf("\u2503 %c ", jogovelha[i][j]);
        }
        printf("\u2503");
        printf("\n");
        if(i != 2){
            printf("\u2523");
            for(int j = 0; j < 4; j++){
                printf("\u2501\u2501\u2501");
                if(j != 3)
                    printf("\u254B");
                else{
                    printf("\u252B");
                }
            }
        }
        else{
            printf("\u2517");
            for(int j = 0; j < 4; j++){
                printf("\u2501\u2501\u2501");
                if(j != 3)
                    printf("\u253B");
                else{
                    printf("\u251B");
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}


//Ranking e suas funções 
void atualizaEstatisticas(Usuario *jogadores,Usuario jgdr1,Usuario jgdr2){

    FILE *ranking = fopen("velha.ini","r+");
    int tam;
    fscanf(ranking,"%d ",&tam);
    for(int i = 0;i < tam;i++){

        fgets(jogadores[i].nome,100,ranking);
        jogadores[i].nome[strlen(jogadores[i].nome) - 1] = '\0';
        fscanf(ranking,"%d %d %d",&jogadores[i].vitoria,&jogadores[i].empate,&jogadores[i].derrota);
    }
    
    if(checaJogadores(jogadores,tam,jgdr1,jgdr2) == 0){
    
        strcpy(jogadores[tam].nome,jgdr1.nome);
        jogadores[tam].vitoria = jgdr1.vitoria;
        jogadores[tam].empate = jgdr1.empate;
        jogadores[tam].derrota = jgdr1.derrota;

        tam = tam + 1;

        strcpy(jogadores[tam].nome,jgdr2.nome);
        jogadores[tam].vitoria = jgdr2.vitoria;
        jogadores[tam].empate = jgdr2.empate;
        jogadores[tam].derrota = jgdr2.derrota;

        tam = tam + 1;
    }
    else if(checaJogadores(jogadores,tam,jgdr1,jgdr2) == 1){

        strcpy(jogadores[tam].nome,jgdr2.nome);
        jogadores[tam].vitoria = jgdr2.vitoria;
        jogadores[tam].empate = jgdr2.empate;
        jogadores[tam].derrota = jgdr2.derrota;

        tam = tam + 1;
    }
    else if(checaJogadores(jogadores,tam,jgdr1,jgdr2) == 2){

        strcpy(jogadores[tam].nome,jgdr1.nome);
        jogadores[tam].vitoria = jgdr1.vitoria;
        jogadores[tam].empate = jgdr1.empate;
        jogadores[tam].derrota = jgdr1.derrota;

        tam = tam + 1;
    }
    
    //ordenação dos vetores
    ordenaVetor(jogadores,tam);
    fclose(ranking);
    
    FILE *arquivo = fopen("velha.ini","r+");
    
    //Atualização de players no ranking
    fprintf(ranking,"%d",tam);
    
    fclose(arquivo);
    
}
void imprimeRanking(Usuario *jogadores,int tam){

    FILE *arquivo = fopen("velha.ini","r");
    int controlador = 1;
    lerRanking(jogadores);
    while(controlador){
        
        printf(BOLD(WHITE("RANKING\n\n\n")));

        printf(BOLD(WHITE("Ordem: Posição - Nome - Vitória - Empate - Derrota\n\n")));

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
    fclose(arquivo);
}



