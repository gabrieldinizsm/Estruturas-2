#include<stdio.h>
#include<stdlib.h>

struct arvore {
	int info;
	struct arvore* esquerda;
	struct arvore* direita;
	struct arvore* pai;
};

typedef struct arvore arvore;

arvore* criaArvoreVazia (void);

int checaArvoreVazia (arvore* arvore);

void liberaArvore (arvore* arvore);

arvore* insereNoIterativo (int valor, arvore* arv);

arvore* insereNoRecursivo (int valor, arvore* arv);

void imprimeCrescente (arvore* arv);

void showMenor (arvore* arv, int valor);

arvore* buscaValorIterativo (arvore* arv, int valor);

arvore* buscaValorRecursivo (arvore* arv, int valor);

arvore* buscaMenorValorIterativo (arvore* arv);

arvore* buscaMaiorValorAntesRaiz (arvore* arv); 

arvore* buscaPaiRecursivamente (arvore* arv, int valor);

main (){
	
	arvore* a = criaArvoreVazia ();
	
	a = insereNoIterativo (6, a);
	
	a =	insereNoIterativo (1, a);
	
	a = insereNoIterativo (5, a);
	
	a =	insereNoIterativo (3, a);
	
	a =	insereNoIterativo (8, a);
	
	a =	insereNoIterativo (4, a);
	
	a =	insereNoIterativo (2, a);
	
	a =	insereNoIterativo (9, a);
	
	a =	insereNoIterativo (7, a);

	imprimeCrescente (a);
	
	showMenor (a, 6);
	
	arvore* b = criaArvoreVazia ();
	
	b = buscaValorIterativo(a, 3);
	
	if (b != NULL)
		printf ("%d \n", b->info);
	
	b = buscaMenorValorIterativo(a);
	
	if (b != NULL)
		printf ("%d \n", b->info);
	
	liberaArvore (a);
	
	a = buscaMaiorValorAntesRaiz(a);
	
	printf ("%d \n", a->info);
	
	a = buscaPaiRecursivamente(a, 4);
	
	printf ("%d \n", a->info);
	
	system ("pause>NULL");

}

arvore* criaArvoreVazia (void){
	
	return NULL;
}

int checaArvoreVazia (arvore* arvore){
	
	return NULL == arvore;
}


void liberaArvore (arvore* arvore){
	
	if (!checaArvoreVazia(arvore)){
		liberaArvore (arvore-> esquerda);
		liberaArvore (arvore-> direita);
		free(arvore);
	}
}

arvore* insereNoIterativo (int valor, arvore* arv){
	
	arvore* novoNo = malloc(sizeof(arvore));
	
	novoNo -> esquerda = NULL;
	
	novoNo -> direita = NULL;
	
	novoNo -> info = valor;
	
	if (arv == NULL)
		return novoNo;
	else {
		arvore* pai = NULL;
		arvore* i = arv;
		
		while (i != NULL) {
			pai = i;
			if (valor < i->info)
				i = i->esquerda;
			else
				i = i->direita;
		}
		if (valor < pai-> info)
			pai -> esquerda = novoNo;
		else 
			pai -> direita = novoNo;
	}
	
	return arv;
		
}

void imprimeCrescente (arvore* arv) {
	
	if (arv != NULL){
		imprimeCrescente (arv->esquerda);
		printf ("%d \n", arv->info);
		imprimeCrescente (arv->direita);
	}
}

void showMenor (arvore* arv, int valor){
	
	if (arv != NULL){
		showMenor (arv->esquerda, valor);
		if (valor > arv->info)
			printf ("%d \n", arv->info);
		showMenor (arv->direita, valor);
	}
}

arvore* insereNoRecursivo (int valor, arvore* arv){
	
	if (arv == NULL){
		arv = (arvore*) malloc(sizeof(arvore));
		arv-> info = valor;
		arv-> esquerda = NULL;
		arv-> direita = NULL;
	} 
	else if (valor < arv-> info)
		arv -> esquerda = insereNoRecursivo (valor, arv->esquerda);	
	else if (valor > arv-> info)
		arv -> direita = insereNoRecursivo (valor, arv->direita);
		
	return arv;	
}

arvore* buscaValorIterativo (arvore* arv, int valor) {
	
	while (arv != NULL && arv-> info != valor){
		if (valor < arv-> info)
			arv = arv-> esquerda;
		else
			arv = arv-> direita;
	}
	return arv;
}

arvore* buscaValorRecursivo (arvore* arv, int valor){
	
	if (arv != NULL){
		if (arv-> info > valor)
			return buscaValorRecursivo(arv-> esquerda, valor);
		else if (arv-> info < valor)
			return buscaValorRecursivo(arv-> direita, valor);
		else
			return arv;
	} else 
		return NULL;
}


arvore* buscaMenorValorIterativo (arvore* arv){
	
	arvore* i = arv;
	arvore* pai = NULL;

	while (i != NULL){
		pai = i;
		i = i-> esquerda;
	}
	return pai;
}

arvore* buscaMaiorValorAntesRaiz (arvore* arv){
	
	arv = arv-> esquerda;
	
	while (arv-> direita != NULL)
		arv = arv-> direita;
		
	return arv;
	
}

arvore* buscaPaiRecursivamente (arvore* arv, int valor){
	 
	if (valor > arv-> info){
		buscaPaiRecursivamente (arv-> direita, valor);
	}
	
	else if (valor < arv-> info){
		buscaPaiRecursivamente (arv-> esquerda, valor);
	}
	
	else if (valor == arv-> info)
		return arv-> pai;
	
	return NULL;
	
}
