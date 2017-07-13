/*The following code is meant to Calculate a set of N(first input option - default is 10000) to be fitted in a 
table of the dimension N+N*n/100 (where n is the second input option - default is 0). The tecnique employed is 
the one of the minimal perfect hashing realized with a 2 steps hashing function:
1st step: the first hashing function gives back an index of the indexing table which contains a set of a fixed
number of random indexes used in the second step.
2nd step: the second hashing function gives back the index of the real table in which the left hand side are 
placed basing on the number taken from the first hf results and on the value of the right hand side.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

//global parameters
unsigned int *indexing_table =NULL;
int *table = NULL;
unsigned int **set;
int parameters[14]={1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int table_dim;
int number_of_keys;
int max_list_length=1; //estending this to 10 we get a problem
int *set_length = NULL;

//functions interfaces
void create_table();
void generate_random_set();
void generate();
unsigned long long big_int(unsigned int rhs[],int rhs_size);
unsigned long long potenza(unsigned long int n,unsigned long int exp);
void reset(int *table,int N);
void print_set(int bucket[],int dim);

int main(int argc,char *argv[])
{
	//analysis of the options and launch of the necessary routine param#1 table dimension param#2 additional space in percentage
	if(argc!=3) return;
	number_of_keys = atoi(argv[1]);
	table_dim = number_of_keys+(int)((float)(atoi(argv[2]))/100*number_of_keys);
	create_table();
	generate_random_set();
	generate();
	printf("Generation Concluded!");
	print_set(table,table_dim);
}


int test_lookup(int rhs[],int rhs_size,int lhs)
{
	//here we test the random parameters of the currently testing solution. Returns 0 if lookup is fine, 1 if is a collision
	unsigned long long int BIG = 0;
	int fi = 0;
	int si = 0;	
	BIG = big_int(rhs,rhs_size);
	fi=h1(BIG);
	si=h2(indexing_table[fi],BIG);
	printf("%i--(%i)|%i",si,table[si],lhs);
	if(table[si] != -1) return 1;
	else	table[si] = lhs;
	puts("FINE\n");
	return 0;
}

/*working : tested!*/
void create_table()
{
	//this creates the indexing and real table basing on the inputs
	int i;
	table = malloc(table_dim*sizeof(int));
	indexing_table = malloc(number_of_keys/10 * sizeof(unsigned int));
	set = malloc(number_of_keys*sizeof(int*));
	set_length = malloc(number_of_keys*sizeof(int));
}


/*working : tested!*/
void generate_random_set()
{
	//this generates the set of random int lists to use for the lookup
	FILE *f;
	unsigned int i=0,j=0,N=0;
	f = fopen("/dev/urandom","r+");
	unsigned int RANDOM_NUMBER;
	fread(&RANDOM_NUMBER,1,sizeof(unsigned int),f);	
	for(i=0;i<number_of_keys;i++)
	{	
		fread(&RANDOM_NUMBER,1,sizeof(unsigned int),f);
		N = max_list_length;// (RANDOM_NUMBER%(max_list_length-1))+1;
		set_length[i] = N;
		set[i] = malloc(N*sizeof(int));
		for(j=0;j<N;j++)
		{
			fread(&RANDOM_NUMBER,1,sizeof(unsigned int),f);
			set[i][j] = RANDOM_NUMBER%(10000);		
		}
	}
	fclose(f);
	return;					
}

//working but to be improved
unsigned long long big_int(unsigned int rhs[],int rhs_size)
{
	unsigned long long c,b = 0;
	int i;
	for(i=0;i<rhs_size;i++)
	{
		c = rhs[rhs_size-i-1]*(potenza(10,4*i));
		b+=c;
	}
	return b;
}

int h1(unsigned long long int big_int)
{
	//this is the first hashing function who returns the index of the indexing table
	unsigned __int128 c = big_int*big_int;
	return ((c*parameters[0]+big_int*parameters[1]+parameters[2])/2)%(number_of_keys/10);
	
}


int h2(int h1,unsigned long long int big_int)
{
	//this second hashing function use the value contained in the indexing table at the h1 index and the value of the key to be hashed
	unsigned __int128 c = big_int*big_int;
	return abs((c*c*big_int*parameters[8]+c*c*parameters[7]+c*big_int*parameters[6]*h1+(c*parameters[3]*h1)%(big_int%8+1)+(big_int*parameters[4]/(h1+1))+(parameters[5]*h1)%(big_int/1000%256+1))%table_dim);
	
}

/*working */
void randomize()
{
	//randomize all the parameters(content of indexing_table and polynom coefficients
	FILE *f = fopen("/dev/urandom","r");
	unsigned int buffer;
	int i;
	for(i=0;i<number_of_keys/10;i++)
	{
		fread(&buffer,1,sizeof(unsigned int),f);
		indexing_table[i] = buffer%1000;
	}
	for(i=0;i<14;i++)
	{
		fread(&buffer,1,sizeof(unsigned int),f);
		parameters[i] = buffer%100;
	}	
	print_set(indexing_table,number_of_keys/10);
	fclose(f);
}

//this is working
void generate()
{
	//this tries different random combinations of parameters and values in the indexing tables until he gets no collisions
	int i=0;
	int err = 0;
	while(number_of_keys>i)
	{		
	//	print_set(table,table_dim);
		randomize();
		reset(table,table_dim);
		err = 0;
		puts("the problem is later");	
		for(i=0;i<number_of_keys && err ==0 ;i++)
		{
			printf("%i/%i:::::::",i,number_of_keys);
			err = test_lookup(set[i],set_length[i],i);
		}
	}
	return;	
}

//returns n^exp
unsigned long long potenza(unsigned long int n,unsigned long int exp)
{
	if(exp == 0) return 1;
	else return n*potenza(n,exp-1);
}

//reset a given list of int putting all the N ints to -1
void reset(int *table,int N)
{
	int i;
	for(i=0;i<N;i++)
	{
		table[i] = -1;
	}
}

//returns the absolute value of the given int
int abs(int n)
{
	if(n<0)	return -n;
	else
		return n;
}

//prints the specified bucket of dimension = dim
void print_set(int bucket[],int dim)
{
	int i=0;
	printf("%i:",dim);
	for(i=0;i<dim;i++)
		printf("%i,",(int)bucket[i]);
	puts("");
}
