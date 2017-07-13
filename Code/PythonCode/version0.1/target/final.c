#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"
#include "testCases.h"


void main(){
	int i = getNumberOfCases();
	int k = 0;
	int j = 0;
	int error = 0;
	for(j=0;j<i;j++){		
	if((int)lookUp(&getTestCases()[k],getLenghts()[j])!=j+1)
		{	
					printf("\nERROR->");
					error += 1;
					printf("[%i]disambiguation cell : %i\n",j,hashFunction(0,&getTestCases()[k],getLenghts()[j])%DSIZE);
					printf("disambiguationContent : %u\n",disambiguationTable[hashFunction(0,&getTestCases()[k],getLenghts()[j])%DSIZE]);
					printf("final cell: %u\n",hashFunction(hashFunction(0,&getTestCases()[k],getLenghts()[j])%DSIZE,&getTestCases()[k],getLenghts()[j])%SIZE);
					printf("final value:%u\n",table[hashFunction(disambiguationTable[hashFunction(0,&getTestCases()[k],getLenghts()[j])%DSIZE],&getTestCases()[k],getLenghts()[j])%SIZE]);
					printf("%i != %i\n\n",lookUp(&getTestCases()[k],getLenghts()[j]),j+1);
		}
		else
		{
			printf("%i==%i,[in position #%i->%u]\n",j+1,(int)lookUp(&getTestCases()[k],getLenghts()[j]),hashFunction(0,&getTestCases()[k],getLenghts()[j])%DSIZE,disambiguationTable[hashFunction(0,&getTestCases()[k],getLenghts()[j])%DSIZE]);
			
		}	
	k = k + getLenghts()[j];
	}
	printf("number of errors:%i. In percentage : %f%%\n",error,(float)error/(float)i);
}

		
