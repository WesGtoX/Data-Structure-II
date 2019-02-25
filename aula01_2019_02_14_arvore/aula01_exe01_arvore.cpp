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

	printf("Informe o valor: ");
	scanf("%d", &novo -> valor);

	novo -> prox = NULL;

	if(raiz == NULL) {
		raiz = novo;
	}
	else if(raiz -> ant == NULL && raiz < novo) {
		raiz -> ant = novo;
	}
	else if(raiz -> prox == NULL) {
		raiz -> prox = novo;
	}


	if(novo < raiz) {		//add on left to the tree
		cad *TEMP = raiz -> ant;

		while(novo < TEMP && TEMP -> ant != NULL)) {
			TEMP = TEMP -> ant;

			while(novo > TEMP && TEMP -> prox != NULL)) {
				TEMP = TEMP -> prox;
			}
		}

		if(TEMP -> ant == NULL) {
			TEMP -> ant = novo;
		}
		else if(TEMP -> prox == NULL) {
			TEMP -> prox = novo;
		}
	}
	else if(novo > raiz) {		//add on right to the tree
		cad *TEMP = raiz -> prox;

		while(novo < TEMP && TEMP -> ant != NULL)) {
			TEMP = TEMP -> ant;

			while(novo > TEMP && TEMP -> prox != NULL)) {
				TEMP = TEMP -> prox;
			}
		}

		if(TEMP -> ant == NULL) {
			TEMP -> ant = novo;
		}
		else if(TEMP -> prox == NULL) {
			TEMP -> prox = novo;
		}
	}
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
				
				show_all(raiz);
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
}

