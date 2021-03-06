#This module contains the functions used to produce the C code after the Generation of the perfect hash table

#Defines the name of the C file containing the Resulting code
name = "perfect_hash_table"
#from the name it creates the two strings identifier for both the C program file and the corresponding header
fileName = "../include/" + name + ".c"
headerName = "../include/" + name + ".h"

#Given the two tables (disambiguation and final table) prints them on the specified files located in the 
#target repository.
def printAll(dTable,table,dSize,size):
	"This function prints the whole C file directly inlining functions in the .h file"
	f = open(headerName,"w")
	#PHASE 1: Printing all the defines
	f.write("#include <stdint.h>\n")
	f.write("#define SIZE "+str(size)+"\n#define DSIZE "+str(dSize)+"\n")
	#PHASE 2: Printing the disambiguation Table
	dType = chooseType(dTable,dSize)
	f.write("static const " + dType +" disambiguationTable[DSIZE]= {"+str(dTable[0]))
	for i in range(1,dSize):
		f.write(","+str(dTable[i]))
	f.write("};\n")
	#PHASE 3: Printing the hashing Table
	Type = chooseType(table,size)
	f.write("static const " + Type+" table[SIZE]= {"+str(table[0]))
	for i in range(1,size):
		f.write(","+str(table[i]))
	f.write("};\n")  
	#PHASE 4: Printing the hashingFunction and lookUp 
	f.write("\nstatic inline uint32_t hashFunction(" + dType + " d,int rhs[],int rhs_size){\n\tuint32_t c=(uint32_t)d;\n\tint i = 0;\n\tif(d==0) (c=0x01000193);\n\tfor(i=0;i<rhs_size;i++) c =((c * 0x01000193)^rhs[i]) & 0xffffffff;\n\treturn c;\n}\n ")
	f.write("\nstatic inline " + Type  + " lookUp(int rhs[],int rhs_size){\n\t" + dType + " d = disambiguationTable[hashFunction(0,rhs,rhs_size)%DSIZE];\n\tif(d<0) return table[-d-1];\n\treturn table[hashFunction(d,rhs,rhs_size)%SIZE];\n}\n")
	f.close()
	#PHASE 5: Printing the whole header file (which is static)
#	p = open(headerName,"w")
#	p.write("#include <stdint.h>\n#define SIZE "+str(size)+"\n#define DSIZE "+str(dSize)+"\n")
#	p.write("\nuint32_t hashFunction("+dType+" d,int rhs[],int rhs_size);\n" + Type + " lookUp(int rhs[],int rhs_size);\n"+ dType + " disambiguationTable[DSIZE];\n"+Type+ " table[SIZE];\n")
#	p.close()

#This function is meant to select the cheaper int type that can be used to store the values of the table.
#The cheap quality is evaluated in terms of memory
def chooseType(table,size):
	"This function establish which kind of int is the minimum needed to represent that kind of data"	
	token = ""
	divisor = 2
	minimum = min_(table,size)
	if minimum >= 0 :
		token = token + "u"
		divisor = 1
	biggest = abs_max(minimum,max_(table,size))
	if (biggest < 2**16/divisor) : token = token + "int16_t "
	elif (biggest >= 2**32/divisor) : token = token + "int64_t "
	else : token = token + "int32_t "
	return token

#Finds the minimum in a table whose size is known
def max_(table,size):
	"find the max in the table"
	maximum = -1
	for i in range(size):
		if table[i] > maximum : maximum = table[i]
	return maximum

#Finds the minimum in a table whose size is known
def min_(table,size):
	"find the min in the table"
	minimum = 100000
	for i in range(size):
		if table[i] < minimum : minimum = table[i]
	return minimum

#Returns the value with the bigger magnitude
def abs_max(intero1,intero2):
	"returns the module of the biggest of the 2 ints"
	if(intero1 < 0) : intero1 = intero1 * (-1)
	if(intero2 < 0) : intero2 = intero2 * (-1)
	if(intero1 > intero2) : return intero1
	else : return intero2

