//Bibliotecas usadas para cria��o desse jogo
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void letreiro(){
    printf("==========================\n");
    printf("=== JOGO DA VELHA EM C ===\n");
    printf("==========================\n\n");

}

//Interface do jogo, onde os jogadores escolher�o quem come�ar�
int interface(){
    system("cls");
    letreiro();
    printf("~ Escolha quem come�ar�\n\n");
    printf("1 - X\n");
    printf("2 - O\n");
    printf("3 - Tanto faz\n");
    int opcao;
    scanf("%d", &opcao);
    
    return opcao;
}

//Jogo da velha
void jogoDaVelha(int n, int sorteio){
    int jogando = 1, posicaoEscolhida, tentativas=0;
    char simbolo, posicoes[10];

//Caso os jogadores tenham escolhido a op��o 3 na interface, ser� feito um sorteio para saber quem come�ar� jogando
    if(sorteio)
        n = 1 + rand()%(10-1+1);
    
    //Jogo come�ou
    system("cls");
    while(jogando){
        //Isso aqui serve para ir alternando quem � o jogador da vez, exemplo: 1� X, depois O, depois X, depois O, depois X...
        if(n % 2 == 1)
            simbolo = 'X';

        if(n % 2 == 0)
            simbolo = 'O';
        n++;

        //Lendo uma posicao e verificando se a posicao lida eh valida
        system("cls");
        while(1){

            //Mostrando a matriz na tela
            letreiro();
            int x=1;
            for(int i=1; i<=3; i++){
                printf("       ");
                for(int j=1; j<=3; j++){
                    if((posicoes[x] == 'X') || (posicoes[x] == 'O')){
                        printf("[%c] ", posicoes[x]);
                    }else{
                        printf("[%d] ", x);
                    }
                    x++;
                }
                printf("\n");
            }

            //Verificando se deu empate
            if(tentativas == 9){
                printf("\n\n~ Fim de Jogo");
                printf("\nDEU EMPATE!");
                jogando = 0;
                break;
            }

            //Mostrando quem � o jogador da vez
            printf("\n\n~ Jogador da vez: %c\n", simbolo);
            printf("Escolha uma posicao: ");
            scanf("%d", &posicaoEscolhida);
            if((posicaoEscolhida > 9) || (posicaoEscolhida < 1) || (posicoes[posicaoEscolhida] == 'X' ) || (posicoes[posicaoEscolhida] == 'O')){
                system("cls");
                printf("ERRO! Escolha uma posi��o v�lida.\n");
            }else{
                tentativas++;
                posicoes[posicaoEscolhida] = simbolo;
                break;
            }
        }
        
        //Verificando se h� algum ganhador, existem 8 maneiras de algu�m ganhar (3 linhas + 3 colunhas + 2 diadonais)
        if ((posicoes[1] == simbolo && posicoes[2] == simbolo && posicoes[3] == simbolo) ||
            (posicoes[4] == simbolo && posicoes[5] == simbolo && posicoes[6] == simbolo) ||
            (posicoes[7] == simbolo && posicoes[8] == simbolo && posicoes[9] == simbolo) ||
            (posicoes[1] == simbolo && posicoes[4] == simbolo && posicoes[7] == simbolo) ||
            (posicoes[2] == simbolo && posicoes[5] == simbolo && posicoes[8] == simbolo) ||
            (posicoes[3] == simbolo && posicoes[6] == simbolo && posicoes[9] == simbolo) ||
            (posicoes[1] == simbolo && posicoes[5] == simbolo && posicoes[9] == simbolo) ||
            (posicoes[3] == simbolo && posicoes[5] == simbolo && posicoes[7] == simbolo)){
            system("cls");
            jogando = 0;
            //Mostrando a matriz do jogo da velha pela �ltima vez ap�s a vit�ria
            letreiro();
            int x=1;
            for(int i=1; i<=3; i++){
                printf("       ");
                for(int j=1; j<=3; j++){
                    if((posicoes[x] == 'X') || (posicoes[x] == 'O')){
                        printf("[%c] ", posicoes[x]);
                    }else{
                        printf("[%d] ", x);
                    }
                    x++;
                }
                printf("\n");
            }
            printf("\n\n~ Fim de Jogo");
            printf("\n%c VENCEU!!!\n", simbolo);
        }
    }
}

//C�digo main
int main(){
    //Colocando o idioma em portugu�s para possibilitar a utiliza��o de caracteres especiais
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    
    //Switch case para as op��es escolhidas na interface do jogo, 
    switch(interface()){
        case 1:
            jogoDaVelha(1, 0);
            break;
        case 2:
            jogoDaVelha(2, 0);
            break;
        case 3:
            jogoDaVelha('\0', 1);
            break;
    }
    return 0;
}

//Jogo criado por Clebson P. Santos, estudante de Sistemas de Informa��o no IFNMG - Campus Janu�ria.