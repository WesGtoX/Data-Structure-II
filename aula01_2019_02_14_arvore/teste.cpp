No *MaiorDireita(No **no) {
    if((*no) -> direita != NULL) {
       return MaiorDireita(&(*no) -> direita);
    }
    else {
       No *aux = *no;
       
       /* se nao houver essa verificacao, esse não vai 
	   perder todos os seus filhos da esquerda! */
       if((*no) -> esquerda != NULL) {
            *no = (*no) -> esquerda;
        }
        else {
            *no = NULL;
            return aux;
        }
    }
}

No *MenorEsquerda(No **no) {
    if((*no) -> esquerda != NULL) {
       return MenorEsquerda(&(*no) -> esquerda);
    }
    else {
        No *aux = *no; 

        /* se nao houver essa verificacao, esse não vai 
		perder todos os seus filhos da direita! */
        if((*no) -> direita != NULL) {
          *no = (*no) -> direita;
        }
        else {
            *no = NULL;
        }
        return aux;
    }
}

void remover(No **pRaiz, int numero) {

    if(numero < (*pRaiz) -> numero) {
        remover(&(*pRaiz)  ->  esquerda, numero);
    }
    else {
        if(numero > (*pRaiz) -> numero) {
            remover(&(*pRaiz) -> direita, numero);
        }
        else {
        	// se nao eh menor nem maior, logo, eh o numero que estou procurando! :)
        	
        	// quem programar no Embarcadero vai ter que declarar o pAux no inicio do void! :[
            No *pAux = *pRaiz;	
            
            // se nao houver filhos...
            if (((*pRaiz) -> esquerda == NULL) && ((*pRaiz) -> direita == NULL)) {
                free(pAux);
                (*pRaiz) = NULL; 
               }
            else {     // so tem o filho da direita
                if((*pRaiz) -> esquerda == NULL) {
                    (*pRaiz) = (*pRaiz) -> direita;
                    pAux -> direita = NULL;
                    free(pAux); pAux = NULL;
                }
                else {      //so tem filho da esquerda
                    if ((*pRaiz) -> direita == NULL){
                        (*pRaiz) = (*pRaiz) -> esquerda;
                        pAux -> esquerda = NULL;
                        free(pAux); pAux = NULL;
                        }
                    else {
                    	//Escolhi fazer o maior filho direito da subarvore esquerda.
                    	//se vc quiser usar o Menor da esquerda, so o que mudaria seria isso:
                        pAux = MaiorDireita(&(*pRaiz) -> esquerda);
                        //pAux = MenorEsquerda(&(*pRaiz) -> direita);
                        pAux -> esquerda = (*pRaiz) -> esquerda;
                        pAux -> direita = (*pRaiz) -> direita;
                        (*pRaiz) -> esquerda = (*pRaiz) -> direita = NULL;
                        free((*pRaiz));  *pRaiz = pAux;  pAux = NULL;   
                    }
                }
            }
        }
    }
}

