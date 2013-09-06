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
				{
					indexTable[line][column] = vector[line * 10 ];
				}

				
				if(vector[line*10]==-1 )
				{
					indexTable[line][0] = (line * 10)+1;
					indexTable[line][1] = vector[(line * 10)+1 ];
				}else continue;


					
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

	if (primaryIndex>=0)
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
	int primaryIndexSup,primaryIndexInf;

	if(findSpace(vector)==1)
	{
		for(j = 0; j<indexLength && matrix[j][1]<=element;j++ )
		{
			primaryIndex = matrix[j][0];

			primaryIndexSup=matrix[j+1][0];
			primaryIndexInf=matrix[j][0];	
		}
		printf("\n\tprimaryIndexInf :%d\nprimaryIndexSup%d\n",primaryIndexInf,primaryIndexSup);
		if (primaryIndex>0)
			{/*

				while(primaryIndex<=vectorLength && (vector[primaryIndex]<element))
				{

					if( element<vector[primaryIndex+1] && element > vector[primaryIndex])
					{
						indexNewElement=primaryIndex+1;
						aux=vector[primaryIndex+1];
						vector[primaryIndex+1]=element;

					}

					primaryIndex++;
				}
			*/
				for(i=primaryIndexInf;i<=primaryIndexSup;i++)
				{
					if(vector[i]==-1 && element>vector[i-1] && element<vector[i+1])
					{
						indexNewElement=i;
						vector[i]=element;
						aux=-1;
					}else 
					if(element<vector[i+1] && element>vector[i])
					{
						indexNewElement=i+1;
						aux=vector[i+1];
						vector[i+1]=element;

					}else continue;
				}

			if(aux!=-1)
			{
				for(i=indexNewElement+1;i<vectorLength;i++)
				{

					aux2=vector[i];
					vector[i]=aux;
					aux=aux2;


				}

			}else return 1;

			fillIndexTable(matrix,vector);
			printf(" valor inserido na posicao= %d \n",indexNewElement);
			return 1;
			}else return -1;
			
			

	}else return -1;

}

int removeElement(int matrix[][2], int *vector, int element)
{
	int indexElment=searchElement(matrix,vector,element);
	if (indexElment>=0)
	{
		vector[indexElment]=-1;
		fillIndexTable(matrix,vector);
		return 1;
	}else return 0;
}
int main()
{
	srand(time(NULL));
	int vector[101];
	int indexTable[11][2]; 
	int valorBusca, indiceValorEncontrado, i, value;
	int opt;

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

	opt=0;
	while(opt!=-1)
	{
		printf("\nDigite \n1:Para buscar\n2:Para Remover\n3:Para inserir\n-1:Para sair\n\n=>:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
			{
				printf("Digite o valor a ser pesquisado\n");
				scanf("%d",&value);
				indiceValorEncontrado = searchElement(indexTable, vector, value);

				if (indiceValorEncontrado >= 0)
				printf("Índice do valor encontrado: %d \n",indiceValorEncontrado);
				else
				printf("Índice não encontrado \n");

			};break;
			case 2:
			{
				printf("Digite o valor a ser removido\n");
				scanf("%d",&value);
				indiceValorEncontrado=removeElement(indexTable,vector,value);
				if (indiceValorEncontrado == 1)
				printf("Valor removido com sucesso!");
				else
				printf("Tem certeza que voce viu esse valor na lista? olha de novo =D \n");


			};break;
			case 3:
			{
				printf("Digite o valor a ser inserido\n");
				scanf("%d",&value);
				indiceValorEncontrado=insertElement(indexTable,vector,value);
				if (indiceValorEncontrado == 1)
				printf("Valor inserido com sucesso!");
				else
				printf("Nao tem espaco  \n");
			}break;



			
		}
		
		for (i=0;i<=100;i++)
		{
			printf("Vector value [%d]=%d \n",i,vector[i]);
		}

		show(indexTable);
		

		

	}
	

	return 0;
}
