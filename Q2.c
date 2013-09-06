#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

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

int removeElement (int *vector, int element)
{

	int index;
	index = searchElement(int *vector, int head, int tail, int element);

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

int main()
{

	srand(time(NULL));	
	int vector[10], head, tail,value,index;

	fillTable(vector);
	sortVector(vector);
	showVector(vector);

	head = 0;
	tail = 9;

	printf("HEAD: %d TAIL %d \n",head,tail);
	
	printf("Informe um número a ser pesquisado\n");
	scanf("%d",&value);

	index = searchElement(vector, head, tail, value);
	
	if(index>=0)
		printf("Index Encontrado: %d\n", index);
	else
		printf("Valor não encontrado\n");

	return 0;

}
