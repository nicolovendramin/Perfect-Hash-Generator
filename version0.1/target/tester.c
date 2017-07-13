#include <stdio.h>
#include "testCases.h"
#include "hashTable.h"
void printArray(int rhs[],int rhs_size);

int main()
{
	int i;
	int counter = 1;
	int number = getNumberOfCases();
	for(i=0;i<number;i++)
	{	
		if(lookUp(&getTestCases()[i],getLenghts()[i])!=i+1)
		{
			printf("Error #%i at case number %i,%i!=%i\n",counter,i,lookUp(&getTestCases()[i],getLenghts()[i]),i+1);
			printArray(&getTestCases()[i],getLenghts()[i]);
			counter++;	
		}
	}
	printf("Total number of errors: %i, Error percentage = %f\n",counter-1,(float)((float)(counter-1)*100/(float)(number)));
}

void printArray(int rhs[],int rhs_size)
{
	int i=0;
	for(i=0;i<rhs_size;i++)
		printf("-->%i",rhs[i]);
	printf("\n");
}
