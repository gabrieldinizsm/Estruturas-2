#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct aluno {
int matricula;
char nome [81];
};
typedef struct aluno Aluno;

#define N 127
typedef Aluno* Hash[N];

int geraHash (int matricula);

void listaAlunos (Hash tabela);

int insereProximaPosicao (Hash tabela, int matricula, char* nome);

int buscaMatricula (Hash tabela, int matricula);

main (){
	
	Hash tabela;
	
	int i;
	
	char nome[81];
	
	for(i= 0; i< N; i++)
		tabela[i]= NULL;
		
	strcpy(nome, "Marco");
	i = insereProximaPosicao (tabela, 127, nome);
	
	strcpy(nome, "Maria");
	i = insereProximaPosicao (tabela, 254, nome);
	
	strcpy(nome, "Carlos");
	i = insereProximaPosicao (tabela, 381, nome); 
	
	strcpy(nome, "Sueli");
	i = insereProximaPosicao (tabela, 508, nome);
	
	i = insereProximaPosicao (tabela, 508, nome); //Não vai inserir!!
	
	if (i==1) 
	    printf ("Aluno(a) %s ja existe! - nao inserido(a) \n", nome);
	
	strcpy(nome, "Jorge");
	i = insereProximaPosicao (tabela, 635, nome);
	
	strcpy(nome, "Lucas");
	i = insereProximaPosicao (tabela, 762, nome);
	
	if (i==1) 
	    printf ("Aluno(a) %s ja existe! - nao inserido(a) \n", nome);
	    
	listaAlunos (tabela);	    
	
	printf("\n");
	printf("\n");
	
	 
	system ("pause>NULL");
}

int geraHash (int matricula){
	
	return (matricula%N);
}


void listaAlunos (Hash tabela){
	
	int i = 0;
	
	for (i = 0; i < N; i++){
		if (tabela[i] != NULL)
			printf ("%s %d \n", tabela[i]->nome, tabela[i]->matricula);		
	}
}

int insereProximaPosicao (Hash tabela, int matricula, char* nome){
	
	int hash = geraHash (matricula);
	int j;
	
	
	if (tabela[hash] == NULL){
		tabela[hash] = (Aluno*) malloc(sizeof(Aluno));
		tabela[hash]-> matricula = matricula;
		strcpy(tabela[hash]-> nome, nome); 
		return hash;
	}
	
	else {
		
		j = buscaMatricula (tabela, matricula);
		if (j != -1)
			return -1;
		
		else {
		
			while (tabela[hash] != NULL)
				hash += 1;
				
			if (hash >= N)
				return -1;
				
			tabela[hash] = (Aluno*) malloc(sizeof(Aluno));
			tabela[hash]-> matricula = matricula;
			strcpy(tabela[hash]-> nome, nome); 
			return hash;	
		}
	}		
	
}

int buscaMatricula (Hash tabela, int matricula) {
	
	int i;
	
	for (i = 0; i < N; i++){
		if (tabela[i] != NULL){
			if (tabela[i]-> matricula == matricula)
				return i;
		}
	}
	return -1;
}


