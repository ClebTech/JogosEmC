#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//range dos numeros a serem sorteados
#define MIN 1
#define MAX 999
#define total_numeros 10

//menu principal
int menu(){
	int opt;
	
	system("clear");
	printf("======================================\n");
	printf("\tJOGO ORDERNAR NÚMEROS\n");
	printf("======================================\n");
	printf("\t1 - INICIAR JOGO\n");
	printf("\t2 - INSTRUÇÕES\n");
	printf("\t0 - SAIR\n");
	scanf(" %d", &opt);
	
	return opt;
}

//instruções de jogo
int instrucoes(){
	system("clear");
	printf("\tCOMO FUNCIONA O JOGO:\n\n");
	printf("10 números aleátorios entre 1 e 999 são gerados pelo sistema, porém um de cada vez.\n");
	printf("A cada número gerado, o jogador deve escolher uma posição de 1 a 10\nonde aquele número ficará, ");
	printf("de maneira que, ao final do jogo, os 10 números \nsorteados fiquem em ordem crescente.\n\n");
	printf("======================================");
	printf("\n\tVEJA O EXEMPLO ABAIXO:\n");
	printf("======================================\n\n");
	printf("NÚMERO GERADO: 581\n\n");
	printf("1.  16\n");
	printf("2. \n");
	printf("3.  91\n");
	printf("4. \n");
	printf("5.  414\n");
	printf("6. \n");
	printf("7. \n");
	printf("8.  754\n");
	printf("9.  912\n");
	printf("10. 968\n");
	
	printf("\nEm qual posição (das 4 livres) você acha que o número sorteado (581)\ndeve ficar, de maneira que, ao final do jogo, todos os números estejam ordenados?\n\n");
	printf("(Perceba que, se você escolher a posição 7, e algum dos próximos números\ngerados for um número entre 581 e 754, POR EXEMPLO, você perderá o jogo,\n");
	printf("pois não terá mais como ordenar a lista de números, já que o número \nque acabou de ser sorteado deveria estar no sétimo lugar.)\n");
	printf("Então, seja estrátegico, antes de escolher uma posição, pense nos possiveis próximos números que virão!");
	printf("\n\n\tOBSERVAÇÕES:	\n");
	printf("Todos os números são gerados aleátoriamente pelo algoritmo do sistema,\nde maneira que,um número já gerado não influenciará nos próximos a serem gerados.\n");
	printf("Além disso, números repetidos não serão gerados, por exemplo, se o número 236 já foi gerado,\nele não será gerado novamente!\n");
	printf("\n\n\n");
	
	while(1){
		int opt;
		printf("APERTE 1 PARA VOLTAR AO MENU PRINCIPAL\n");
		scanf(" %d", &opt);
		
		if(opt == 1)
			return opt;
	}
}

//menu de fim, o menu que aparece caso o usuario perca ou ganhe
int menuFimJogo(char *msg){
	int opt;
	
	printf("\n===========================\n");
	printf("\t%s \n", msg);
	printf("===========================\n");
	printf("1 - JOGAR NOVAMENTE\n");
	printf("2 - VOLTAR AO MENU PRINCIPAL\n");
	printf("0 - SAIR\n");
	scanf(" %d", &opt);
	
	return opt;
	
}

//função de gerar numeros
int gerarNumeros(int listaNumerosSorteados[]){
	int numeroGerado=0, i=0, numeroValido=0;
	do{
		numeroGerado = MIN + rand()%(MAX-MIN+1);
		numeroValido=1;
		for(i=0; i<total_numeros; i++){
			if(numeroGerado==listaNumerosSorteados[i]){
				numeroValido=0;
				break;
			}
		}
	}while(!numeroValido);
	printf("NÚMERO GERADO: %d\n\n", numeroGerado);
	
	return numeroGerado;
}

//função que executa o jogo
void jogo(){
	int jogando=1, i=0, listaNumerosSorteados[total_numeros];
	
	//preenche todas as posições do vetor com o valor 0
	for(i=0; i<total_numeros; i++){
		listaNumerosSorteados[i] = 0;
	}
		
	while(jogando){
		system("clear");
		int j=0, posicao=0, posicaoValida=0;
		
		int numeroGerado = gerarNumeros(listaNumerosSorteados);
		
		for(i=0; i<total_numeros; i++){
			printf("%d. %d\n", i+1, listaNumerosSorteados[i]);
		}
		
		//verifica se a lista esta ficando em ordem
		for(i=0; i<total_numeros; i++){		
			if(i>0 && numeroGerado < listaNumerosSorteados[i] && numeroGerado > listaNumerosSorteados[i-1] && listaNumerosSorteados[i-1] != 0)
				jogando=0;
			
			//caso seja sorteado um numero menor do que o primeiro da lista
			if(numeroGerado < listaNumerosSorteados[0])
				jogando=0;
			
			if(numeroGerado > listaNumerosSorteados[i] && listaNumerosSorteados[i] != 0){
				jogando=0;
				for(j=i; j<=total_numeros; j++){
					if(listaNumerosSorteados[j] == 0){
						jogando = 1;
						break;
					}
				}
			}
		}
		
		//jogador escolhe uma posicao
		if(jogando){
			while(!posicaoValida){
				printf("\nEscolha uma posição: ");
				while(1){
					scanf(" %d", &posicao);
					if(posicao > total_numeros || posicao < 1){
						printf("ERRO! Escolha uma posição válidaa!\n");
					}else{
						break;
					}
				}
				
				if(posicao == 1 && listaNumerosSorteados[0] == 0)
					posicaoValida = 1;
					
				for(i=0; i<10; i++){
					if(listaNumerosSorteados[posicao-1] != 0){
						printf("ERRO! Escolha uma posição que esteja vazia!");
						break;
					}else{
						
						
						//caso o jogador tente colocar um numero em uma posição onde algum dos anteriores dele seja um numero maior que ele
						for(j=0; j<posicao-1; j++){
							posicaoValida=0;
							if(listaNumerosSorteados[j] > numeroGerado && listaNumerosSorteados[j] != 0){
								printf("ERRO! Se você colocar o número %d nessa posição, a lista ficará desordenada!\n", numeroGerado);
								break;
							}else{
								posicaoValida=1;
							}
						}
						
						
						
						if(posicaoValida){
							for(j=posicao; j<total_numeros; j++){
								posicaoValida=0;
								if(numeroGerado > listaNumerosSorteados[j] && listaNumerosSorteados[j] != 0){
									printf("\nERROOO! Se você colocar o número %d nessa posição, a lista ficará desordenada!\n", numeroGerado);
									break;
								}else{
									posicaoValida=1;
								}
							}
						}
						
						if(!posicaoValida)
							break;
							
							
					}
				}
			}
			
			listaNumerosSorteados[posicao-1] = numeroGerado;
		}else{
			while(1){
				switch(menuFimJogo("VOCÊ PERDEU!")){
					case 1:
						jogo();
						break;
					case 2:
						return;
					case 0:
						exit(0);
					default:
						printf("ERRO! Escolha uma posição válida!");
						break;	
				}
			}
		}
		//verificação se o usuario ganhou o jogo
		int confirmacao=0;
		for(i=0; i<total_numeros; i++){
		if(listaNumerosSorteados[i] > 0)
			confirmacao++;
		}
		
		//todas as 10 posições foram preenchidas, e com base nas logicas de verificação anteriores, a lista já está ordenada
		if(confirmacao==10){
			switch(menuFimJogo("VOCÊ GANHOU!")){
				case 1:
					jogo();
					break;
				case 2:
					return;
				case 0:
					exit(0);
				default:
					printf("ERRO! Escolha uma posição válida!");
					break;	
			}
		}
	}
}

int main(){
	srand(time(NULL));
	
	while(1){
		switch(menu()){
			case 1:
				jogo();
				break;
				
			case 2:
				instrucoes();
				break;
			
			case 0:
				exit(0);
			
			default:
				break;
		}
	}
	
	return 0;
}
//Codigo sujeito a alterações futuras
