//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 8

//data struct declare
struct cadastro {
	struct cadastro *prox;
	struct cadastro *ant;
	int valor;
//	char name[50];
};
typedef struct cadastro cad;

// 65 66 67 68 69  // 70 71 72 73 74  // 75 76 77 78 79  // 80 81 82 83 84  // 85 86 87 88 89 90

cad *HASH[MAX];

// INICIALIZAR HASH
void initialize_hash(cad *HASH[MAX]) {
	int i;
	for(i=0; i < MAX; i++) {
		HASH[i] = (cad *)malloc(sizeof(cad));
		HASH[i] -> prox = NULL;
        HASH[i] -> ant = NULL;
        HASH[i] -> valor = NULL;
	}
}

int calculate_hash(int value) {
    int index;
    index = value % MAX;
    return index;
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

// FUNÇÃO DE HASH VERIFICA A POSIAÇÃO E INSERE UM VALOR
void hash_table(cad *HASH[MAX], int valor) {
    cad *raiz = (cad *)malloc(sizeof(cad));

    int i = calculate_hash(valor);

	if(HASH[i] -> prox == NULL) {
		raiz -> prox = NULL;
		raiz -> ant = NULL;
		raiz -> valor = NULL;
		HASH[i] -> prox = raiz;
	}
	else {
        raiz -> prox = NULL;
        raiz -> ant = NULL;
		raiz = HASH[i] -> prox;
	}
	inserir_recursive(raiz, valor);
}

//IMPRIMIR EM ORDEM
void show_ordem_recursive(cad *raiz) {
	cad *RAIZT = (cad *)malloc(sizeof(cad));
	RAIZT = raiz;

    if(RAIZT != NULL){
        show_ordem_recursive(RAIZT -> ant);
        printf("%i  ", RAIZT -> valor);

        show_ordem_recursive(RAIZT -> prox);
    }
}

void menu(cad *HASH[MAX]) {
	int opcao, i=0;
	int valor;
	//char name[50];
	
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
				
//				printf("Informe o valor: ");
//				scanf("%d", &valor);
//				printf("Informe o nome: ");
//				fflush(stdin);
//				gets(name);
//
//				hash_table(HASH, name);
//				hash_table(HASH, valor);
				
				// AUTO INSERT
                hash_table(HASH, 4); hash_table(HASH, 3); hash_table(HASH, 1);  hash_table(HASH, 6); hash_table(HASH, 7);
                hash_table(HASH, 2); hash_table(HASH, 9); hash_table(HASH, 10); hash_table(HASH, 8); hash_table(HASH, 5);
				break;
			}
			case 2 : {
				//imprimir todos
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("::::::::::::::. IMPRIMIR ORDEM RECURSIVO .::::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
				for(int i=0; i < MAX; i++) {
                    printf("Index %i --->\t", i);
				    show_ordem_recursive(HASH[i] -> prox);
                    printf("\n--------------------------------------------------------");
				    printf("\n\n");
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
	initialize_hash(HASH);
	menu(HASH);
}

