#include <stdint.h>
#define SIZE 100
#define DSIZE 25
static const int16_t  disambiguationTable[DSIZE]= {3,9,1,-69,386,1,0,5,-41,13,31,67,1562,55,57,18,39,11,111,12,71,1176,31,173,201};
static const uint16_t  table[SIZE]= {68,69,32,41,62,15,31,44,40,73,79,88,45,23,71,43,37,55,78,80,61,19,87,11,21,84,93,28,60,18,14,12,39,83,72,92,10,67,98,82,47,65,1,27,70,16,29,20,25,76,3,48,74,90,54,63,30,24,89,91,33,85,35,81,99,36,53,95,7,86,22,50,77,57,8,52,9,56,66,5,100,6,34,64,17,46,26,97,51,13,75,49,58,4,2,42,94,96,38,59};

static inline uint32_t hashFunction(int16_t  d,int rhs[],int rhs_size){
	uint32_t c=(uint32_t)d;
	int i = 0;
	if(d==0) (c=0x01000193);
	for(i=0;i<rhs_size;i++) c =((c * 0x01000193)^rhs[i]) & 0xffffffff;
	return c;
}
 
static inline uint16_t  lookUp(int rhs[],int rhs_size){
	int16_t  d = disambiguationTable[hashFunction(0,rhs,rhs_size)%DSIZE];
	if(d<0) return table[-d-1];
	return table[hashFunction(d,rhs,rhs_size)%SIZE];
}
