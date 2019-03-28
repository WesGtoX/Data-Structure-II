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

void inserir(cad *raiz, int numero) {																			// AUTO INSERT
// void inserir(cad *raiz) {																						// AUTO INSERT
	cad *novo = (cad *)malloc(sizeof(cad));
	
	novo -> ant = NULL;
	novo -> prox = NULL;
	novo -> valor = NULL;
	
	if(raiz -> valor == NULL) {
		// printf("\ninserir raiz\n");																			// AUTO INSERT
		// printf("Informe o valor: ");																			// AUTO INSERT
		// scanf("%d", &raiz -> valor);																			// AUTO INSERT
		raiz -> valor = numero;																					// AUTO INSERT
		
		// printf("raiz %i\n\n", raiz -> valor);																//=== PRINT TEST ===
	}
	else {
		// printf("\ninserir novo\n");																			// AUTO INSERT
		// printf("Informe o valor: ");																			// AUTO INSERT
		// scanf("%d", &novo -> valor);																			// AUTO INSERT
		novo -> valor = numero;																					// AUTO INSERT
		
		// printf("novo %i\n\n", novo -> valor);																//=== PRINT TEST ===
	}
	
	// printf("OK-01\n\n");																					//=== PRINT TEST ===
	// printf("raiz %i\n", raiz -> valor);																		//=== PRINT TEST ===
	// system("pause");																						//=== PRINT TEST ===

	if(raiz -> ant == NULL && novo -> valor != NULL && novo -> valor < raiz -> valor) {
		// printf("novo ESQ %i\n", novo -> valor);																//=== PRINT TEST ===
		raiz -> ant = novo;
		// printf("OK-02\n\n");																				//=== PRINT TEST ===
		
		// printf("raiz %i\n", raiz -> valor);																	//=== PRINT TEST ===
		// system("pause");																					//=== PRINT TEST ===
	}
	else if(raiz -> prox == NULL && novo -> valor != NULL && novo -> valor > raiz -> valor) {
		// printf("novo DIR %i\n", novo -> valor);																//=== PRINT TEST ===
		raiz -> prox = novo;
		// printf("OK-03\n\n");																				//=== PRINT TEST ===
		
		// printf("raiz %i\n", raiz -> valor);																	//=== PRINT TEST ===
		// system("pause");																					//=== PRINT TEST ===
	}
	else if(novo -> valor < raiz -> valor && raiz -> ant != NULL) {		//add on left to the tree
		// printf("LOOP OK-01\n\n");																			//=== PRINT TEST ===
		// system("pause");																					//=== PRINT TEST ===
		cad *TEMP = raiz -> ant;
		// printf("TEMP %i ", TEMP -> valor);																	//=== PRINT TEST ===
		// system("pause");																					//=== PRINT TEST ===

		while(novo -> valor < TEMP -> valor && TEMP -> ant != NULL) {
			// printf("LOOP OK-01-02\n\n");																	//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
			// printf("ANTES %i ", TEMP -> valor);																//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
			TEMP = TEMP -> ant;
			// printf("DEPOIS %i\n", TEMP -> valor);															//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
		}
		
		while(novo -> valor > TEMP -> valor && TEMP -> prox != NULL) {
			// printf("LOOP OK-01-03\n\n");																	//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
			// printf("ANTES %i ", TEMP -> valor);																//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
			TEMP = TEMP -> prox;
			// printf("DEPOIS %i\n", TEMP -> valor);															//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
		}

		if(TEMP -> ant == NULL && novo -> valor < TEMP -> valor) {
			// printf("IF OK\n\n");																			//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
			// printf("ANTES %i ", TEMP -> valor);																//=== PRINT TEST ===
			TEMP -> ant = novo;
			// printf("DEPOIS %i\n", TEMP -> ant -> valor);													//=== PRINT TEST ===
		}
		else if(TEMP -> prox == NULL && novo -> valor > TEMP -> valor) {
			// printf("ELSE OK\n\n");																			//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
			// printf("ANTES %i ", TEMP -> valor);																//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
			TEMP -> prox = novo;
			// printf("DEPOIS %i\n", TEMP -> prox -> valor);													//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
		}
	}
	else if(novo -> valor > raiz -> valor && raiz -> prox != NULL) {		//add on right to the tree
		// printf("LOOP OK-02\n\n");																			//=== PRINT TEST ===
		// system("pause");																					//=== PRINT TEST ===
		cad *TEMP = raiz -> prox;
		// printf("TEMP %i ", TEMP -> valor);																	//=== PRINT TEST ===
		// system("pause");																					//=== PRINT TEST ===

		while(novo -> valor < TEMP -> valor && TEMP -> ant != NULL) {
			// printf("LOOP OK-02-02\n\n");																	//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
			// printf("ANTES %i ", TEMP -> valor);																//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
			TEMP = TEMP -> ant;
			// printf("DEPOIS %i\n", TEMP -> valor);															//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
		}
		
		while(novo -> valor > TEMP -> valor && TEMP -> prox != NULL) {
			// printf("LOOP OK-02-03\n\n");																	//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
			// printf("ANTES %i ", TEMP -> valor);																//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
			TEMP = TEMP -> prox;
			// printf("DEPOIS %i\n", TEMP -> valor);															//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
		}

		if(TEMP -> ant == NULL) {
			TEMP -> ant = novo;
		}
		else if(TEMP -> prox == NULL) {
			TEMP -> prox = novo;
		}

		if(TEMP -> ant == NULL && novo -> valor < TEMP -> valor) {
			// printf("IF OK\n\n");																			//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
			// printf("ANTES %i ", TEMP -> valor);																//=== PRINT TEST ===
			TEMP -> ant = novo;
			// printf("DEPOIS %i\n", TEMP -> ant -> valor);													//=== PRINT TEST ===
		}
		else if(TEMP -> prox == NULL && novo -> valor > TEMP -> valor) {
			// printf("ELSE OK\n\n");																			//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
			// printf("ANTES %i ", TEMP -> valor);																//=== PRINT TEST ===
			TEMP -> prox = novo;
			// printf("DEPOIS %i\n", TEMP -> prox -> valor);													//=== PRINT TEST ===
			// system("pause");																				//=== PRINT TEST ===
		}
	}
	
	// system("pause");																						//=== PRINT TEST ===
}

void show_all(cad *raiz) {
	
//	cad *RAIZT = (cad *)malloc(sizeof(cad));
//	RAIZT = raiz;
//	
//		
//	if(RAIZT -> ant != NULL) {		//5/2/
//		show_all(RAIZT -> ant);
//		printf("%i ", RAIZT -> valor);
//	}
//	else if(RAIZT -> ant == NULL) {
//		printf("%i ", RAIZT -> valor);
//	}
//	else if(RAIZT -> prox != NULL) {
//		show_all(RAIZT -> prox);
//	}
//	
//	
//	if(RAIZT -> prox != NULL) {
//		show_all(RAIZT -> prox);
//		printf("%i ", RAIZT -> valor);
//	}
//	else {
////		printf("%i ", RAIZT -> valor);
//	}

  
    if(raiz != NULL){
        show_all(raiz->ant);
        printf("%i ", raiz->valor);
        show_all(raiz->prox);
    }
	
	
//	system("pause");
	
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
				
//				inserir(raiz);																				// AUTO INSERT
				
				inserir(raiz, 3);
				inserir(raiz, 4);
				inserir(raiz, 8);
				inserir(raiz, 1);
				inserir(raiz, 6);
				inserir(raiz, 10);
				inserir(raiz, 2);
				inserir(raiz, 7);
				inserir(raiz, 9);
				inserir(raiz, 5);

				// inserir(raiz, );


//				printf("%i ", raiz -> ant -> prox -> valor);
				system("pause");
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
