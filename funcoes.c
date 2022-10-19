#include "funcoes.h"
#include "cores.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "funcaux.h"

//jogo 1 ou 2 jogadores
void umplayer(char **jogovelha,char *jogador1,char *jogador2,int contadorjogadas,int jogadas){
    
    char comando[30];
    char *comando1;
    char *comando2;
    char *nomearq;

    
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

                int linha = comando2[0] - '0';
                int coluna = comando2[1] - '0';
                jogovelha[linha - 1][coluna - 1] = 'X';
            }
                        
            else if(strcmp("salvar",comando1) == 0){

                nomearq = comando2;
                escrevejogo(jogovelha,nomearq,'1',3,3,jogadas,jogador1,"Computador");
                printf("\x1b[1m\x1b[37mArquivo '%s' salvo com sucesso!\n",nomearq);
                contadorjogadas = contadorjogadas - 1;
                jogadas = jogadas - 1; 
            }

            if(strcmp("voltar",comando1) == 0){
               
                escrevejogo(jogovelha,"jogoEmAndamento.txt",'1',3,3,jogadas,jogador1,"Computador");
                break;
            } 
        }
        
        //computador
        if(jogadas % 2 == 0){
            
            printf("\x1b[31m\nVez do %s!\n",jogador2);
            inteligenciacomp(jogovelha);
        }
        
       //checagem de resultados da partida
        if(checagem(jogovelha) == 1){

            tabuleiro(jogovelha);
            
            ganhou(jogador1);

            teclamenu();

            printf("\n");
            break;  
        }
        else if(checagem(jogovelha) == 2){

            tabuleiro(jogovelha);
            
            ganhou("Computador");

            teclamenu();

            printf("\n");
            break;
            
        }
        jogadas++;
        contadorjogadas++;
        //caso de empate
        if(contadorjogadas == 9){

            tabuleiro(jogovelha);
            
            empate();
            
            teclamenu();
            printf("\n");
            break;      
        }
    }
}
void doisplayers(char **jogovelha,char *jogador1,char *jogador2,int contadorjogadas,int jogadas){

    char comando[30];
    char *comando1;
    char *comando2;
    char *nomearq;


    while(contadorjogadas <= 9){

        printf("\n");
        tabuleiro(jogovelha);

        
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
    
                int linha = comando2[0] - '0';
                int coluna = comando2[1] - '0';
                jogovelha[linha - 1][coluna - 1] = 'X';
            }
                        
            else if(strcmp("salvar",comando1) == 0){

                nomearq = comando2;
                escrevejogo(jogovelha,nomearq,'2',3,3,jogadas,jogador1,jogador2);
                printf("\x1b[1m\x1b[37mArquivo '%s' salvo com sucesso!\n",nomearq);
                contadorjogadas = contadorjogadas - 1;
                jogadas = jogadas - 2; 
            }

            if(strcmp("voltar",comando1) == 0){
               
                escrevejogo(jogovelha,"jogoEmAndamento.txt",'2',3,3,jogadas,jogador1,jogador2);
                break;
            } 
            
        }       
        
        //JOGADOR 2
        if(jogadas % 2 == 0){

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
                   
                int linha = comando2[0] - '0';
                int coluna = comando2[1] - '0';
                jogovelha[linha - 1][coluna - 1] = 'O';
            }
                        
            else if(strcmp("salvar",comando) == 0){

                nomearq = comando2;
                escrevejogo(jogovelha,nomearq,'2',3,3,jogadas,jogador1,jogador2);
                printf("\x1b[1m\x1b[37mArquivo '%s' salvo com sucesso!\n",nomearq);
                contadorjogadas = contadorjogadas - 1;
                jogadas = jogadas - 1; 
            }

            if(strcmp("voltar",comando1) == 0){
                
                escrevejogo(jogovelha,"jogoEmAndamento.txt",'2',3,3,jogadas,jogador1,jogador2);
                break;
            } 
        }
        
        //checagem de resultados da partida
        if(checagem(jogovelha) == 1){

            tabuleiro(jogovelha);
                
            ganhou(jogador1);

            teclamenu();

            printf("\n");
                
            break;  
        }
        else if(checagem(jogovelha) == 2){

            tabuleiro(jogovelha);
                
            ganhou(jogador2);

            teclamenu();

            printf("\n");

            break;
                
        }
        jogadas++;
        contadorjogadas++;

        //caso de empate
        if(contadorjogadas == 9){

            tabuleiro(jogovelha);
                
            empate();
                
            teclamenu();
            printf("\n");

            break;      
        }
        
    } 
}

//salvamento e carregamento do jogo
void escrevejogo(char **jogovelha,char *arquivo,int opcaojg,int l,int c,int jogadas,char *jogador1,char*jogador2){

    FILE *jogo1 = fopen(arquivo,"w");

    opcaojg = opcaojg - '0';
    fprintf(jogo1,"%d\n",opcaojg);

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

        fprintf(jogo1,"%d\n",opcaojg - 1);
    }
    if(jogadas % 2 == 0){

        fprintf(jogo1,"%d\n",opcaojg);
    }
    fclose(jogo1);      
}
void lerJogo(char **jogovelha,char *jogador1,char *jogador2,char arquivo[20],int opcaojg,int l,int c){

    FILE *jogo1 = fopen(arquivo,"r");
    
    opcaojg = opcaojg + '0';
    fscanf(jogo1,"%d ",&opcaojg);
    fscanf(jogo1,"%s ",jogador1);
    fscanf(jogo1,"%s ",jogador2);
    
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
}

//tabuleiro
char** criaMatriz(int linha, int coluna){

    char **matriz;

    matriz = malloc(linha * sizeof(char*));
    for(int j = 0;j < linha;j++){

        matriz[j] = malloc(coluna * sizeof(char));
    }

    //inicializa a matriz
    for(int i = 0;i < linha;i++){

        for(int j = 0;j < coluna;j++){

            matriz[i][j] = ' ';
        }
    }

        return matriz;

}
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
void liberaMatriz(char** matriz, int linha){

    for(int q = 0;q < linha;q++){

        free(matriz[q]);
    }
    free(matriz);
}

//inteligencia do computador
void inteligenciacomp(char **jogovelha){

    int linha_comp;
    int coluna_comp;

    //vitória computador horizontal
    if(jogovelha[0][0] == 'O' && jogovelha[0][1] == 'O' && jogovelha[0][2] == ' '){

        jogovelha[0][2] = 'O';
    }
    else if(jogovelha[1][0] == 'O' && jogovelha[1][1] == 'O' && jogovelha[1][2] == ' '){

        jogovelha[1][2] = 'O';
    }
    else if(jogovelha[2][0] == 'O' && jogovelha[2][1] == 'O' && jogovelha[2][2] == ' '){

        jogovelha[2][2] = 'O';
    }
    else if(jogovelha[2][2] == 'O' && jogovelha[2][1] == 'O' && jogovelha[2][0] == ' '){

        jogovelha[0][0] = 'O';
    }
    else if(jogovelha[1][0] == ' ' && jogovelha[1][1] == 'O' && jogovelha[1][2] == 'O'){

        jogovelha[1][0] = 'O';
    }
    else if(jogovelha[0][2] == 'O' && jogovelha[0][1] == 'O' && jogovelha[0][0] == ' '){

        jogovelha[0][0] = 'O';
    }
    
    //vitória computador vertical
    else if(jogovelha[0][0] == 'O' && jogovelha[1][0] == 'O' && jogovelha[2][0] == ' '){

        jogovelha[2][0] = 'O';
    }
    else if(jogovelha[0][1] == 'O' && jogovelha[1][1] == 'O' && jogovelha[2][1] == ' '){

        jogovelha[2][1] = 'O';
    }
    else if(jogovelha[0][2] == 'O' && jogovelha[1][2] == 'O' && jogovelha[2][2] == ' '){

        jogovelha[2][2] = 'O';
    }
    else if(jogovelha[2][1] == 'O' && jogovelha[1][1] == 'O' && jogovelha[0][1] == ' '){

        jogovelha[0][1] = 'O';
    }
    else if(jogovelha[0][0] == ' ' && jogovelha[1][0] == 'O' && jogovelha[2][0] == 'O'){

        jogovelha[0][0] = 'O';
    }
    else if(jogovelha[2][2] == 'O' && jogovelha[1][2] == 'O' && jogovelha[0][2] == ' '){

        jogovelha[0][2] = 'O';
    }

     
    //vitoria diagonais
    else if(jogovelha[0][0] == 'O' && jogovelha[1][1] == 'O' && jogovelha[2][2] == ' '){

        jogovelha[2][2] = 'O';
    }
    else if(jogovelha[0][2] == 'O' && jogovelha[1][1] == 'O' && jogovelha[2][0] == ' '){

        jogovelha[2][0] = 'O';
    }
    else if(jogovelha[2][0] == 'O' && jogovelha[1][1] == 'O' && jogovelha[0][2] == ' '){

        jogovelha[0][2] = 'O';
    }
    else if(jogovelha[2][2] == 'O' && jogovelha[1][1] == 'O' && jogovelha[0][0] == ' '){

        jogovelha[0][0] = 'O';
    }

    //vitoria meio
    else if(jogovelha[0][0] == 'O' && jogovelha[1][1] == ' ' && jogovelha[2][2] == 'O'){

        jogovelha[1][1] = 'O';
    }
    else if(jogovelha[0][2] == 'O' && jogovelha[1][1] == ' ' && jogovelha[2][1] == 'O'){

        jogovelha[1][1] = 'O';
    }
    else if(jogovelha[0][1] == 'O' && jogovelha[1][1] == ' ' && jogovelha[2][1] == 'O'){

        jogovelha[1][1] = 'O';
    }
    else if(jogovelha[1][0] == 'O' && jogovelha[1][1] == ' ' && jogovelha[1][2] == 'O'){

        jogovelha[1][1] = 'O';
    }


    //vitória nos cantos meio
    else if(jogovelha[0][0] == 'O' && jogovelha[0][1] == ' ' && jogovelha[0][2] == 'O'){

        jogovelha[0][1] = 'O';
    }
    else if(jogovelha[2][0] == 'O' && jogovelha[2][1] == ' ' && jogovelha[2][2] == 'O'){

        jogovelha[2][1] = 'O';
    }
    else if(jogovelha[0][2] == 'O' && jogovelha[2][2] == 'O' && jogovelha[1][2] == ' '){

        jogovelha[1][2] = 'O';
    }
    else if(jogovelha[0][0] == 'O' && jogovelha[1][0] == ' ' && jogovelha[2][0] == 'O'){

        jogovelha[1][0] = 'O';
    }
    
    //possibildades de vitória horizontal
    else if(jogovelha[0][0] == 'X' && jogovelha[0][1] == 'X' && jogovelha[0][2] == ' '){

        jogovelha[0][2] = 'O';
    }
    else if(jogovelha[1][0] == 'X' && jogovelha[1][1] == 'X' && jogovelha[1][2] == ' '){

        jogovelha[1][2] = 'O';
    }
    else if(jogovelha[2][0] == 'X' && jogovelha[2][1] == 'X' && jogovelha[2][2] == ' '){

        jogovelha[2][2] = 'O';
    }
    else if(jogovelha[2][2] == 'X' && jogovelha[2][1] == 'X' && jogovelha[2][0] == ' '){

        jogovelha[2][0] = 'O';
    }
    else if(jogovelha[1][0] == ' ' && jogovelha[1][1] == 'X' && jogovelha[1][2] == 'X'){

        jogovelha[1][0] = 'O';
    }
    else if(jogovelha[0][2] == 'X' && jogovelha[0][1] == 'X' && jogovelha[0][0] == ' '){

        jogovelha[0][0] = 'O';
    }

    //POssibilidades de vitória vertical
    else if(jogovelha[0][0] == 'X' && jogovelha[1][0] == 'X' && jogovelha[2][0] == ' '){

        jogovelha[2][0] = 'O';
    }
    else if(jogovelha[0][1] == 'X' && jogovelha[1][1] == 'X' && jogovelha[2][1] == ' '){

        jogovelha[2][1] = 'O';
    }
    else if(jogovelha[0][2] == 'X' && jogovelha[1][2] == 'X' && jogovelha[2][2] == ' '){

        jogovelha[2][2] = 'O';
    }
    else if(jogovelha[2][1] == 'X' && jogovelha[1][1] == 'X' && jogovelha[0][1] == ' '){

        jogovelha[0][1] = 'O';
    }
    else if(jogovelha[0][0] == ' ' && jogovelha[1][0] == 'X' && jogovelha[2][0] == 'X'){

        jogovelha[0][0] = 'O';
    }
    else if(jogovelha[2][2] == 'X' && jogovelha[1][2] == 'X' && jogovelha[0][2] == ' '){

        jogovelha[0][2] = 'O';
    }


    //Possibilidades diagonais
    else if(jogovelha[0][0] == 'X' && jogovelha[1][1] == 'X' && jogovelha[2][2] == ' '){

        jogovelha[2][2] = 'O';
    }
    else if(jogovelha[0][2] == 'X' && jogovelha[1][1] == 'X' && jogovelha[2][0] == ' '){

        jogovelha[2][0] = 'O';
    }
    else if(jogovelha[2][0] == 'X' && jogovelha[1][1] == 'X' && jogovelha[0][2] == ' '){

        jogovelha[0][2] = 'O';
    }
    else if(jogovelha[2][2] == 'X' && jogovelha[1][1] == 'X' && jogovelha[0][0] == ' '){

        jogovelha[0][0] = 'O';
    }
     
    
    //vitória no meio
    else if(jogovelha[0][0] == 'X' && jogovelha[1][1] == ' ' && jogovelha[2][2] == 'X'){

        jogovelha[1][1] = 'O';
    }
    else if(jogovelha[0][2] == 'X' && jogovelha[1][1] == ' ' && jogovelha[2][1] == 'X'){

        jogovelha[1][1] = 'O';
    }
    else if(jogovelha[0][1] == 'X' && jogovelha[1][1] == ' ' && jogovelha[2][1] == 'X'){

        jogovelha[1][1] = 'O';
    }
    else if(jogovelha[1][0] == 'X' && jogovelha[1][1] == ' ' && jogovelha[1][2] == 'X'){

        jogovelha[1][1] = 'O';
    }
    

    //vitória nos cantos meio
    else if(jogovelha[0][0] == 'X' && jogovelha[0][1] == ' ' && jogovelha[0][2] == 'X'){

        jogovelha[0][1] = 'O';
    }
    else if(jogovelha[2][0] == 'X' && jogovelha[2][1] == ' ' && jogovelha[2][2] == 'X'){

        jogovelha[2][1] = 'O';
    }
    else if(jogovelha[0][2] == 'X' && jogovelha[2][2] == 'X' && jogovelha[1][2] == ' '){

        jogovelha[1][2] = 'O';
    }
    else if(jogovelha[0][0] == 'X' && jogovelha[1][0] == ' ' && jogovelha[2][0] == 'X'){

        jogovelha[1][0] = 'O';
    }

    //jogadas iniciais
    else if(jogovelha[0][0] == 'X' && jogovelha[0][1] == ' ' && jogovelha[0][2] == ' ' && jogovelha[1][0] == ' ' && jogovelha[1][1] == ' ' && jogovelha[1][2] == ' ' && jogovelha[2][0] == ' ' && jogovelha[2][1] == ' ' && jogovelha[2][2] == ' '){

        jogovelha[1][1] = 'O';
    }
    else if(jogovelha[0][0] == ' ' && jogovelha[0][1] == ' ' && jogovelha[0][2] == 'X' && jogovelha[1][0] == ' ' && jogovelha[1][1] == ' ' && jogovelha[1][2] == ' ' && jogovelha[2][0] == ' ' && jogovelha[2][1] == ' ' && jogovelha[2][2] == ' '){

        jogovelha[1][1] = 'O';
    }
    else if((jogovelha[0][0] == ' ' && jogovelha[0][1] == ' ' && jogovelha[0][2] == ' ' && jogovelha[1][0] == ' ' && jogovelha[1][1] == ' ' && jogovelha[1][2] == ' ' && jogovelha[2][0] == 'X' && jogovelha[2][1] == ' ' && jogovelha[2][2] == ' ')){

        jogovelha[1][1] = 'O';
    }
    else if((jogovelha[0][0] == ' ' && jogovelha[0][1] == ' ' && jogovelha[0][2] == ' ' && jogovelha[1][0] == ' ' && jogovelha[1][1] == ' ' && jogovelha[1][2] == ' ' && jogovelha[2][0] == ' ' && jogovelha[2][1] == ' ' && jogovelha[2][2] == 'X')){

        jogovelha[1][1] = 'O';
    }
    else if((jogovelha[0][0] == ' ' && jogovelha[0][1] == ' ' && jogovelha[0][2] == ' ' && jogovelha[1][0] == ' ' && jogovelha[1][1] == 'X' && jogovelha[1][2] == ' ' && jogovelha[2][0] == ' ' && jogovelha[2][1] == ' ' && jogovelha[2][2] == ' ')){

        jogovelha[0][0] = 'O';
    }
    
    //jogadas sem efeito
    else{

        do{
            srand(time(NULL));
            linha_comp = rand() % 2;
            coluna_comp = rand() % 2;

        }while(jogovelha[linha_comp][coluna_comp] != ' ');

        jogovelha[linha_comp][coluna_comp] = 'O';
    }
}    

