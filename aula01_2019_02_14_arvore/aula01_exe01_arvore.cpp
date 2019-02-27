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

void inserir(cad *raiz) {
	cad *novo = (cad *)malloc(sizeof(cad));
	
	novo -> ant = NULL;
	novo -> prox = NULL;
	novo -> valor = NULL;
	
	if(raiz -> valor == NULL) {
		printf("inserir raiz\n\n");
		printf("Informe o valor: ");
		scanf("%d", &raiz -> valor);
	}
	else {
		printf("inserir novo\n\n");
		printf("Informe o valor: ");
		scanf("%d", &novo -> valor);
		
		printf("novo %i\n\n", novo -> valor);
		system("pause");
	}
	
	printf("raiz %i\n", raiz -> valor);
	printf("raiz ant %i\n", raiz -> ant);
	printf("raiz prox %i\n", raiz -> prox);
	system("pause");

	if(raiz -> ant == NULL && novo -> valor != NULL && novo < raiz) {
		raiz -> ant = novo;
		printf("OK-02\n\n");
		
		printf("raiz %i\n", raiz -> valor);
		printf("raiz ant %i\n", raiz -> ant -> valor);
		printf("raiz prox %i\n", raiz -> prox -> valor);
		system("pause");
	}
	else if(raiz -> prox == NULL && novo -> valor != NULL && novo > raiz) {
		raiz -> prox = novo;
		printf("OK-03\n\n");
		
		printf("raiz %i\n", raiz -> valor);
		printf("raiz ant %i\n", raiz -> ant -> valor);
		printf("raiz prox %i\n", raiz -> prox -> valor);
		system("pause");
	}

//	if(novo < raiz) {		//add on left to the tree
//		cad *TEMP = raiz -> ant;
//
//		while(novo < TEMP && TEMP -> ant != NULL) {
//			TEMP = TEMP -> ant;
//
//			while(novo > TEMP && TEMP -> prox != NULL) {
//				TEMP = TEMP -> prox;
//			}
//		}
//
//		if(TEMP -> ant == NULL) {
//			TEMP -> ant = novo;
//		}
//		else if(TEMP -> prox == NULL) {
//			TEMP -> prox = novo;
//		}
//	}
//	else if(novo > raiz) {		//add on right to the tree
//		cad *TEMP = raiz -> prox;
//
//		while(novo < TEMP && TEMP -> ant != NULL) {
//			TEMP = TEMP -> ant;
//
//			while(novo > TEMP && TEMP -> prox != NULL) {
//				TEMP = TEMP -> prox;
//			}
//		}
//
//		if(TEMP -> ant == NULL) {
//			TEMP -> ant = novo;
//		}
//		else if(TEMP -> prox == NULL) {
//			TEMP -> prox = novo;
//		}
//	}
}

void menu(cad *raiz) {
	int opcao, i=0;
	
	system("cls");
	
	while(i == 0) {
		system("cls");
		printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf(":::::::::::::::::::. MENU .:::::::::::::::::::\n");
		printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
		
		printf("\n1 - Inserir");
		printf("\n2 - Imprimir Todos");
		printf("\n0 - Sair");
		
		printf("\n\nEscolha uma opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao) {
			case 1 : {
				//inserir fim
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf(":::::::::::::. INSERIR NO INICIO .::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
				inserir(raiz);
				break;
			}
			case 2 : {
				//imprimir todos
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("::::::::::::::. IMPRIMIR TODOS .::::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
//				show_all(raiz);
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

