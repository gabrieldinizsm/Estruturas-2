#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct aluno {
int matricula;
char nome [81];
struct aluno* proximo; 
};
typedef struct aluno Aluno;

#define N 127
typedef Aluno* Hash[N];

int geraHash (int matricula){
	
	return (matricula%N);
}

int insereUltimo (Hash tab, int matricula, char nome[50]);

Aluno* buscaAluno (Hash tab, int matricula);

int retiraAluno (Hash tab, int matricula);

void listaAlunos (Hash tab, int matricula);

main (){
	
	Hash tabela;
	
	int i;
	
	char nome[81];
	
	for(i=0;i<N;i++)
		tabela[i]= NULL;
		
   strcpy(nome, "Marco");
   i = insereUltimo (tabela, 127, nome);
   
   strcpy(nome, "Maria");
   i = insereUltimo (tabela, 254, nome);
   
   strcpy(nome, "Carlos");
   i = insereUltimo (tabela, 381, nome); 
   
   strcpy(nome, "Sueli");
   i = insereUltimo (tabela, 508, nome);
   
   i = insereUltimo (tabela, 508, nome); //Não vai inserir!!
   
   if (i==1) 
   	    printf ("Aluno(a) %s ja existe! - nao inserido(a) \n", nome);
   
   strcpy(nome, "Jorge");
   i = insereUltimo (tabela, 635, nome);
   
   strcpy(nome, "Lucas");
   i = insereUltimo (tabela, 762, nome);
   
   listaAlunos (tabela, 762);
   
   if (i==1) 
   	    printf ("Aluno(a) %s ja existe! - nao inserido(a) \n", nome);
   
   printf("\n");
   printf("\n");

   Aluno* k = buscaAluno (tabela, 635);

   
   if(k==NULL)
   		printf("Aluno(a) nao encontrado(a)!");
   else 
   		printf("Aluno(a) %s pertence a tabela!", k->nome);
   
   printf("\n");
   printf("\n");

   i = retiraAluno (tabela, 762);
   
   k = buscaAluno (tabela, 508);
   
   if(k==NULL) 
   		printf("Aluno(a) nao encontrado(a)!");
   else 
   		printf("Aluno(a) %s pertence a tabela!", k->nome);  
		
	
	printf("\n");
	printf("\n");
	
	 
	system ("pause>NULL");
}

int insereUltimo (Hash tab, int matricula, char nome[50]){
	
	int hash = geraHash(matricula);
	Aluno* x = NULL;
	Aluno* novoElemento = NULL;
	
	if (tab[hash] == NULL){
		
		tab[hash] = (Aluno*) malloc(sizeof(Aluno));
		tab[hash]-> matricula = matricula;
		strcpy(tab[hash]-> nome, nome); 
		tab[hash]-> proximo = NULL;
		
		return 0;
	}
	else {
		if (tab[hash]-> matricula == matricula)
			return 1;
		else {
			x = tab[hash];
			while (x-> proximo != NULL)
				x = x-> proximo;
				
			novoElemento = (Aluno*) malloc(sizeof(Aluno));
			novoElemento-> matricula = matricula;
			strcpy(novoElemento-> nome, nome); 
			novoElemento-> proximo = NULL; 
			x->proximo = novoElemento;

			return 0;
		}
	}
}

Aluno* buscaAluno (Hash tab, int matricula){
	
	int hash = geraHash(matricula);
	Aluno* x = tab[hash];
	
	if (tab[hash]-> matricula == matricula)
		return tab[hash];
	
	else {
		while (x != NULL){
			if (x-> matricula == matricula)
		  		return x;
			x = x-> proximo;
		}
	return NULL;		
	}		
}

int retiraAluno (Hash tab, int matricula){
	
	int hash = geraHash(matricula);
	Aluno* aluno = NULL;
	Aluno* novoCabeca = NULL;
	
	if (tab[hash]-> matricula == matricula){
		tab[hash] = tab[hash]-> proximo;
		return 0;
	}
	else{
		
		aluno = buscaAluno (tab, matricula);
		
		if (aluno-> proximo != NULL){
			aluno-> matricula = aluno-> proximo -> matricula;
			strcpy(aluno-> nome, aluno-> proximo -> nome); 
			aluno-> proximo = aluno -> proximo-> proximo;
			return 0;
		}
		else {
			free(aluno);
			return 0;
		}
	}
	
	return 1;
}

void listaAlunos (Hash tab, int matricula){
	
	int hash = geraHash(matricula);
	Aluno* x = tab[hash];
	
	while (x != NULL){
		printf ("%s  \n", x-> nome);
		x = x-> proximo;
	}
}
