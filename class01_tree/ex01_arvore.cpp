//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

//data struct declare
struct cadastro {
	struct cadastro *prox;
	struct cadastro *ant;
	int valor;
};
typedef struct cadastro cad;

//INSERIR
//void inserir(cad *raiz, int numero) {		// AUTO INSERT
 void inserir(cad *raiz) {
	cad *novo = (cad *)malloc(sizeof(cad));
	
	novo -> ant = NULL;
	novo -> prox = NULL;
	novo -> valor = NULL;
	
	if(raiz -> valor == NULL) {
		printf("Informe o valor: ");
		scanf("%d", &raiz -> valor);
//		raiz -> valor = numero;				// AUTO INSERT
	}
	else {
		printf("Informe o valor: ");
		scanf("%d", &novo -> valor);
//		novo -> valor = numero;				// AUTO INSERT
	}

	if(raiz -> ant == NULL && novo -> valor != NULL && novo -> valor < raiz -> valor) {
		raiz -> ant = novo;
	}
	else if(raiz -> prox == NULL && novo -> valor != NULL && novo -> valor > raiz -> valor) {
		raiz -> prox = novo;
	}
	else if(novo -> valor < raiz -> valor && raiz -> ant != NULL) {		//add on left to the tree
		cad *TEMP = raiz -> ant;

		while(novo -> valor < TEMP -> valor && TEMP -> ant != NULL) {
			TEMP = TEMP -> ant;
			
			while(novo -> valor > TEMP -> valor && TEMP -> prox != NULL) {
				TEMP = TEMP -> prox;
			}
		}
		
		while(novo -> valor > TEMP -> valor && TEMP -> prox != NULL) {
			TEMP = TEMP -> prox;
			
			while(novo -> valor < TEMP -> valor && TEMP -> ant != NULL) {
				TEMP = TEMP -> ant;
			}
		}

		if(TEMP -> ant == NULL && novo -> valor < TEMP -> valor) {
			TEMP -> ant = novo;
		}
		else if(TEMP -> prox == NULL && novo -> valor > TEMP -> valor) {
			TEMP -> prox = novo;
		}
	}
	else if(novo -> valor > raiz -> valor && raiz -> prox != NULL) {		//add on right to the tree
		cad *TEMP = raiz -> prox;
		
		while(novo -> valor < TEMP -> valor && TEMP -> ant != NULL) {
			TEMP = TEMP -> ant;
			
			while(novo -> valor > TEMP -> valor && TEMP -> prox != NULL) {
				TEMP = TEMP -> prox;
			}
		}
		
		while(novo -> valor > TEMP -> valor && TEMP -> prox != NULL) {
			TEMP = TEMP -> prox;
			
			while(novo -> valor < TEMP -> valor && TEMP -> ant != NULL) {
				TEMP = TEMP -> ant;
			}
		}

		if(TEMP -> ant == NULL && novo -> valor < TEMP -> valor) {
			TEMP -> ant = novo;
		}
		else if(TEMP -> prox == NULL && novo -> valor > TEMP -> valor) {
			TEMP -> prox = novo;
		}
	}
}

//INSERIR RECURSIVO
void inserir_recursive(cad *raiz, int valor) {
	cad *novo = (cad *)malloc(sizeof(cad));
	novo -> ant = NULL;
	novo -> prox = NULL;
	novo -> valor = valor;
	
	if(raiz -> valor == NULL) {
		raiz -> valor = valor;
	}
	else {
		if(raiz -> valor > valor && raiz -> ant == NULL) {
			raiz -> ant = novo;
		}
		else if(raiz -> valor > valor && raiz -> ant != NULL) {
			inserir_recursive(raiz -> ant, valor);
		}
		else if(raiz -> valor < valor && raiz -> prox == NULL) {
			raiz -> prox = novo;
		}
		else if(raiz -> valor < valor && raiz -> prox != NULL) {
			inserir_recursive(raiz -> prox, valor);
		}
	}
}

//IMPRIMIR EM ORDEM
void show_ordem_recursive(cad *raiz) {
	cad *RAIZT = (cad *)malloc(sizeof(cad));
	RAIZT = raiz;

    if(RAIZT != NULL){
        show_ordem_recursive(RAIZT -> ant);
        printf("%i ", RAIZT -> valor);
        
        show_ordem_recursive(RAIZT -> prox);
    }
}

//IMPRIMIR EM PR�-ORDEM
void show_preordem_recursive(cad *raiz) {
	cad *RAIZT = (cad *)malloc(sizeof(cad));
	RAIZT = raiz;

    if(RAIZT != NULL){
        printf("%i ", RAIZT -> valor);
        show_preordem_recursive(RAIZT -> ant);        
        show_preordem_recursive(RAIZT -> prox);
    }
}

//IMPRIMIR EM P�S-ORDEM
void show_posordem_recursive(cad *raiz) {
	cad *RAIZT = (cad *)malloc(sizeof(cad));
	RAIZT = raiz;

    if(RAIZT != NULL){
        show_posordem_recursive(RAIZT -> ant);
        show_posordem_recursive(RAIZT -> prox);
        printf("%i ", RAIZT -> valor);
    }
}

//REMOVER
void delete_raiz(cad *raiz, int valor) {
	cad *TEMP1;
	cad *TEMP2;
	cad *RAIZT = (cad *)malloc(sizeof(cad));
	RAIZT = raiz;
	
	if(RAIZT != NULL) {
		if(valor == raiz -> valor) {
			
			
		}
		else if(valor < raiz -> valor) {
			cad *TEMP;
			TEMP = raiz -> ant;
			delete_raiz(raiz -> ant, valor);
			
		}
		else if(valor > raiz -> valor){
			
		}
	}


     {
        if(RAIZT -> valor == valor) {
        	TEMP1 = RAIZT -> ant;
        	TEMP2 = RAIZT -> prox;
        	TEMP2 -> prox -> ant = TEMP2 -> ant;
        	TEMP2 -> ant = RAIZT -> ant;
        	raiz = TEMP2;
        	free(RAIZT);
		}
		else {
			TEMP1 = RAIZT -> ant;
			show_ordem_recursive(RAIZT -> ant);
		}
		TEMP1 -> ant;
    }
show_ordem_recursive(RAIZT -> prox);
}

//TRABALHO ED II - JOSE FERREIRA - IMPRIMIR NOS DO TIPO RAIZ
void imprimir_nos_tipo_raiz(cad *raiz) {
	cad *RAIZT = (cad *)malloc(sizeof(cad));
	RAIZT = raiz;

    if(RAIZT != NULL){
        imprimir_nos_tipo_raiz(RAIZT -> ant);
        
		if(RAIZT -> ant != NULL && RAIZT -> prox != NULL) {
			printf("Raiz %i \n", RAIZT -> valor);	
		}
        
        imprimir_nos_tipo_raiz(RAIZT -> prox);
    }
}

//TRABALHO ED II - JOSE FERREIRA - NUMERO E SEU DOBRO
int imprimir_numero_e_dobro(cad *raiz, int numero, int dobro, int n) {
	cad *RAIZT = (cad *)malloc(sizeof(cad));
	RAIZT = raiz;

    if(RAIZT != NULL){
        n = imprimir_numero_e_dobro(RAIZT -> ant, numero, dobro, n);
        if(RAIZT -> valor == numero) {
//        	printf("\nO numero informado ( %i ) consta na arvore\n", numero);
        	n = 1;
		}
		
	    if(RAIZT -> valor == dobro) {
//	    	printf("O DOBRO ( %i ) do numero informado ( %i ) consta na arvore", dobro, dobro / 2);
	    	n = 2;
		}
        
        n = imprimir_numero_e_dobro(RAIZT -> prox, numero, dobro, n);
    }
    
    return n;
}

void menu(cad *raiz) {
	int opcao, i=0, valor;
	
	system("cls");
	
	while(i == 0) {
		system("cls");
		printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf(":::::::::::::::::::. MENU .:::::::::::::::::::\n");
		printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
		
		printf("\n1 - Inserir");
		printf("\n2 - Inserir Recursivo");
		printf("\n3 - Imprimir Ordem Recursivo");
		printf("\n4 - Imprimir Pre-Ordem Recursivo");
		printf("\n5 - Imprimir Pos-Ordem Recursivo");
		printf("\n6 - Remover");
		printf("\n7 - TRABALHO ED II - JOSE FERREIRA - IMPRIMIR NOS DO TIPO RAIZ");
		printf("\n8 - TRABALHO ED II - JOSE FERREIRA - NUMERO E SEU DOBRO");
		printf("\n6 - Remover");
		printf("\n0 - Sair");
		
		printf("\n\nEscolha uma opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao) {
			case 1 : {
				//inserir fim
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("::::::::::::::::::. INSERIR .:::::::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
				inserir(raiz);
				
//				inserir(raiz, 0);		// AUTO INSERT

				system("pause");
				break;
			}
			case 2 : {
				//inserir recursivo
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf(":::::::::::::. INSERIR RECURSIVO .::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
//				printf("Informe o valor: ");
//				scanf("%d", &valor);
//				
//				inserir_recursive(raiz, valor);

				// AUTO INSERT
				inserir_recursive(raiz, 11);
				inserir_recursive(raiz, 6);
				inserir_recursive(raiz, 5);
				inserir_recursive(raiz, 2);
				inserir_recursive(raiz, 18);
				inserir_recursive(raiz, 10);
				inserir_recursive(raiz, 9);
				inserir_recursive(raiz, 17);
				inserir_recursive(raiz, 8);
				inserir_recursive(raiz, 4);
				inserir_recursive(raiz, 13);
				inserir_recursive(raiz, 1);
				inserir_recursive(raiz, 3);
				inserir_recursive(raiz, 7);
				inserir_recursive(raiz, 12);
				inserir_recursive(raiz, 15);

				break;
			}
			case 3 : {
				//imprimir todos
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("::::::::::::::. IMPRIMIR ORDEM RECURSIVO .::::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
				show_ordem_recursive(raiz);
				printf("\n\n");
				system("pause");
				break;
			}
			case 4 : {
				//imprimir todos
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("::::::::::::::. IMPRIMIR PRE-ORDEM RECURSIVO .::::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
				show_preordem_recursive(raiz);
				printf("\n\n");
				system("pause");
				break;
			}
			case 5 : {
				//imprimir todos
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("::::::::::::::. IMPRIMIR POS-ORDEM RECURSIVO .::::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
				show_posordem_recursive(raiz);
				printf("\n\n");
				system("pause");
				break;
			}
			case 6 : {
				//deletar
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("::::::::::::::::::. DELETAR .:::::::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
				show_ordem_recursive(raiz);
				
				int valor;
				
				printf("\n\nDigite o valor que deseja deletar: ");
				scanf("%i", valor);
				
				delete_raiz(raiz, valor);
				break;
			}
			case 7 : {
				system("cls");
				printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("::::::::::::::::::. TRABALHO ED II - JOSE FERREIRA - IMPRIMIR NOS DO TIPO RAIZ .:::::::::::::::::\n");
				printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
				imprimir_nos_tipo_raiz(raiz);
				printf("\n\n");
				system("pause");
				
				break;
			}
			case 8 : {
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("::::::::::::::::::. TRABALHO ED II - JOSE FERREIRA - NUMERO E SEU DOBRO .:::::::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
				int numero, dobro, n=0, nd=0;
				
				printf("Informe o numero: ");
				scanf("%d", &numero);
				
				dobro = numero * 2;
				
				n = imprimir_numero_e_dobro(raiz, numero, dobro, n);
				if(n == 1) {
					printf("\nO numero informado ( %i ) consta na arvore, mas seu dobro ( %i ) NAO consta!\n", numero, dobro);
				}
				else if(n == 2) {
					printf("\nO numero informado ( %i ) e seu dobro ( %i ) CONSTAM na arvore!\n", numero, dobro);
				}
				else {
					printf("\nO numero informado ( %i ) NAO consta na arvore!\n", numero);
				}
				
				printf("\n\n");
				system("pause");
				
				break;
			}
			case 0 : {
				//sair
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("::::::::::::::. SAINDO DO MENU .::::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				printf("\tSAINDO...\n");
								
				exit(1);
				break;
			}
		}
	}
	
	system("pause");
}

int main() {
	cad *raiz = (cad *)malloc(sizeof(cad));
	raiz -> prox = NULL;
	raiz -> ant = NULL;
	raiz -> valor = NULL;
	
	menu(raiz);
}

