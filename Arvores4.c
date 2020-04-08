#include<stdio.h>
#include<stdlib.h>

struct arvore {
	int info;
	struct arvore* esquerda;
	struct arvore* direita;
};

typedef struct arvore arvore;

arvore* criaArvoreVazia (void);

int checaArvoreVazia (arvore* arvore);

int arvorePertence (arvore* arvore, char c);

void liberaArvore (arvore* arvore);

arvore* insereNoInterativo (int valor, arvore* arv);

arvore* insereNoRecursivo (int valor, arvore* arv);

void imprimeCrescente (arvore* arv);

arvore* buscaValorRecursivo (arvore* arv, int valor);

main (){
	
	arvore* a = criaArvoreVazia ();
	
	a = insereNoRecursivo (6, a);
	
	a = insereNoRecursivo (5, a);
	
	a =	insereNoRecursivo (8, a);
	
	a =	insereNoRecursivo (4, a);
	
	a =	insereNoRecursivo (2, a);
	
	a =	insereNoRecursivo (9, a);
	
	a =	insereNoRecursivo (1, a);

	imprimeCrescente (a);
	
	a = buscaValorRecursivo(a, 4);
	
	printf ("\n\n%d \n", a->info);
	
	liberaArvore (a);
	
	system ("pause>NULL");

}

arvore* criaArvoreVazia (void){
	
	return NULL;
}

int checaArvoreVazia (arvore* arvore){
	
	return NULL == arvore;
}

arvore* criaArvore (int valor, arvore* esq, arvore* dir){
	
	arvore* p = malloc(sizeof(arvore));
	p->info = valor;
	p->esquerda = esq;
	p->direita = dir;
	return p;
}


int arvorePertence (arvore* arvore, char c){
	
	if (checaArvoreVazia(arvore))
		return 0;
	else 	
		return arvore ->info == c || arvorePertence (arvore->esquerda, c) || arvorePertence (arvore->direita, c);
}

void liberaArvore (arvore* arvore){
	
	if (!checaArvoreVazia(arvore)){
		liberaArvore (arvore-> esquerda);
		liberaArvore (arvore-> direita);
		free(arvore);
	}
}

arvore* insereNoInterativo (int valor, arvore* arv){
	
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

arvore* buscaValorRecursivo (arvore* arv, int valor) {
	
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
