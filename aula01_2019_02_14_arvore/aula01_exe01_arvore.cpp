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

void inserir(cad *raiz, int numero) {
	cad *novo = (cad *)malloc(sizeof(cad));
	
	novo -> ant = NULL;
	novo -> prox = NULL;
	novo -> valor = NULL;
	
	if(raiz -> valor == NULL) {
		printf("\ninserir raiz\n");
//		printf("Informe o valor: ");
//		scanf("%d", &raiz -> valor);
		raiz -> valor = numero;
		
		printf("raiz %i\n\n", raiz -> valor);
	}
	else {
		printf("\ninserir novo\n");
//		printf("Informe o valor: ");
//		scanf("%d", &novo -> valor);
		novo -> valor = numero;
		
		printf("novo %i\n\n", novo -> valor);
	}
	
//	printf("OK-01\n\n");									//================== PRINT TEST ==================
//	printf("raiz %i\n", raiz -> valor);						//================== PRINT TEST ==================
////	printf("raiz ant %i\n", raiz -> ant -> valor);			//================== PRINT TEST ==================
////	printf("raiz prox %i\n", raiz -> prox -> valor);		//================== PRINT TEST ==================
//	system("pause");

	if(raiz -> ant == NULL && novo -> valor != NULL && novo -> valor < raiz -> valor) {
		printf("novo ESQ %i\n", novo -> valor);
		raiz -> ant = novo;
//		printf("OK-02\n\n");		//================== PRINT TEST ==================
		
//		printf("raiz %i\n", raiz -> valor);						//================== PRINT TEST ==================
//		printf("raiz ant %i\n", raiz -> ant -> valor);			//================== PRINT TEST ==================
////		printf("raiz prox %i\n", raiz -> prox -> valor);		//================== PRINT TEST ==================
//		system("pause");
	}
	else if(raiz -> prox == NULL && novo -> valor != NULL && novo -> valor > raiz -> valor) {
		printf("novo DIR %i\n", novo -> valor);
		raiz -> prox = novo;
//		printf("OK-03\n\n");		//================== PRINT TEST ==================
		
//		printf("raiz %i\n", raiz -> valor);					//================== PRINT TEST ==================
////		printf("raiz ant %i\n", raiz -> ant -> valor);		//================== PRINT TEST ==================
//		printf("raiz prox %i\n", raiz -> prox -> valor);	//================== PRINT TEST ==================
//		system("pause");
	}
	else if(novo -> valor < raiz -> valor && raiz -> ant != NULL) {		//add on left to the tree
		printf("LOOP OK-01\n\n");		//================== PRINT TEST ==================
		system("pause");
		cad *TEMP = raiz -> ant;
		printf("TEMP %i ", TEMP -> valor);
		system("pause");

		while(novo -> valor < TEMP -> valor && TEMP -> ant != NULL) {
			printf("LOOP OK-01-02\n\n");		//================== PRINT TEST ==================
			system("pause");
			printf("ANTES %i ", TEMP -> valor);
			system("pause");
			TEMP = TEMP -> ant;
			printf("DEPOIS %i\n", TEMP -> valor);
			system("pause");

			while(novo -> valor > TEMP -> valor && TEMP -> prox != NULL) {
				printf("LOOP OK-01-03\n\n");		//================== PRINT TEST ==================
				system("pause");
				printf("ANTES %i ", TEMP -> valor);
				system("pause");
				TEMP = TEMP -> prox;
				printf("DEPOIS %i\n", TEMP -> valor);
				system("pause");
			}
		}

		if(TEMP -> ant == NULL) {
			printf("IF OK\n\n");		//================== PRINT TEST ==================
			system("pause");
			printf("ANTES %i ", TEMP -> valor);
			TEMP -> ant = novo;
			printf("DEPOIS %i\n", TEMP -> ant -> valor);
		}
		else if(TEMP -> prox == NULL) {
			printf("ELSE OK\n\n");		//================== PRINT TEST ==================
			system("pause");
			printf("ANTES %i ", TEMP -> valor);
			system("pause");
			TEMP -> prox = novo;
			printf("DEPOIS %i\n", TEMP -> prox -> valor);
			system("pause");
		}
	}
	else if(novo -> valor > raiz -> valor && raiz -> prox != NULL) {		//add on right to the tree
		printf("LOOP OK-02\n\n");		//================== PRINT TEST ==================
		system("pause");
		cad *TEMP = raiz -> prox;
		printf("TEMP %i ", TEMP -> valor);
		system("pause");

		while(novo -> valor < TEMP -> valor && TEMP -> ant != NULL) {
			printf("LOOP OK-02-02\n\n");		//================== PRINT TEST ==================
			system("pause");
			printf("ANTES %i ", TEMP -> valor);
			system("pause");
			TEMP = TEMP -> ant;
			printf("DEPOIS %i\n", TEMP -> valor);
			system("pause");

			while(novo -> valor > TEMP -> valor && TEMP -> prox != NULL) {
				printf("LOOP OK-02-03\n\n");		//================== PRINT TEST ==================
				system("pause");
				printf("ANTES %i ", TEMP -> valor);
				system("pause");
				TEMP = TEMP -> prox;
				printf("DEPOIS %i\n", TEMP -> valor);
				system("pause");
			}
		}

		if(TEMP -> ant == NULL) {
			printf("IF OK\n\n");		//================== PRINT TEST ==================
			system("pause");
			printf("ANTES %i ", TEMP -> valor);
			TEMP -> ant = novo;
			printf("DEPOIS %i\n", TEMP -> ant -> valor);
		}
		else if(TEMP -> prox == NULL) {
			printf("ELSE OK\n\n");		//================== PRINT TEST ==================
			system("pause");
			printf("ANTES %i ", TEMP -> valor);
			TEMP -> prox = novo;
			printf("DEPOIS %i\n", TEMP -> prox -> valor);
			system("pause");
		}
	}
	
	system("pause");
}

void show_all(cad *raiz) {
	cad *TEMP1;
	cad *TEMP2;
	cad *TEMP3;
	cad *TEMP4;
	cad *TEMP5;
	cad *TEMP6;
	cad *TEMP7;
	cad *TEMP8;
	
	TEMP1 = raiz -> ant -> ant;
	TEMP2 = raiz -> ant;
	TEMP3 = raiz -> ant -> prox;
	TEMP4 = raiz;
//	
//	TEMP5 = raiz -> prox -> ant;
//	TEMP6 = raiz -> prox;
//	TEMP7 = raiz -> prox -> prox -> ant;
//	TEMP8 = raiz -> prox -> prox;
//	
//	
	printf("%i ", TEMP1 -> valor);
	printf("%i ", TEMP2 -> valor);
	printf("%i ", TEMP3 -> valor);
	printf("%i ", TEMP4 -> valor);
//	
//	printf("%i ", TEMP5 -> valor);
//	printf("%i ", TEMP6 -> valor);
//	printf("%i ", TEMP7 -> valor);
//	printf("%i ", TEMP8 -> valor);
	
		
//	printf("%i ", TEMP2 -> valor);
//	printf("%i ", TEMP4 -> valor);
//	printf("%i ", TEMP6 -> valor);
	
	

//	while(TEMP -> ant != NULL) {
//		TEMP = TEMP -> ant;
//		printf("%i", TEMP -> valor);
//	}
	
//	if(TEMP -> ant == NULL) {
//	printf("%i", TEMP -> valor);
//	}
	
	
	
//	printf("raiz %i\n", raiz -> valor);					//================== PRINT TEST ==================
//	printf("raiz ant %i\n", raiz -> ant -> valor);		//================== PRINT TEST ==================
//	printf("raiz prox %i\n", raiz -> prox -> valor);	//================== PRINT TEST ==================
	printf("\n");
	system("pause");
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
				inserir(raiz, 14);
				inserir(raiz, 10);
				inserir(raiz, 6);
				inserir(raiz, 2);
				inserir(raiz, 7);
				inserir(raiz, 12);
				inserir(raiz, 30);
				inserir(raiz, 28);
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
	raiz -> valor = NULL;
	
	menu(raiz);
}

