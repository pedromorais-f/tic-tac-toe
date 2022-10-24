#include "funcoes.h"
#include "cores.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "funcaux.h"
#include "ranking.h"


//FUNÇOES PRINCIPAIS PARA O FUNCIONAMENTO DO JOGO


//Jogo 1 ou 2 jogadores
void umplayer(char **jogovelha,char *jogador1,char *jogador2,int contadorjogadas,int jogadas,Usuario *jogadores,int *tam){
    
    //Variáveis dos comandos,sendo comando = linha geral,comando 1 = a ação(marcar,salvar ou voltar),
    //e comando 2 = escrever onde deseja salvar ou marcação no tabuleiro
    char comando[30];
    char *comando1;
    char *comando2;
    
    //Nome do arquivo
    char *nomearq;

    //Coordenadas das posições no tabuleiro
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

            //Função para ler o comando escolhido
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
    
            //Marcação das casas
            if(strcmp("marcar",comando1) == 0){

                linha = comando2[0] - '0';
                coluna = comando2[1] - '0';
                //Validação da marcação das casas no jogo
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

                //Comando de salvar o jogo em um arquivo
                nomearq = comando2;
                escreveJogo(jogovelha,nomearq,'1',3,3,jogadas,jogador1,"Computador");
                printf("\x1b[1m\x1b[37mArquivo '%s' salvo com sucesso!\n",nomearq);
                contadorjogadas = contadorjogadas - 1; 
            }

            if(strcmp("voltar",comando1) == 0){
               
                //Volta ao menu e salva o jogo que estava em curso em um arquivo
                escreveJogo(jogovelha,"jogoEmAndamento.txt",'1',3,3,jogadas,jogador1,"Computador");
                break;
            } 
        }
        
        //computador
        else if(jogadas % 2 == 0){
            
            //Jogadas da máquina e sua "Inteligencia"
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

            //Atualização e ordenação do ranking
            atualizaEstatisticas(jogadores,jgdr1,jgdr2,tam);

            //Posição no Ranking
            if(posicaoRanking(jogadores,jogador1) == -1){

                printf(BOLD(YELLOW("\nSua posição está fora do Ranking\n")));
            }
            else{

                printf("\n\x1b[1mSua posição no Ranking:%d\n",posicaoRanking(jogadores,jogador1));
            }

            //Tecla de voltar para o menu
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


            //Atualização e ordenação do ranking
            atualizaEstatisticas(jogadores,jgdr1,jgdr2,tam);
            
            //Posição no Ranking
            if(posicaoRanking(jogadores,jogador1) == -1){

                printf(BOLD(YELLOW("\nSua posição está fora do Ranking\n")));
            }
            else{

                printf("\n\x1b[1mSua posição no Ranking:%d\n",posicaoRanking(jogadores,jogador1));
            }

            //Tecla de volta ao menu
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
            atualizaEstatisticas(jogadores,jgdr1,jgdr2,tam);

            //Posição no Ranking
            if(posicaoRanking(jogadores,jogador1) == -1){

                printf(BOLD(YELLOW("\nSua posição está fora do Ranking\n")));
            }
            else{

                printf("\n\x1b[1mSua posição no Ranking:%d\n",posicaoRanking(jogadores,jogador1));
            }

            //Tecla de volta ao menu
            teclamenu();

            printf("\n");
            break;      
        }
    }
}

void doisplayers(char **jogovelha,char *jogador1,char *jogador2,int contadorjogadas,int jogadas,Usuario *jogadores,int *tam){

    //Variáveis dos comandos,sendo comando = linha geral,comando 1 = a ação(marcar,salvar ou voltar),
    //e comando 2 = escrever onde deseja salvar ou marcação no tabuleiro
    char comando[30];
    char *comando1;
    char *comando2;
    
    //Variável para o nome do arquivo
    char *nomearq;

    //Casas para marcação no tabuleiro
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
    
            //Marcação das casas do Jogador 1
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
                        
            //Salvamento do jogo
            else if(strcmp("salvar",comando1) == 0){

                nomearq = comando2;
                escreveJogo(jogovelha,nomearq,'2',3,3,jogadas,jogador1,jogador2);
                printf("\x1b[1m\x1b[37mArquivo '%s' salvo com sucesso!\n",nomearq);
                contadorjogadas = contadorjogadas - 1;
            }

            //Volta ao menu e escreve o jogo em andamento
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
            //Marcação no tabuleiro do Jogador 2
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
            //Salvamento do jogo          
            else if(strcmp("salvar",comando) == 0){

                nomearq = comando2;
                escreveJogo(jogovelha,nomearq,'2',3,3,jogadas,jogador1,jogador2);
                printf("\x1b[1m\x1b[37mArquivo '%s' salvo com sucesso!\n",nomearq);
                contadorjogadas = contadorjogadas - 1;
            }
            //Volta ao menu e salva o jogo em andamento
            if(strcmp("voltar",comando1) == 0){
                
                escreveJogo(jogovelha,"jogoEmAndamento.txt",'2',3,3,jogadas,jogador1,jogador2);
                break;
            } 
        }
        
        //checagem de resultados da partida
        if(checagem(jogovelha) == 1){

            tabuleiro(jogovelha);
                
            ganhou(jogador1);
            
            jgdr1.vitoria++;
            jgdr2.derrota++;

            //Atualização e ordenação do ranking
            atualizaEstatisticas(jogadores,jgdr1,jgdr2,tam);

            //Posição no Ranking
            if(posicaoRanking(jogadores,jogador1) == -1){

                printf(BOLD(YELLOW("\nSua posição está fora do Ranking\n")));
            }
            else{

                printf("\n\x1b[1mSua posição no Ranking:%d\n",posicaoRanking(jogadores,jogador1));
            }
            
            
            teclamenu();

            printf("\n");
                
            break;  
        }
        else if(checagem(jogovelha) == 2){

            tabuleiro(jogovelha);
                
            ganhou(jogador2);

            jgdr1.derrota++;
            jgdr2.vitoria++;


            //Atualização e ordenação do ranking
            atualizaEstatisticas(jogadores,jgdr1,jgdr2,tam);
            
            //Posição no Ranking
            if(posicaoRanking(jogadores,jogador2) == -1){

                printf(BOLD(YELLOW("\nSua posição está fora do Ranking\n")));
            }
            else{

                printf("\n\x1b[1mSua posição no Ranking:%d\n",posicaoRanking(jogadores,jogador2));
            }
            

            teclamenu();

            printf("\n");

            break;
                
        }
        
        contadorjogadas++;

        //caso de empate
        if(contadorjogadas == 9){

            tabuleiro(jogovelha);
                
            empate();
            jgdr1.empate++;
            jgdr2.empate++;

             //Atualização e ordenação do ranking
            atualizaEstatisticas(jogadores,jgdr1,jgdr2,tam);

            //Posição no Ranking
            if(posicaoRanking(jogadores,jogador1) == -1){

                printf(BOLD(YELLOW("\nSua posição está fora do Ranking\n")));
            }
            else{

                printf("\n\x1b[1mSua posição no Ranking:%d\n",posicaoRanking(jogadores,jogador1));
            }
            //Posição no Ranking
            if(posicaoRanking(jogadores,jogador2) == -1){

                printf(BOLD(YELLOW("\nSua posição está fora do Ranking\n")));
            }
            else{

                printf("\n\x1b[1mSua posição no Ranking:%d\n",posicaoRanking(jogadores,jogador2));
            }
            
                
            teclamenu();

            printf("\n");

            break;      
        }
        
    } 
}

//Salvamento e carregamento do jogo
void escreveJogo(char **jogovelha,char *arquivo,char opcaojg,int l,int c,int jogadas,char *jogador1,char*jogador2){

    FILE *jogo1 = fopen(arquivo,"w");

    //Opção jogada no jogo,sendo 1 ou 2 jogadores
    fprintf(jogo1,"%c\n",opcaojg);

    //Salva o nome dos jogadores na partida
    fprintf(jogo1,"%s\n",jogador1);
    fprintf(jogo1,"%s \n",jogador2);
    
    //Salva o tabuleiro e os espaços vazios se tornam asteriscos
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

    //Salva quem foi o último a jogar
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
    //Validação do arquivo,se ele não existir,retorna -1
    jogo1 = fopen(arquivo,"r");
    if(jogo1 == NULL){

        
        return -1;
    }

    //Leitura da opção jogada salva no arquivo
    fscanf(jogo1,"%c ",&opcaojg);

    //Leitura do nomme dos jogadores na seção e remoção do /n na leitura
    fgets(jogador1,20,jogo1);
    jogador1[strlen(jogador1) - 1] = '\0';
    fgets(jogador2,20,jogo1);
    jogador2[strlen(jogador2) - 1] = '\0';
    
    //Leitura do tabuleiro
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

    //Substituição dos asteriscos por espaços vazios 
    for(int k = 0;k < l;k++){

        for(int m = 0;m < c;m++){

            if(jogovelha[k][m] == '-'){

                jogovelha[k][m] = ' ';
            }
        }
    }
    fclose(jogo1);

    //Retorno de 1,para a sucesso do carregamento
    return 1;
}

//Tabuleiro
void tabuleiro(char **jogovelha){

    
    printf("\u250F");// ┏ (top-left)
    for(int i = 0; i < 4; i++){
        printf("\u2501\u2501\u2501");// ━ (horizontal)
        if(i != 3)
            printf("\u2533");// ┳ (top-join)
        else{
            printf("\u2513");// ┓ (top-right)
        }
    }
    printf("\n");
    printf("\u2503   ");// ┃ (vertical)
    for(int i = 0; i < 3; i++){
        printf("\u2503 %d ", i+1);// ┃ (vertical)
    }
    printf("\u2503");// ┃ (vertical)
    printf("\n");

    printf("\u2523");// ┣ (middle-left)
    for(int i = 0; i < 4; i++){
        printf("\u2501\u2501\u2501");// ━ (horizontal)
        if(i != 3)
            printf("\u254B");// ╋ (middle-join)
        else{
            printf("\u252B");// ┫ (middle-right)
        }
    }
    printf("\n");

    for(int i = 0; i < 3; i++){
        printf("\u2503 %d ", i+1);// ┃ (vertical)
        for(int j = 0; j < 3; j++){
            printf("\u2503 %c ", jogovelha[i][j]);// ┃ (vertical)
        }
        printf("\u2503");// ┃ (vertical)
        printf("\n");
        if(i != 2){
            printf("\u2523");// ┣ (middle-left)
            for(int j = 0; j < 4; j++){
                printf("\u2501\u2501\u2501");// ━ (horizontal)
                if(j != 3)
                    printf("\u254B");// ╋ (middle-join)
                else{
                    printf("\u252B");// ┫ (middle-right)
                }
            }
        }
        else{
            printf("\u2517");// ┗ (bottom-left)
            for(int j = 0; j < 4; j++){
                printf("\u2501\u2501\u2501");// ━ (horizontal)
                if(j != 3)
                    printf("\u253B");// ┻ (bottom-join)
                else{
                    printf("\u251B");// ┛ (bottom-right)
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}




