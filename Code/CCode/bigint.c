#include <stdio.h>
#include <stdlib.h>

void byteTranslation(int number,char *result);
void twoBytecarry(char *a,char *b,char *carry);
void twoBytesum(char *a,char *b,char *result);

//the first 2 char represent the lenght of the string, the chars between the third and the end of the string represent the concatenation
//of the list of int
char *translate(int *list,int list_size)
{
	int iterator;
	char *result = malloc((2+2*list_size)*(sizeof(char)));
	byteTranslation(list_size,result);
	for(iterator=0;iterator<list_size;iterator++)
		byteTranslation(list[iterator],&result[iterator*2+2]);
	return result;
}

int max(int a,int b)
{
	if(a>=b) return a;
	else return b;
}
//byte translation --> input 2 ints < 10000 and a 2 char string where to write the representation in bytes of the ints
void byteTranslation(int number,char *result)
{
	result[1] = (number/256)%256;
	result[0] = (number%256);
}

int twoBytestoInt(char *number)
{
	return number[1]*256+number[0];
}
//sums 2 strings
char *sum(char *a,char *b)
{
	int iterator;
	char *result;
	char *carry;
	char temp[2];
	char temp2[2];
	char temp3[2];
	byteTranslation(0,carry);
	int sizea,sizeb;
	sizea = twoBytestoInt(a);
	sizeb = twoBytestoInt(b);
	result = malloc((max(sizea,sizeb)+4)*sizeof(char));
	for(iterator = 0;iterator < max(sizea,sizeb);iterator = iterator+2)
	{
		twoBytesum(&a[iterator+2],&b[iterator+2],temp);	
		twoBytesum(temp,carry,&result[iterator+2]);
		twoBytecarry(carry,temp,temp2);
		twoBytecarry(&a[iterator+2],&b[iterator+2],temp3);
		twoBytesum(temp2,temp3,carry);
	}

}


void twoBytecarry(char *a,char *b,char *carry)
{
	byteTranslation((twoBytestoInt(a)+twoBytestoInt(b))/(256*256),carry);
	return;
}

//returns a two char representing the sum with no carry
void twoBytesum(char *a,char *b,char *result)
{
	byteTranslation(twoBytestoInt(a)+twoBytestoInt(b),result);
	return;
}

void print_big_int(char *integer)
{
	int size = twoBytestoInt(integer);
	int i,j=0;
	for(i=0;i<size;i++)
	{
		j = twoBytestoInt(&integer[i*2+2]);
		printf("%i%i%i%i",(j/1000),(j/100)%10,(j/10)%10,j%10);
	}
	printf("Eccomitroia");
}

int main()
{
	int *ciccio = malloc(2*sizeof(int));
	ciccio[0] = 1111;
	ciccio[1] = 1111;
	int *porcoddio = malloc(2*sizeof(int)); 
	porcoddio[0] = 123;
	porcoddio[1] = 232;
 	printf("Diocan qui ghe rivo");
	print_big_int(translate(ciccio,2));
	printf("merda\n");
	print_big_int(translate(porcoddio,2));
//	print_big_int(sum(translate(ciccio,2),translate(porcoddio,2)));
}
