//repita a função imprime sendo que nesse caso quero imprimir apenas as folhas

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

criaArvore (char c, arvore* esq, arvore* dir){
	
	arvore* p = malloc(sizeof(arvore));
	p->info = c;
	p->esquerda = esq;
	p->direita = dir;
	return p;
}

void arvoreImprime (arvore* arvore){
	
	if (!checaArvoreVazia(arvore)){
		printf("%c \n", arvore->info);
		arvoreImprime (arvore->esquerda);
		arvoreImprime (arvore->direita);
	}
}

main (){
	
	arvore* a1  = criaArvore ('e', criaArvoreVazia(),criaArvoreVazia()); //folha
	
	arvore* a2  = criaArvore ('f', criaArvoreVazia(),criaArvoreVazia()); //folha
	
	arvore* a3  = criaArvore ('d', criaArvoreVazia(),criaArvoreVazia()); //folha
	
	arvore* a4  = criaArvore ('c', a1, a2);
	
	arvore* a5  = criaArvore ('b', criaArvoreVazia(), a3);
	
	arvore* a6  = criaArvore ('a', a5, a4);
	
	arvoreImprime (a6);
	
	system ("pause>NULL");

}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

