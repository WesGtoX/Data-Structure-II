//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//data struct declare
struct cadastro {
	struct cadastro *prox;
	struct cadastro *ant;
//	int valor;
	char name[50];
};
typedef struct cadastro cad;

//INSERIR RECURSIVO
//void inserir_recursive(cad *raiz, int valor, char name) {
void inserir_recursive(cad *raiz, char name[50]) {
	cad *novo = (cad *)malloc(sizeof(cad));
	novo -> ant = NULL;
	novo -> prox = NULL;
//	novo -> valor = valor;
	strcpy(novo -> name, name);
	
	if(strcmp(raiz -> name, "") == 0) {
		strcpy(raiz -> name, name);
	}
	else {
		if(strcmp(raiz -> name, name) > 0 && raiz -> ant == NULL) {
			raiz -> ant = novo;
		}
		else if(strcmp(raiz -> name, name) > 0 && raiz -> ant != NULL) {
			inserir_recursive(raiz -> ant, name);
		}
		else if(strcmp(raiz -> name, name) < 0 && raiz -> prox == NULL) {
			raiz -> prox = novo;
		}
		else if(strcmp(raiz -> name, name) < 0 && raiz -> prox != NULL) {
			inserir_recursive(raiz -> prox, name);
		}
	}
}

void hash_table() {
	
}

//IMPRIMIR EM ORDEM
void show_ordem_recursive(cad *raiz) {
	cad *RAIZT = (cad *)malloc(sizeof(cad));
	RAIZT = raiz;

    if(RAIZT != NULL){
        show_ordem_recursive(RAIZT -> ant);
        printf("%s ", RAIZT -> name);
        
        show_ordem_recursive(RAIZT -> prox);
    }
}

void menu(cad *raiz) {
	int opcao, i=0;
	char name[50];
	
	system("cls");
	
	while(i == 0) {
		system("cls");
		printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf(":::::::::::::::::::. MENU .:::::::::::::::::::\n");
		printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
		
		printf("\n1 - Inserir Recursivo");
		printf("\n2 - Imprimir Ordem Recursivo");
		printf("\n0 - Sair");
		
		printf("\n\nEscolha uma opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao) {
			case 1 : {
				//inserir recursivo
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf(":::::::::::::. INSERIR RECURSIVO .::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
//				printf("Informe o nome: ");
////				scanf("%d", &valor);
//				fflush(stdin);
//				gets(name);
//				
//				inserir_recursive(raiz, name);
				
				// AUTO INSERT
				inserir_recursive(raiz, "Sophia");
				inserir_recursive(raiz, "Helena");
				inserir_recursive(raiz, "Valentina");
				inserir_recursive(raiz, "Laura");
				inserir_recursive(raiz, "Alice");
				inserir_recursive(raiz, "Isabella");
				inserir_recursive(raiz, "Manuela");
				inserir_recursive(raiz, "Julia");
				inserir_recursive(raiz, "Heloisa");
				inserir_recursive(raiz, "Luiza");
				break;
			}
			case 2 : {
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
	strcpy(raiz -> name, "");
	
	menu(raiz);
}

