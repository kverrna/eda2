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

void fillTable(int *vector)
{
	printf("Filling the Vector.................................\n");
	int j;
	sleep(1);
	for (j=0;j<10;j++)
	{
		vector[j] = rand() % 100 + 1;
		
	}
}

int searchElement(int *vector, int head, int tail, int element)
{
	int initialElement, finalElement, middle;
	initialElement = head;
	finalElement = tail;	

	while (initialElement<=finalElement)
	{
		middle = initialElement + ( finalElement - initialElement)/ 2 ;

		if (vector[middle] == element)
			return middle;
		else
		{
			if (element > vector[middle])
				initialElement = middle + 1;
			else
				finalElement = middle - 1;
		}		
	}	
	return -1;
}

int removeElement (int *vector, int head, int tail, int element)
{

	int index,i;
	index = searchElement(vector, head, tail, element);
	if(index>=0)
	{
		for (i=0;i<10;i++)
		{
			
		}
	}

	

}

void showVector(int *vector)
{
	int k;	
	int length = 10;

	for(k=0;k<length;k++)
	{
		printf("Vector value [%d]=%d \n",k,vector[k]);
	}

}

void sortVector(int *vector)
{
	int k=0, j=0, temporaria;
	printf("Sorting the Vector.................................\n");
	for(k=0;k<10;k++)
	{
		for(j=k+1;j<10;j++)
		{
		if(vector[k]>vector[j])
		{
			temporaria=vector[k];
			vector[k]=vector[j];
			vector[j]=temporaria;
			}
		}
	}	

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
	int value,index;
	
	vector = vectorCreate(10);
	
	fillTable(vector->vect);
	sortVector(vector->vect);
	showVector(vector->vect);

	vector->head = 0;
	vector->tail = 9;

	printf("HEAD: %d TAIL %d \n",vector->head,vector->tail);
	
	printf("Informe um número a ser pesquisado\n");
	scanf("%d",&value);

	index = searchElement(vector->vect, vector->head, vector->tail, value);
	
	if(index>=0)
		printf("Index Encontrado: %d\n", index);
	else
		printf("Valor não encontrado\n");

	return 0;

}
