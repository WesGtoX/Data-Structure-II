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
	int dado[5];
};
typedef struct cadastro cad;

//struct tablehash {
//	struct tablehash *prox;
//};
//typedef struct tablehash hash[5];

//INSERIR RECURSIVO
//void inserir_recursive(cad *raiz, int valor, char name) {
void inserir_recursive(cad *raiz, cad *HASH, char name[50]) {
	cad *novo = (cad *)malloc(sizeof(cad));
	novo -> ant = NULL;
	novo -> prox = NULL;
//	novo -> valor = valor;
	strcpy(novo -> name, name);

	if(strcmp(raiz -> name, "") == 0) {
		strcpy(raiz -> name, name);
		raiz = &HASH[0];
	}
	else {
		if(strcmp(raiz -> name, name) > 0 && raiz -> ant == NULL) {
			raiz -> ant = novo;
		}
		else if(strcmp(raiz -> name, name) > 0 && raiz -> ant != NULL) {
			inserir_recursive(raiz -> ant, HASH, name);
		}
		else if(strcmp(raiz -> name, name) < 0 && raiz -> prox == NULL) {
			raiz -> prox = novo;
		}
		else if(strcmp(raiz -> name, name) < 0 && raiz -> prox != NULL) {
			inserir_recursive(raiz -> prox, HASH, name);
		}
	}
}

void hash_table(cad *raiz, cad *HASH, char name[50]) {
	//	65 66 67 68 69
	//	70 71 72 73 74
	//	75 76 77 78 79
	//	80 81 82 83 84
	//	85 86 87 88 89 90
	
	if((name[0]) <= 69) {
		inserir_recursive(raiz, HASH, name);
	}
	else if((name[0]) <= 74) {
		inserir_recursive(raiz, HASH, name);
	}
	else if((name[0]) <= 79) {
		inserir_recursive(raiz, HASH, name);
	}
	else if((name[0]) <= 84) {
		inserir_recursive(raiz, HASH, name);
	}
	else if((name[0]) <= 90) {
		inserir_recursive(raiz, HASH, name);
	}
	
}

//IMPRIMIR EM ORDEM
void show_ordem_recursive(cad *raiz, cad *HASH) {
//	cad *RAIZT = (cad *)malloc(sizeof(cad));
//	RAIZT = raiz;
	cad *RAIZT = &HASH[0];
	
//	printf("%s ", RAIZT -> name);
	printf("\nRAIZT = HASH\n");
	system("pause");
	
	while (RAIZT != NULL) {
		printf("\nENTROU NO LOOP\n");
		system("pause");
		RAIZT = RAIZT -> prox;
		printf("%s ", RAIZT -> name);
		printf("\nLOOP\n");
		system("pause");		printf("%s ", RAIZT -> name);
		RAIZT = RAIZT -> prox;
	
	printf("\nSAIU DO LOOP\n");
	system("pause");}
	

//    if(RAIZT != NULL){
//        show_ordem_recursive(RAIZT -> ant);
//        printf("%s ", RAIZT -> name);
//        
//     
	system("pause");
//    }
}

void menu(cad *raiz, cad *HASH) {
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
////				scanf("%d", &valor);
				fflush(stdin);
				gets(name);
//				
				inserir_recursive(raiz, HASH, name);
				
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
				
				show_ordem_recursive(raiz, HASH);
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
	
	int vet[5] = {0,1,2,3,4};
	
	cad *HASH[5];
	
	HASH[0] = NULL;
	HASH[1] = NULL;
	HASH[2] = NULL;
	HASH[3] = NULL;
	HASH[4] = NULL;
	
//	int *hash;
	
//	vet = &HASH[0];
	
//	cad *hash[0] = (cad *)malloc(sizeof(cad));
//	*dado = vet;
//	hash[0] -> prox = vet[0];
	
//	printf("%i", HASH[0]);
	
	
	menu(raiz, *HASH);
}

