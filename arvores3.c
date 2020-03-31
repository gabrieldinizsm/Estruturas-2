#include <stdio.h>
#include <stdlib.h>

struct arvore {
	char info;
	struct arvore* esquerda;
	struct arvore* direita;
};

typedef struct arvore arvore;

arvore* criaArvoreVazia (void){
	return NULL;
}

int checaArvoreVazia (arvore* arvore){
	
	return NULL == arvore;
}

arvore* criaArvore (char c, arvore* esq, arvore* dir){
	
	arvore* p = malloc(sizeof(arvore));
	p->info = c;
	p->esquerda = esq;
	p->direita = dir;
	return p;
}

void arvoreImprimePreOrdem (arvore* arvore){
	
	if (!checaArvoreVazia(arvore)){
		printf("%c \n", arvore->info);
		arvoreImprimePreOrdem (arvore->esquerda);
		arvoreImprimePreOrdem (arvore->direita);
	}
}

void arvoreImprimePosOrdem (arvore* arvore){
	
	if (!checaArvoreVazia(arvore)){
		arvoreImprimePosOrdem (arvore->esquerda);
		arvoreImprimePosOrdem (arvore->direita);
		printf("%c \n", arvore->info);
	}
}

void arvoreImprimeOrdemSimetrica (arvore* arvore){
	
	if (!checaArvoreVazia(arvore)){
		arvoreImprimeOrdemSimetrica (arvore->esquerda);
		printf("%c \n", arvore->info);
		arvoreImprimeOrdemSimetrica (arvore->direita);
	}
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
	}
}

main (){
	
	arvore* a1  = criaArvore ('j', criaArvoreVazia(), criaArvoreVazia()); //folha
	
	arvore* a2  = criaArvore ('i', criaArvoreVazia(), a1);
	
	arvore* a3  = criaArvore ('m', criaArvoreVazia(), criaArvoreVazia()); //folha
	
	arvore* a4  = criaArvore ('h', a3, a2);
	
	arvore* a5  = criaArvore ('l', criaArvoreVazia(), criaArvoreVazia()); //folha
	
	arvore* a6  = criaArvore ('d', a4, criaArvoreVazia());
	
	arvore* a7  = criaArvore ('g', criaArvoreVazia(), criaArvoreVazia()); //folha
	
	arvore* a8  = criaArvore ('f', criaArvoreVazia(), criaArvoreVazia()); //folha	
	
	arvore* a9  = criaArvore ('k', criaArvoreVazia(), a5); 
	
	arvore* a10  = criaArvore ('c', a7, a6); 
	
	arvore* a11  = criaArvore ('e', a9, a8); 
	
	arvore* a12  = criaArvore ('b', a11, a10); 

	arvore* a13  = criaArvore ('a', a12, criaArvoreVazia()); 
	
	arvoreImprimePreOrdem (a13);
	
	printf ("\n\n\n");
	
	arvoreImprimePosOrdem (a13);
	
	printf ("\n\n\n");
	
	arvoreImprimeOrdemSimetrica (a13);
	
	arvorePertence(a13, "k");
	
	liberaArvore (a13);
	
	system ("pause>NULL");

}
