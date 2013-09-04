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
	for (j=0;j<=100;j++)
	{
		vector[j] = rand() % 1000 + 1;
		
	}
}

void sortVector(int *vector)
{
	int k=0, j=0, temporaria;
	printf("Sorting the Vector.................................\n");
	for(k=0;k<=100;k++)
	{
		for(j=k+1;j<=100;j++)
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

void fillIndexTable(int indexTable[][2] , int *vector)
{
	int line, column;
	printf("Filling the index table.................................\n");
    	for(line = 0 ; line <= 10 ; line++)
	{
		for(column = 0 ; column < 2 ; column++)
		{
			if (column == 0)
				indexTable[line][column] = line * 10;
			else
				indexTable[line][column] = vector[line * 10 ];
		}
	}
}

void show(int matrix[][2])
{
	printf("Printing the index table.................................\n");
	int line, column;
	printf("Matrix Index\n\n");
	printf("Index_Vector|Value\n");
	for(line = 0 ; line <= 10 ; line++)
	{	
		for(column = 0 ; column < 2 ; column++)	    
			printf("     %2d ", matrix[line][column]);

		printf("\n");
	}
}


int searchElement(int matrix[][2], int *vector, int searchedElement)
{
	int searchedIndex = -1, j, primaryIndex;
	int indexLength = 11;
	int vectorLength = 101;
	
	for(j = 0; j<indexLength && matrix[j][1]<=searchedElement;j++ )
	{
		primaryIndex = matrix[j][0];	
	}

	printf("Primary Index = %d\n ",primaryIndex);

	if (primaryIndex>0)
	{
		printf("Searching in the Vector................................\n");

		while(primaryIndex<=vectorLength && vector[primaryIndex]<=searchedElement)
		{
			printf("Primary Index: %d vector[primaryIndex] %d searchedELement %d \n",primaryIndex,vector[primaryIndex],searchedElement);
			if(vector[primaryIndex]==searchedElement)
			{
				searchedIndex=primaryIndex;
				printf(" Indice Real = %d \n",searchedIndex);		
			}

			primaryIndex++;
		}
	}
	return searchedIndex;	
}

int findSpace(int *vector)
{
	int result=-1,i;
	int vectorLength=101;
	for ( i = 0; i < vectorLength; i++)
	{
		if(vector[i]==-1) return 1;else continue;
	}
	return result;
}
int insertElement(int matrix[][2],int *vector, int element)
{		
	int i,j, aux,aux2,primaryIndex,indexNewElement;
	int indexLength = 11;
	int vectorLength = 101;

	if(findSpace(vector)==1)
	{
			for(j = 0; j<indexLength && matrix[j][1]<=searchedElement;j++ )
			{
				primaryIndex = matrix[j][0];	
			}
		if (primaryIndex>0)
			{
				while(primaryIndex<=vectorLength && (vector[primaryIndex]<=element))
				{
					
					if( element<vector[primaryIndex+1] && element > vector[primaryIndex])
					{
						indexNewElement=primaryIndex;
						aux=vector[primaryIndex];
						vector[primaryIndex]=element;
								
					}

					primaryIndex++;
				}

				for(i=indexElment+1;i<vectorLength;i++)
				{
					aux2=vector[i];
					vector[i]=aux;
					aux=vector[i+1];
					vector[i+3]=aux;
					//fazer o uso de duas auxiliares --mt sono .. nao da mais nao ... vou dormir

				}
			}
			printf(" valor inserido na posicao= %d \n",indexNewElement);

	}else return -1;

}
int removeElement(int matrix[][2], int *vector, int element)
{
	int indexElment=searchElement(matrix,vector,element);
	if (indexElment>=0)
	{
		vector[indexElment]=-1;
		return 1;
	}else return 0;
}

int main()
{
	srand(time(NULL));
	int vector[101];
	int indexTable[11][2]; 
	int valorBusca, indiceValorEncontrado, i, searched_value,removed_value;
	int removeReturn;

	fillTable(vector);
	
	for (i=0;i<=100;i++)
	{
		printf("Vector value [%d]=%d \n",i,vector[i]);
	}

        sortVector(vector);	

	for (i=0;i<=100;i++)
	{
		printf("Sorted value vector [%d]=%d \n",i,vector[i]);
	}

	fillIndexTable(indexTable,vector);
	
	show(indexTable);
	
	printf("Digite o valor a ser pesquisado\n");
	scanf("%d",&searched_value);

	indiceValorEncontrado = searchElement(indexTable, vector, searched_value);

	if (indiceValorEncontrado >= 0)
		printf("Índice do valor encontrado: %d \n",indiceValorEncontrado);
	else
		printf("Índice não encontrado \n");

	

	//Remocao -- sequencia de testes 

	printf("Digite o valor a se removido\n");
	scanf("%d",&removed_value);

	removeReturn=removeElement(indexTable,vector,removed_value);


	if (removeReturn==1)
	{
			for (i=0;i<=100;i++)
		{
			printf("Vector value [%d]=%d \n",i,vector[i]);
		}
		printf("\t\t\nÍndice do valor encontrado e removido: \n");
	}
	else
		printf("Valor informado nao existe na lista \n");

	
	return 0;
}
