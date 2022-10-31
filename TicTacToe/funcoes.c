#include "funcoes.h"
#include "cores.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "funcaux.h"
#include "ranking.h"

//MAIN FUNCTIONS OF THE GAME


//Game for one player
void umplayer(char **jogovelha,char *jogador1,char *jogador2,int contadorjogadas,int jogadas,Usuario *jogadores,int *tam){
    
    /* Variables for all commands that the game have,including save the game,mark on the board and
    return to menu*/
    char comando[30];
    char *comando1;
    char *comando2;
    
    //Variable for the File
    char *nomearq;

    //Location on the board
    int linha;
    int coluna;


    //Inicializing the struct of the players
    //Player 1
    Usuario jgdr1;
    strcpy(jgdr1.nome,jogador1);
    jgdr1.vitoria = 0;
    jgdr1.empate = 0;
    jgdr1.derrota = 0;

    //Player 2
    Usuario jgdr2;
    strcpy(jgdr2.nome,jogador2);
    jgdr2.vitoria = 0;
    jgdr2.empate = 0;
    jgdr2.derrota = 0;
    
    while(contadorjogadas <= 9){

        printf("\n");
        tabuleiro(jogovelha);

        
        //Player 1
        if(jogadas % 2 != 0){

            //Reading commands
            comandos(comando,jogador1,"\x1b[32m");
            
            comando1 = strtok(comando," ");
            comando2 = strtok(NULL," ");
            
            //validations of the commands
            while((strcmp("marcar",comando1) != 0) && (strcmp("salvar",comando1) != 0) && (strcmp("voltar",comando1) != 0)){
               
                printf(BOLD(RED("Comando incorreto!!!\n")));
                comandos(comando,jogador1,"\x1b[32m");

                comando1 = strtok(comando," ");
                comando2 = strtok(NULL," ");
            }
    
            //Mark on the board
            if(strcmp("marcar",comando1) == 0){

                linha = comando2[0] - '0';
                coluna = comando2[1] - '0';
                
                //Validations about where you mark on the board
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

                //Command to save a game
                nomearq = comando2;
                escreveJogo(jogovelha,nomearq,'1',3,3,jogadas,jogador1,"Computador");
                printf("\x1b[1m\x1b[37mArquivo '%s' salvo com sucesso!\n",nomearq);
                contadorjogadas = contadorjogadas - 1; 
            }

            else if(strcmp("voltar",comando1) == 0){
               
                //Command that return to menu and save the game if the player,after quit the game,wants to come back
                escreveJogo(jogovelha,"jogoEmAndamento.txt",'1',3,3,jogadas,jogador1,"Computador");
                break;
            } 
        }
        
        //Computer's time
        else if(jogadas % 2 == 0){
            
            //Computer intellIgence
            printf("\x1b[31m\nVez do %s!\n",jogador2);
            inteligenciaComp(jogovelha);
            jogadas++;
        }
        
       //Verify the results
        if(checagem(jogovelha) == 1){

            tabuleiro(jogovelha);
            
            //Counting the stats of the players
            ganhou(jogador1);
            jgdr1.vitoria++;
            jgdr2.derrota++;

            //Updating and reorganizing the rank
            atualizaEstatisticas(jogadores,jgdr1,jgdr2,tam);

            //Looking for the position of the player in the rank
            if(posicaoRanking(jogadores,jogador1) == -1){

                printf(BOLD(YELLOW("\nSua posição está fora do Ranking\n")));
            }
            else{

                printf("\n\x1b[1mSua posição no Ranking:%d\n",posicaoRanking(jogadores,jogador1));
            }

            //Key to return to the menu
            teclamenu();

            printf("\n");
            break;  
        }
        if(checagem(jogovelha) == 2){

            tabuleiro(jogovelha);
            
            //Counting the stats of the players
            perdeu();
            jgdr1.derrota++;
            jgdr2.vitoria++;


            //Updating and reorganizing the rank
            atualizaEstatisticas(jogadores,jgdr1,jgdr2,tam);
            
            //Looking for the position of the player in the rank
            if(posicaoRanking(jogadores,jogador1) == -1){

                printf(BOLD(YELLOW("\nSua posição está fora do Ranking\n")));
            }
            else{

                printf("\n\x1b[1mSua posição no Ranking:%d\n",posicaoRanking(jogadores,jogador1));
            }

            //Key to return to the menu
            teclamenu();

            printf("\n");
            break;
            
        }
        
        contadorjogadas++;

        //Draw case
        if(contadorjogadas == 9){

            tabuleiro(jogovelha);
            
            //Counting the stats
            empate();
            jgdr1.empate++;
            jgdr2.empate++;

            //Updating and reorganizing the rank
            atualizaEstatisticas(jogadores,jgdr1,jgdr2,tam);

            //Looking for the position of the player in the rank
            if(posicaoRanking(jogadores,jogador1) == -1){

                printf(BOLD(YELLOW("\nSua posição está fora do Ranking\n")));
            }
            else{

                printf("\n\x1b[1mSua posição no Ranking:%d\n",posicaoRanking(jogadores,jogador1));
            }

            //Key to return to the menu
            teclamenu();

            printf("\n");
            break;      
        }
    }
}

void doisplayers(char **jogovelha,char *jogador1,char *jogador2,int contadorjogadas,int jogadas,Usuario *jogadores,int *tam){

    /* Variables for all commands that the game have,including save the game,mark on the board and
    return to menu*/
    char comando[30];
    char *comando1;
    char *comando2;
    
    //Variable for the File
    char *nomearq;

    //Location on the board
    int linha;
    int coluna;

    //Inicializing the struct 
    //Player 1
    Usuario jgdr1;
    strcpy(jgdr1.nome,jogador1);
    jgdr1.vitoria = 0;
    jgdr1.empate = 0;
    jgdr1.derrota = 0;

    //PLayer 2
    Usuario jgdr2;
    strcpy(jgdr2.nome,jogador2);
    jgdr2.vitoria = 0;
    jgdr2.empate = 0;
    jgdr2.derrota = 0;


    while(contadorjogadas <= 9){

        printf("\n");
        tabuleiro(jogovelha);

        //Player 1
        if(jogadas % 2 != 0){

            comandos(comando,jogador1,"\x1b[32m");
            
            comando1 = strtok(comando," ");
            comando2 = strtok(NULL," ");
            
            //validations of the commands
            while(((strcmp("marcar",comando1) != 0) && (strcmp("salvar",comando1) != 0) && (strcmp("voltar",comando1) != 0))){
               
                printf(BOLD(RED("Comando incorreto!!!\n")));
                comandos(comando,jogador1,"\x1b[32m");

                comando1 = strtok(comando," ");
                comando2 = strtok(NULL," ");
            }
    
            //Mark on the board
            if(strcmp("marcar",comando1) == 0){
    
                linha = comando2[0] - '0';
                coluna = comando2[1] - '0';
                
                //Validations about where you mark on the board
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
                        
            //Command to save a game
            else if(strcmp("salvar",comando1) == 0){

                nomearq = comando2;
                escreveJogo(jogovelha,nomearq,'2',3,3,jogadas,jogador1,jogador2);
                printf("\x1b[1m\x1b[37mArquivo '%s' salvo com sucesso!\n",nomearq);
                contadorjogadas = contadorjogadas - 1;
            }

            //Command that return to menu and save the game if the player,after quit the game,wants to come back
            else if(strcmp("voltar",comando1) == 0){
               
                escreveJogo(jogovelha,"jogoEmAndamento.txt",'2',3,3,jogadas,jogador1,jogador2);
                break;
            } 
            
        }       
        
        //Player 2 
        else if(jogadas % 2 == 0){

            comandos(comando,jogador2,"\x1b[31m");

            comando1 = strtok(comando," ");
            comando2 = strtok(NULL," ");
               
            //validations of the commands
            while(((strcmp("marcar",comando1) != 0) && (strcmp("salvar",comando1) != 0) && (strcmp("voltar",comando1) != 0))){
               
                printf(BOLD(RED("Comando incorreto!!!\n")));
                comandos(comando,jogador2,"\x1b[31m");

                comando1 = strtok(comando," ");
                comando2 = strtok(NULL," ");
            }
            
            //Mark on the board
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
            
            //Command to save a game    
            else if(strcmp("salvar",comando) == 0){

                nomearq = comando2;
                escreveJogo(jogovelha,nomearq,'2',3,3,jogadas,jogador1,jogador2);
                printf("\x1b[1m\x1b[37mArquivo '%s' salvo com sucesso!\n",nomearq);
                contadorjogadas = contadorjogadas - 1;
            }
            //Command that return to menu and save the game if the player,after quit the game,wants to come back
            else if(strcmp("voltar",comando1) == 0){
                
                escreveJogo(jogovelha,"jogoEmAndamento.txt",'2',3,3,jogadas,jogador1,jogador2);
                break;
            } 
        }
        
        //Verify the results
        if(checagem(jogovelha) == 1){

            tabuleiro(jogovelha);
                
            ganhou(jogador1);
            
            //Counting the stats
            jgdr1.vitoria++;
            jgdr2.derrota++;

            //Updating and reorganizing the rank
            atualizaEstatisticas(jogadores,jgdr1,jgdr2,tam);

            //Looking for the position of the player in the rank
            if(posicaoRanking(jogadores,jogador1) == -1){

                printf(BOLD(YELLOW("\nSua posição está fora do Ranking\n")));
            }
            else{

                printf("\n\x1b[1mSua posição no Ranking:%d\n",posicaoRanking(jogadores,jogador1));
            }
            
            //Key to return to the menu
            teclamenu();

            printf("\n");
                
            break;  
        }
        else if(checagem(jogovelha) == 2){

            tabuleiro(jogovelha);
                
            ganhou(jogador2);

            //Counting the stats
            jgdr1.derrota++;
            jgdr2.vitoria++;


            //Updating and reorganizing the rank
            atualizaEstatisticas(jogadores,jgdr1,jgdr2,tam);
            
            //Looking for the position of the player in the rank
            if(posicaoRanking(jogadores,jogador2) == -1){

                printf(BOLD(YELLOW("\nSua posição está fora do Ranking\n")));
            }
            else{

                printf("\n\x1b[1mSua posição no Ranking:%d\n",posicaoRanking(jogadores,jogador2));
            }
            
            //Key to return to the menu
            teclamenu();

            printf("\n");

            break;
                
        }
        
        contadorjogadas++;

        //Draw's case
        if(contadorjogadas == 9){

            tabuleiro(jogovelha);
                
            empate();
            
            //Counting the stats
            jgdr1.empate++;
            jgdr2.empate++;

            //Updating and reorganizing the rank
            atualizaEstatisticas(jogadores,jgdr1,jgdr2,tam);

            //Looking for the position of both players in the rank
            if(posicaoRanking(jogadores,jogador1) == -1){

                printf(BOLD(YELLOW("\nSua posição está fora do Ranking\n")));
            }
            else{

                printf("\n\x1b[1mSua posição no Ranking:%d\n",posicaoRanking(jogadores,jogador1));
            }
            
            if(posicaoRanking(jogadores,jogador2) == -1){

                printf(BOLD(YELLOW("\nSua posição está fora do Ranking\n")));
            }
            else{

                printf("\n\x1b[1mSua posição no Ranking:%d\n",posicaoRanking(jogadores,jogador2));
            }
            
            //Key to return to the menu  
            teclamenu();

            printf("\n");

            break;      
        }
        
    } 
}

//Save and Load the game Functions
void escreveJogo(char **jogovelha,char *arquivo,char opcaojg,int l,int c,int jogadas,char *jogador1,char*jogador2){

    FILE *jogo1 = fopen(arquivo,"w");

    //Game option that the player choose,1 or 2 players
    fprintf(jogo1,"%c\n",opcaojg);

    //Save the name of the players in the match
    fprintf(jogo1,"%s\n",jogador1);
    fprintf(jogo1,"%s\n",jogador2);
    
    //Save the board and turn the empty spaces in "-"
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

    //Save the last player that would mark on the board
    if(jogadas % 2 != 0){

        fprintf(jogo1,"%c\n",opcaojg - 1);
    }
    if(jogadas % 2 == 0){

        fprintf(jogo1,"%c\n",opcaojg);
    }
    fclose(jogo1);      
}

int lerJogo(char **jogovelha,char *jogador1,char *jogador2,char arquivo[100],char opcaojg,int l,int c){

    
    FILE *jogo1 = NULL;
    
    //If the file do not exist,the function will return -1
    jogo1 = fopen(arquivo,"r");
    if(jogo1 == NULL){

        
        return -1;
    }

    //Read the option that was saved on the file
    fscanf(jogo1,"%c ",&opcaojg);

    //Read the players name and remove \n
    fgets(jogador1,20,jogo1);
    jogador1[strlen(jogador1) - 1] = '\0';
    
    fgets(jogador2,20,jogo1);
    jogador2[strlen(jogador2) - 1] = '\0';
    
    //Read the board saved on file
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

    //Return the "-" in empty spaces 
    for(int k = 0;k < l;k++){

        for(int m = 0;m < c;m++){

            if(jogovelha[k][m] == '-'){

                jogovelha[k][m] = ' ';
            }
        }
    }
    fclose(jogo1);

    //if the function returns 1,the load was a success
    return 1;
}
int lerJogoEmAndamento(char **jogovelha,char *jogador1,char *jogador2,char arquivo[20],char opcaojg,int l,int c){

    
    FILE *jogo1 = NULL;
    
    //If the file do not exist,the function will return -1
    jogo1 = fopen(arquivo,"r");
    if(jogo1 == NULL){

        
        return -1;
    }

    //Read the option that was saved on the file
    fscanf(jogo1,"%c ",&opcaojg);

    //Read the players name and remove \n
    fgets(jogador1,20,jogo1);
    jogador1[strlen(jogador1) - 1] = '\0';
    
    fgets(jogador2,20,jogo1);
    jogador2[strlen(jogador2) - 1] = '\0';
    
    //Read the board saved on file
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

     //Return the "-" in empty spaces 
    for(int k = 0;k < l;k++){

        for(int m = 0;m < c;m++){

            if(jogovelha[k][m] == '-'){

                jogovelha[k][m] = ' ';
            }
        }
    }
    fclose(jogo1);

    //if the function returns 1,the load was a success
    return 1;
}

//Board construction
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




