//Bibliotecas usadas para criação desse jogo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Jogo da Velha (Jogador x Jogador) feito em C.
 
 //Função de limpar a tela
 void limpaTela(){
	#ifdef _WIN32
		system("cls");
	#elif __unix__ || __linux__
		system("clear");
	#else
		printf("ERRO AO LIMPAR A TELA! Sistema Operacional imcompativel!\n");
	#endif
}
 
//Função que mostra o letreiro do jogo
void letreiro(){
	char *cor_vermelho = "\033[1;31m"; // Vermelho Escuro
	char *cor_verde = "\033[1;92m"; // Verde Claro
	char *reset = "\033[0m";        // Reset para cor padrão
	
    printf("%s==========================\n", cor_vermelho);
    printf("=== %sJOGO DA VELHA EM C %s===\n", cor_verde, cor_vermelho);
    printf("==========================\n\n%s", reset);

}

//Interface do jogo, onde os jogadores escolherão quem começa
char interface(){
	char opcao;
	char *cor_azul = "\033[1;94m";  // Azul
    char *cor_amarelo = "\033[1;93m"; // Amarelo
    char *cor_verde = "\033[1;92m"; // Verde Claro
	char *reset = "\033[0m";        // Reset para cor padrão
	
	limpaTela();
	letreiro();
	
	printf("%s~ Escolha quem começa.%s\n\n", cor_verde, reset);
	printf("\t%sX%s\t", cor_amarelo, reset);
	printf("%sO%s\n", cor_azul, reset);
	scanf(" %c", &opcao);
	
	if(opcao == 'x'){
		opcao = 'X';
		return opcao;
    }else if(opcao == 'o'){
		opcao = 'O';
		return opcao;
	}else{
		return '\0';
	}
	
}

//Jogo da velha
void jogoDaVelha(int n){
    int jogando=1, posicaoEscolhida, tentativas=0;
    char simbolo='\0';
    char posicoes[10]={'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
    
    //Jogo começou
    limpaTela();
    while(jogando){
        //Isso aqui serve para ir alternando quem é o jogador da vez, exemplo: primeiro X, depois O, depois X, depois O, depois X...
        if(n % 2 == 1)
            simbolo = 'X';

        if(n % 2 == 0)
            simbolo = 'O';
        n++;

        //Lendo uma posicao e verificando se a posicao lida eh valida
        limpaTela();
        
        char *cor_azul = "\033[1;94m";  // Azul Claro
        char *cor_amarelo = "\033[1;93m"; // Amarelo Claro
        char *cor_verde = "\033[1;92m"; // Verde Claro
        char *cor_vermelho = "\033[1;31m"; // Vermelho Escuro
		char *reset = "\033[0m";        // Reset para cor padrão
		
        while(1){
            //Mostrando a matriz na tela
            letreiro();
            int x=1;
            for(int i=1; i<=3; i++){
                printf("       ");
                for(int j=1; j<=3; j++){
                    if((posicoes[x] == 'X') || (posicoes[x] == 'O')){
						if(posicoes[x] == 'X'){
							printf("[%s%c%s] ", cor_amarelo, posicoes[x], reset);
						}
						if(posicoes[x] == 'O'){
							printf("[%s%c%s] ", cor_azul, posicoes[x], reset);
						}
                    }else{
                        printf("[%d] ", x);
                    }
                    x++;
                }
                printf("\n");
            }

            //Verificando se deu empate
            if(tentativas == 9){
				printf("\n\n%s~ Fim de Jogo%s\n\n", cor_verde, reset);
				printf("%s==========================\n", cor_vermelho);
				printf("===       %sEMPATE       %s===\n", cor_verde, cor_vermelho);
				printf("==========================\n%s", reset);
                jogando = 0;
                break;
            }

            //Mostrando quem é o jogador da vez
            if(simbolo == 'X')
				printf("\n\n%s[%s%c%s] Escolha uma posicao. %s\n", cor_verde, cor_amarelo, simbolo, cor_verde, reset);
			if(simbolo == 'O')
				printf("\n\n%s[%s%c%s] Escolha uma posicao. %s\n", cor_verde, cor_azul, simbolo, cor_verde, reset);
				
            scanf("%d", &posicaoEscolhida);
            //Verificação para saber se o jogador informou uma posição válida!
            if((posicaoEscolhida > 9) || (posicaoEscolhida < 1) || (posicoes[posicaoEscolhida] == 'X' ) || (posicoes[posicaoEscolhida] == 'O')){
                limpaTela();
                printf("%sERRO! Escolha uma posição válida.%s\n", cor_verde, reset);
            }else{
                tentativas++;
                posicoes[posicaoEscolhida] = simbolo;
                break;
            }
        }
        
        //Verificando se há algum ganhador, existem 8 maneiras de alguém ganhar (3 linhas + 3 colunhas + 2 diadonais)
        if ((posicoes[1] == simbolo && posicoes[2] == simbolo && posicoes[3] == simbolo) ||
            (posicoes[4] == simbolo && posicoes[5] == simbolo && posicoes[6] == simbolo) ||
            (posicoes[7] == simbolo && posicoes[8] == simbolo && posicoes[9] == simbolo) ||
            (posicoes[1] == simbolo && posicoes[4] == simbolo && posicoes[7] == simbolo) ||
            (posicoes[2] == simbolo && posicoes[5] == simbolo && posicoes[8] == simbolo) ||
            (posicoes[3] == simbolo && posicoes[6] == simbolo && posicoes[9] == simbolo) ||
            (posicoes[1] == simbolo && posicoes[5] == simbolo && posicoes[9] == simbolo) ||
            (posicoes[3] == simbolo && posicoes[5] == simbolo && posicoes[7] == simbolo)){
            limpaTela();
            jogando = 0;
            
            //Mostrando a matriz do jogo da velha com os posições finais
            letreiro();
            int x=1;
            for(int i=1; i<=3; i++){
                printf("       ");
                for(int j=1; j<=3; j++){
                    if((posicoes[x] == 'X') || (posicoes[x] == 'O')){
						if(posicoes[x] == 'X'){
							printf("[%s%c%s] ", cor_amarelo, posicoes[x], reset);
						}
						if(posicoes[x] == 'O'){
							printf("[%s%c%s] ", cor_azul, posicoes[x], reset);
						}
                    }else{
                        printf("[%d] ", x);
                    }
                    x++;
                }
                printf("\n");
            }
            
            //Mostrando quem foi o vencedor
            printf("\n\n%s~ Fim de Jogo%s\n\n", cor_verde, reset);
            printf("%s==========================", cor_vermelho);
            if(simbolo == 'X')
				printf("\n%s===    %sVENCEDOR: %s%c     %s===%s\n", cor_vermelho, cor_verde, cor_amarelo, simbolo, cor_vermelho, reset);
			if(simbolo == 'O')
				printf("\n%s===    %sVENCEDOR: %s%c     %s===%s\n", cor_vermelho, cor_verde, cor_azul, simbolo, cor_vermelho, reset);
			printf("%s==========================\n%s", cor_vermelho, reset);
        }
    }
}

//Função main
int main(){
    
    switch(interface()){
        case 'X':
            jogoDaVelha(1);
            break;
        case 'O':
            jogoDaVelha(2);
            break;
        default:
			return 1;
    }
    return 0;
}

//Jogo criado por Clebson P. Santos, estudante de Sistemas de Informação no IFNMG - Campus Januária.
