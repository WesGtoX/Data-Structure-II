//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 5

//data struct declare
struct cadastro {
	struct cadastro *prox;
	struct cadastro *ant;
	int valor;
	char name[50];
};
typedef struct cadastro cad;

// 65 66 67 68 69  // 70 71 72 73 74  // 75 76 77 78 79  // 80 81 82 83 84  // 85 86 87 88 89 90

cad *HASH[MAX];

void initialize_hash(cad *HASH[MAX]) {
	int i;
	for(i=0; i <= 4; i++) {
		HASH[i] = (cad *)malloc(sizeof(cad));
		HASH[i] -> prox = NULL;
//		printf("Teste %i\n",i);
	}
}

//INSERIR RECURSIVO
//void inserir_recursive(cad *raiz, int valor, char name) {
void inserir_recursive(cad *raiz, int valor) {
	// printf("\nENTROU NO INSERIR\n");
	// system("pause");
	
	cad *novo = (cad *)malloc(sizeof(cad));
	novo -> ant = NULL;
	novo -> prox = NULL;
	novo -> valor = valor;
	
	// printf("\nNOVO -> valor = %d\n", novo -> valor);
	// system("pause");
	
	// printf("\nvalor = %d\n", valor);
	// system("pause");
	
//	printf("\nraiz -> valor = %d\n", raiz -> valor);
//	system("pause");
	
	if(raiz -> valor == NULL) {
		// printf("\nENTROU NO IF\n");
		// system("pause");
		
		raiz -> valor = valor;
		// printf("\nraiz -> name = %d\n", raiz -> valor);
		
		// printf("\nSAIU DO IF\n");
		// system("pause");
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

void hash_table(cad *HASH[MAX], int valor) {
	cad *raiz = (cad *)malloc(sizeof(cad));
	int i;
	
	if(valor <= 5) {
		i = 0;
	}
	else if(valor <= 10) {
		i = 1;
	}
	else if(valor <= 15) {
		i = 2;
	}
	else if(valor <= 20) {
		i = 3;
	}
	else if(valor <= 25) {
		i = 4;
	}
	
//	printf("\n\ni = %i\n\n", i);
//	system("pause");
	
	if(HASH[i] -> prox == NULL) {
		// printf("\nENTROU NO IF\n");
		// system("pause");
		
		raiz -> prox = NULL;
		raiz -> ant = NULL;
		raiz -> valor = NULL;
		
//		printf("\n\nraiz -> name = %d\n\n", raiz -> valor);
		
		HASH[i] -> prox = raiz;
		
//		printf("\n\nname = %s\n\n", nome);
//		system("pause");
//				
		// printf("\nraiz -> prox = %i\n", raiz -> prox);
		// printf("\nraiz -> ant = %i\n", raiz -> ant);
		// printf("\nraiz -> valor = %i\n", raiz -> valor);
		// printf("\nSAIU DO IF\n");
		// system("pause");
	}
	else {
		cad *raiz = (cad *)malloc(sizeof(cad));
		raiz = HASH[i] -> prox;
	}
	
//	printf("\n\nname = %s\n\n", nome);
//	system("pause");
	
	inserir_recursive(raiz, valor);
}

//IMPRIMIR EM ORDEM
void show_ordem_recursive(cad *raiz) {
	cad *RAIZT = (cad *)malloc(sizeof(cad));
	RAIZT = raiz;
	// cad *RAIZT = HASH[0];

    if(RAIZT != NULL){
        show_ordem_recursive(RAIZT -> ant);
        printf("%s ", RAIZT -> name);
        
        show_ordem_recursive(RAIZT -> prox);
    }
}

void menu(cad *HASH[MAX]) {
	int opcao, i=0;
	int valor;
//	char name[50];
	
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
////				printf("Informe o nome: ");
////				fflush(stdin);
////				gets(name);
//
////				hash_table(HASH, name);
//				hash_table(HASH, valor);
				
				// AUTO INSERT
				hash_table(HASH, 3);
				hash_table(HASH, 1);
				hash_table(HASH, 2);
				hash_table(HASH, 4);
//				inserir_recursive(raiz, HASH, "Sophia");
//				inserir_recursive(raiz, HASH, "Helena");
//				inserir_recursive(raiz, HASH, "Valentina");
//				inserir_recursive(raiz, HASH, "Laura");
//				inserir_recursive(raiz, HASH, "Alice");
//				inserir_recursive(raiz, hash, "Isabella");
//				inserir_recursive(raiz, hash, "Manuela");
//				inserir_recursive(raiz, hash, "Julia");
//				inserir_recursive(raiz, hash, "Heloisa");
//				inserir_recursive(raiz, hash, "Luiza");
				break;
			}
			case 2 : {
				//imprimir todos
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("::::::::::::::. IMPRIMIR ORDEM RECURSIVO .::::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
//				printf("\n\nHASH[i] -> prox -> valor = %i\n\n", HASH[0] -> prox -> valor);
				printf("\nHASH[i] -> tree:\n");
				printf("\n -> %i\n", HASH[0] -> prox -> valor);
				system("pause");
				printf("\n -> %i\n", HASH[0] -> prox -> prox -> valor);
				system("pause");
				printf("\n -> %i\n", HASH[0] -> prox -> prox -> prox -> valor);
				system("pause");
				printf("\n -> %i\n", HASH[0] -> prox -> prox -> prox -> prox -> valor);
				system("pause");
				
//				show_ordem_recursive(HASH[0] -> prox);
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

