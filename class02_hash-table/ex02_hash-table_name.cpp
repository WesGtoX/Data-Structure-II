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
	// int valor;
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
void inserir_recursive(cad *raiz, char name[50]) {
	printf("\n\nENTROU NO INSERIR\n\n");
	system("pause");
	
	cad *novo = (cad *)malloc(sizeof(cad));
	novo -> ant = NULL;
	novo -> prox = NULL;
//	novo -> valor = valor;
	strcpy(novo -> name, name);
	
	printf("\n\nraiz -> name = %s\n\n", raiz -> name);
	system("pause");
	printf("\n\nNOVO = nome\n\n");
	system("pause");

	if(strcmp(raiz -> name, "") == 0) {
		printf("\n\nENTROU NO IF inserir\n\n");
		system("pause");
		
		strcpy(raiz -> name, name);
		
		printf("\n\nraiz -> name = %s\n\n", raiz -> name);
		printf("\n\nSAIU DO IF inserir\n\n");
		system("pause");
	}
	else {
		printf("\n\nENTROU NO ELSE inserir\n\n");
		system("pause");
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
		printf("\n\nSAIU DO ELSE inserir\n\n");
		system("pause");
	}
}

void hash_table(cad *HASH[MAX], char name[50]) {
	cad *raiz;
	int i;
	
	if((name[0]) <= 69) {
		i = 0;
	}
	else if((name[0]) <= 74) {
		i = 1;
	}
	else if((name[0]) <= 79) {
		i = 2;
	}
	else if((name[0]) <= 84) {
		i = 3;
	}
	else if((name[0]) <= 90) {
		i = 4;
	}
	
//	printf("\n\ni = %i\n\n", i);
//	system("pause");
	
	if(HASH[i] -> prox == NULL) {
		printf("\nENTROU NO IF\n");
		system("pause");
		
		cad *raiz = (cad *)malloc(sizeof(cad));
		raiz -> prox = NULL;
		raiz -> ant = NULL;
		strcpy(raiz -> name, "");
		
		printf("\n\nraiz -> name = %s\n\n", raiz -> name);
		
		HASH[i] -> prox = raiz;
		
//		printf("\n\nname = %s\n\n", nome);
//		system("pause");
//				
//		printf("\n\nHASH[i] = %i\n\n", HASH[i] -> prox);
		printf("\nSAIU DO IF\n");
		system("pause");
	}
	else {
		cad *raiz = (cad *)malloc(sizeof(cad));
		raiz = HASH[i] -> prox;
	}
	
//	printf("\n\nname = %s\n\n", nome);
//	system("pause");
	
	inserir_recursive(raiz, name);
}

//IMPRIMIR EM ORDEM
//void show_ordem_recursive(cad *HASH) {
//	cad *RAIZT = (cad *)malloc(sizeof(cad));
//	RAIZT = raiz;
//	// cad *RAIZT = HASH[0];
//
//    if(RAIZT != NULL){
//        show_ordem_recursive(RAIZT -> ant);
//        printf("%s ", RAIZT -> name);
//        
//        show_ordem_recursive(RAIZT -> prox);
//    }
//}

void menu(cad *HASH[MAX]) {
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
				
				printf("Informe o nome: ");
//				scanf("%d", &valor);
				fflush(stdin);
				gets(name);

				hash_table(HASH, name);
				
				// AUTO INSERT
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
				
//				show_ordem_recursive(HASH);
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

