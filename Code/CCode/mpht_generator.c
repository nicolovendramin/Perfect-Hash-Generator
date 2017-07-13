/*Software written by Vendramin Nicolò. All rights are reserved to the owner.*/
#include <stdio.h>
#include <stdlib.h>
int size = 10000;
int add_lenght = 0;
int *indexing_table;
int *table;
int lookup_parameters[5];
void get_random();

void main(int argc,char *argv[])
{
	int i;
	FILE *f;
	char buffer[4];
	int result=0,j;
	if(argc==1) ;
	else if(strcmp(argv[1],"-h")==0)
	{
		printf("HELP: You can call the function with one or two parameters, the first is ALWAYS the additional lenght in percentage to the dimension of the whole table, and the second is ALWAYS the size of the table. If you want to set only the first parameter leave the second blank.\nIf you want to set only the second parameter set the first option to zero.\n");
		return;
	}
	else if(atoi(argv[1])>=0 && (argc==2 || atoi(argv[2])>0))
	{
		add_lenght = atoi(argv[1]);
		if(argc==3) size = atoi(argv[2]);
	}
	else
	{
		printf("Not recognised option.Retry\n");
		return;
	}
	printf("size:%i,add_lenght:%i\n",size,add_lenght);
	for(j=0;j<size;j++)
	{
		printf("I launch the routine");
		f = fopen("/dev/random","r");
	fread(buffer,1,4,f);
	for(i=0;i<4;i++)
	{
		result+=(int)buffer[i]*2^(i*8);
		printf("cicle %i",i);
	}
	printf("random number = %i\n",result);
	printf("%i\n",fclose(f));
		printf("I got back from the routine");
	}
	return;
}
	
int lookup_function();
void build_table()
{
	indexing_table = malloc(size/10*sizeof(int));
	table = malloc(size*sizeof(int));
}

void get_random()
{
	FILE *f;
	char buffer[4];
	int result=0,i;
	f = fopen("/dev/random","r");
	fread(buffer,1,4,f);
	for(i=0;i<4;i++)
	{
		result+=(int)buffer[i]*2^(i*8);
		printf("cicle %i",i);
	}
	printf("random number = %i\n",result);
	printf("%i\n",fclose(f));
	return;
}
void recalculate_parameter_set()
{
	//this function has the aim to produce a set of random coefficients for the lookup polynome
	//and the set of value to be put on the indexing table;
}

void primary_hashing(int array[])
{
	//translate each single int into a string. Concats the strings and then atoi the full seto to get the BIGINT to hash
}
		
