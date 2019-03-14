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

//void imprimir(cad *raiz);

void inserir(cad *raiz, int numero) {
	cad *novo = (cad *)malloc(sizeof(cad));
	
	novo -> ant = NULL;
	novo -> prox = NULL;
	novo -> valor = NULL;
	
	if(raiz -> valor == NULL) {
//		printf("\ninserir raiz\n");
//		printf("Informe o valor: ");
//		scanf("%d", &raiz -> valor);
		raiz -> valor = numero;
		
//		printf("raiz %i\n\n", raiz -> valor);
	}
	else {
//		printf("\ninserir novo\n");
//		printf("Informe o valor: ");
//		scanf("%d", &novo -> valor);
		novo -> valor = numero;
		
//		printf("novo %i\n\n", novo -> valor);
	}
	
//	printf("OK-01\n\n");									//================== PRINT TEST ==================
//	printf("raiz %i\n", raiz -> valor);						//================== PRINT TEST ==================
////	printf("raiz ant %i\n", raiz -> ant -> valor);			//================== PRINT TEST ==================
////	printf("raiz prox %i\n", raiz -> prox -> valor);		//================== PRINT TEST ==================
//	system("pause");

	if(raiz -> ant == NULL && novo -> valor != NULL && novo -> valor < raiz -> valor) {
//		printf("novo ESQ %i\n", novo -> valor);
		raiz -> ant = novo;
//		printf("OK-02\n\n");		//================== PRINT TEST ==================
		
//		printf("raiz %i\n", raiz -> valor);						//================== PRINT TEST ==================
//		printf("raiz ant %i\n", raiz -> ant -> valor);			//================== PRINT TEST ==================
////		printf("raiz prox %i\n", raiz -> prox -> valor);		//================== PRINT TEST ==================
//		system("pause");
	}
	else if(raiz -> prox == NULL && novo -> valor != NULL && novo -> valor > raiz -> valor) {
//		printf("novo DIR %i\n", novo -> valor);
		raiz -> prox = novo;
//		printf("OK-03\n\n");		//================== PRINT TEST ==================
		
//		printf("raiz %i\n", raiz -> valor);					//================== PRINT TEST ==================
////		printf("raiz ant %i\n", raiz -> ant -> valor);		//================== PRINT TEST ==================
//		printf("raiz prox %i\n", raiz -> prox -> valor);	//================== PRINT TEST ==================
//		system("pause");
	}
	else if(novo -> valor < raiz -> valor && raiz -> ant != NULL) {		//add on left to the tree
//		printf("LOOP OK-01\n\n");		//================== PRINT TEST ==================
//		system("pause");
		cad *TEMP = raiz -> ant;
//		printf("TEMP %i ", TEMP -> valor);
//		system("pause");

		while(novo -> valor < TEMP -> valor && TEMP -> ant != NULL) {
//			printf("LOOP OK-01-02\n\n");		//================== PRINT TEST ==================
//			system("pause");
//			printf("ANTES %i ", TEMP -> valor);
//			system("pause");
			TEMP = TEMP -> ant;
//			printf("DEPOIS %i\n", TEMP -> valor);
//			system("pause");

			while(novo -> valor > TEMP -> valor && TEMP -> prox != NULL) {
//				printf("LOOP OK-01-03\n\n");		//================== PRINT TEST ==================
//				system("pause");
//				printf("ANTES %i ", TEMP -> valor);
//				system("pause");
				TEMP = TEMP -> prox;
//				printf("DEPOIS %i\n", TEMP -> valor);
//				system("pause");
			}
		}

		if(TEMP -> ant == NULL) {
//			printf("IF OK\n\n");		//================== PRINT TEST ==================
//			system("pause");
//			printf("ANTES %i ", TEMP -> valor);
			TEMP -> ant = novo;
//			printf("DEPOIS %i\n", TEMP -> ant -> valor);
		}
		else if(TEMP -> prox == NULL) {
//			printf("ELSE OK\n\n");		//================== PRINT TEST ==================
//			system("pause");
//			printf("ANTES %i ", TEMP -> valor);
//			system("pause");
			TEMP -> prox = novo;
//			printf("DEPOIS %i\n", TEMP -> prox -> valor);
//			system("pause");
		}
	}
	else if(novo -> valor > raiz -> valor && raiz -> prox != NULL) {		//add on right to the tree
//		printf("LOOP OK-02\n\n");		//================== PRINT TEST ==================
//		system("pause");
		cad *TEMP = raiz -> prox;
//		printf("TEMP %i ", TEMP -> valor);
//		system("pause");

		while(novo -> valor < TEMP -> valor && TEMP -> ant != NULL) {
//			printf("LOOP OK-02-02\n\n");		//================== PRINT TEST ==================
//			system("pause");
//			printf("ANTES %i ", TEMP -> valor);
//			system("pause");
			TEMP = TEMP -> ant;
//			printf("DEPOIS %i\n", TEMP -> valor);
//			system("pause");

			while(novo -> valor > TEMP -> valor && TEMP -> prox != NULL) {
//				printf("LOOP OK-02-03\n\n");		//================== PRINT TEST ==================
//				system("pause");
//				printf("ANTES %i ", TEMP -> valor);
//				system("pause");
				TEMP = TEMP -> prox;
//				printf("DEPOIS %i\n", TEMP -> valor);
//				system("pause");
			}
		}

		if(TEMP -> ant == NULL) {
//			printf("IF OK\n\n");		//================== PRINT TEST ==================
//			system("pause");
//			printf("ANTES %i ", TEMP -> valor);
			TEMP -> ant = novo;
//			printf("DEPOIS %i\n", TEMP -> ant -> valor);
		}
		else if(TEMP -> prox == NULL) {
//			printf("ELSE OK\n\n");		//================== PRINT TEST ==================
//			system("pause");
//			printf("ANTES %i ", TEMP -> valor);
			TEMP -> prox = novo;
//			printf("DEPOIS %i\n", TEMP -> prox -> valor);
//			system("pause");
		}
	}
	
//	system("pause");
}

void show_all(cad *raiz) {
	
	cad *RAIZT = (cad *)malloc(sizeof(cad));
	RAIZT = raiz;
	
		
	if(RAIZT -> ant != NULL) {
		show_all(RAIZT -> ant);
	}
	else {
		printf("%i ", RAIZT -> valor);
	}
	
	
	if(RAIZT -> prox != NULL) {
		printf("%i ", RAIZT -> valor);
		show_all(RAIZT -> prox);
	}
//	else {
//		printf("%i ", RAIZT -> valor);
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
				
//				inserir(raiz);
				inserir(raiz, 5);
				inserir(raiz, 2);
				inserir(raiz, 1);
				inserir(raiz, 3);
				inserir(raiz, 4);
				inserir(raiz, 8);
				inserir(raiz, 7);
				inserir(raiz, 6);
				inserir(raiz, 9);
				inserir(raiz, 10);
//				inserir(raiz, 43);
//				inserir(raiz, 32);
//				inserir(raiz, 29);
//				inserir(raiz, 36);
//				inserir(raiz, 3);
				break;
			}
			case 2 : {
				//imprimir todos
				system("cls");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("::::::::::::::. IMPRIMIR TODOS .::::::::::::::\n");
				printf("::::::::::::::::::::::::::::::::::::::::::::::\n\n");
				
				show_all(raiz);
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

