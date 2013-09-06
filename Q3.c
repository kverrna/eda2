#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

typedef struct vector{
    int *vect;
    int head;
    int tail;
    int qtd;
    int length;
} Vector ;

void fillTable(Vector *vector)
{
	printf("Filling the Vector.................................\n");
	int indice;
	sleep(1);
	for (indice=0;indice<vector->length;indice++)
	{
		vector->vect[indice] = indice + 1;
		vector->qtd = vector->qtd + 1;	
	}
	vector->head = 0;
	vector->tail = vector->length - 1;
}

int searchElement(Vector *vector, int element)
{
	int initialElement, finalElement, middle;
	initialElement = vector->head;
	finalElement = vector->tail;	

	while (initialElement<=finalElement)
	{
		middle = initialElement + (( finalElement - initialElement) / (vector->vect[finalElement] - vector->vect[initialElement]) * (element -vector->vect[initialElement])) ;

		if (vector->vect[middle] == element)
			return middle;
		else
		{
			if (element > vector->vect[middle])
				initialElement = middle + 1;
			else
				finalElement = middle - 1;
		}		
	}
	return -1;
}

void sortVector(Vector *vector)
{
	int k=0, j=0, temporaria;
	printf("Sorting the Vector.................................\n");
	
	for(k=0;k<=vector->qtd;k++)
	{
		for(j=k+1;j<=vector->qtd;j++)
		{
		if(vector->vect[k]>vector->vect[j])
		{
			temporaria=vector->vect[k];
			vector->vect[k]=vector->vect[j];
			vector->vect[j]=temporaria;
			}
		}
	}	

}

void showVector(Vector *vector)
{
	int k;	
	int length = vector->qtd;

	printf("HEAD: %d TAIL %d \n",vector->head,vector->tail);

	for(k=0;k<length;k++)
	{
		printf("Vector value [%d]=%d \n",k,vector->vect[k]);
	}

}

int removeElement (Vector *vector, int element)
{

	int index,i;
	index = searchElement(vector, element);
	if(index>=0)
	{
		if (vector->vect[index] == vector->vect[vector->tail])
			vector->tail--;

		for (i=index;i<9;i++)
		{
			vector->vect[i] = vector->vect[i+1];
		}

		vector->vect = (int*) realloc ( vector->vect , sizeof( int ) * (vector->qtd - 1));
		vector->qtd = vector->qtd - 1;
		printf("---------QTD VECTOR: %d---------\n", vector->qtd);
		printf("Tamanho do Vetor: %d\n", vector->length);	
		showVector(vector);	
		return 1;
			
	}
	return 0;

}


int insertElement(Vector *vector, int element)
{
	
	int index;
	if (vector->qtd < vector->length)
	{
		vector->vect = (int*) realloc ( vector->vect , sizeof( int ) * (vector->qtd + 1));
		printf("---------QTD VECTOR: %d---------\n", vector->qtd);	
		vector->vect[vector->qtd] = element;
		vector->qtd = vector->qtd + 1;
		sortVector(vector);
		showVector(vector);
		return 1;		

	}
	else
		return 0;

}

Vector * vectorCreate(int length){
    
	Vector * vector;
	vector = (Vector*) malloc ( sizeof( Vector ) );
 
	if(!vector)
	{
      		return NULL; 
   	}
 

    	vector->vect = (int*) malloc ( sizeof( int ) * length );
 
   	if(!vector->vect)
	{
      		return NULL; 
   	}
 
	vector->head = 0;
	vector->qtd = 0;
	vector->tail = 0;
	vector->length = length;
	 
	return vector;
}

int main()
{

	srand(time(NULL));
	Vector *vector;	
	int value,index,resposta;
	
	vector = vectorCreate(100);
	
	fillTable(vector);
	//sortVector(vector);
	showVector(vector);

	
	printf("Informe um número a ser pesquisado\n");
	scanf("%d",&value);

	index = searchElement(vector, value);
	
	if(index>=0)
		printf("Index Encontrado: %d\n", index);
	else
		printf("Valor não encontrado\n");
	
	return 0;

	/*

	printf("Digite um valor a ser removido\n");
	scanf("%d",&value);
	
	resposta = removeElement (vector, value);
	
	if(resposta == 1)
		printf("Valor Removido com Sucesso!!!!!!\n");
	else
		printf(" Valor a ser removido não existe, tente novamente\n");

	printf("Informe um número a ser inserido\n");
	scanf("%d",&value);

	index = insertElement(vector, value);
	
	if(index == 1)
		printf("Inserido\n");
	else
		printf("Não inserido - Falta de Espaço\n");
	*/
	

}
