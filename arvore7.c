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

arvore* insereNoIterativo (arvore* arv, int valor);

void imprimeCrescente (arvore* arv);

arvore* buscaPaiRecursivamente (arvore* arv, int valor);

void showMenor (arvore* arv, int valor);

arvore* buscaMenorValorIterativo (arvore* arv);

arvore* encontraRaiz (arvore* arv);

arvore* liberaArvore (arvore* arvore);

arvore* buscaMaiorValorAntesRaiz (arvore* arv);

main (){
	
	arvore* a = criaArvoreVazia ();
	
	a = insereNoIterativo (a, 6);
	
	a =	insereNoIterativo (a, 1);
	
	a = insereNoIterativo (a, 5);
	
	a =	insereNoIterativo (a, 3);
	
	a =	insereNoIterativo (a, 8);
	
	a =	insereNoIterativo (a, 5);
	
	a =	insereNoIterativo (a, 2);
	
	a =	insereNoIterativo (a, 9);
	
	a =	insereNoIterativo (a, 4);
	
	a =	insereNoIterativo (a, 7);
	
	imprimeCrescente (a);
	
	showMenor(a, 5);
	
	arvore* k = criaArvoreVazia ();
	
	k = buscaMenorValorIterativo(a);
	
	if (a != NULL)
		printf ("%d \n", k->info);
		
	arvore* b = criaArvoreVazia ();
	
	b = encontraRaiz(k);
	
	printf ("%d \n", b->info);
	
	k = buscaMaiorValorAntesRaiz (a);
	
	if (a != NULL)
		printf ("%d \n", k->info);
	
	liberaArvore (a);
	
	system("pause>NULL");
}

arvore* criaArvoreVazia (void){
	
	return NULL;
}

int checaArvoreVazia (arvore* arvore){
	
	return NULL == arvore;
}

arvore* insereNoIterativo (arvore* arv, int valor){
	
	arvore* novoNo = malloc(sizeof(arvore));
	
	novoNo-> esquerda = NULL;
	
	novoNo-> direita = NULL;
	
	novoNo-> pai = NULL;
	
	novoNo-> info = valor;
	
	if (arv == NULL)
		return novoNo;
	else {
		arvore* i = arv;
		
		while (i != NULL) {
			novoNo-> pai = i;
			if (valor < i->info)
				i = i->esquerda;
			else
				i = i->direita;
		}
		
		i = novoNo-> pai;
		
		if (valor >= i-> info){
			novoNo-> pai = i;
			i-> direita = novoNo;
		} 
		else {
			novoNo-> pai = i;
			i-> esquerda = novoNo;
		}
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

arvore* buscaMenorValorIterativo (arvore* arv){
	
	arvore* i = arv;

	while (i-> esquerda != NULL)
		i = i-> esquerda;

	return i;
}

arvore* encontraRaiz (arvore* arv){
	
	arvore* i = arv;
	
	while (i->pai != NULL)
		i = i->pai;
		
	return i;
}

arvore* liberaArvore (arvore* arvore){
	
	if (!checaArvoreVazia(arvore)){
		liberaArvore (arvore-> esquerda);
		liberaArvore (arvore-> direita);
		free(arvore);
	}
	
	return NULL;
}

arvore* buscaMaiorValorAntesRaiz (arvore* arv){
	
	arv = arv-> esquerda;
	
	while (arv-> direita != NULL)
		arv = arv-> direita;
		
	return arv;
	
}
