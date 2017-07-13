MODS TO DO ->
DEFINE ALL FIRST
RETURN TYPES MUST BE THOUGHT BETTER
NAME OF THE TABLES MUST BE DEFINES SO THAT EVERYWHERE I HAVE TO PRINT THAT NAME I PRINT THE RIGHT ONE

def printTable2(name,lhs,size,max_,which):
	"Checks which integer type is the minimum to represent all the integers needed"
	token = getIntegerType(max_)
	if(which == 0) : token2 = "SIZE"
	else : token2 = "DSIZE"
	f = open("table.c","a")
	f.write("define " + token2 + " " + str(size) + ";\n")
	f.write(token + name +  "[" + token2 + "] = {" + str(lhs[0]))
	for i in range(1,size):
		f.write("," + str(lhs[i]))
	f.write("};\n")
	f.close()

def printTable(name,lhs,size,which):
	"Receives a list of numbers and prints it formatting like a c-like table"
	max_ = _max(lhs,size)
	printTable2(name,lhs,size,max_,which)

def printAll(name1,lhs,size,name2,lhs2,size2):
	printTable(name1,lhs,size,1)
	printTable(name2,lhs2,size2,0)
	printFunction(lhs2,size2)

def getIntegerType(integer):
	"Takes as input a number and returns the token corresponding to the minimum int size necessary to represent it"
	if(integer < 2**16): return  "unsigned short int "
	elif(integer >= 2**32) : return "unisgned long int "
	else : return "unsigned int "

def _max(lhs,size):
	max1 = -1
	for i in range(size):
		if(lhs[i]>max1) : max1 = lhs[i]
	return max1	
		

def printFunction(lhs,size):
	"This prints the hashing function in c"
	token = getIntegerType(_max(lhs,size))
	f = open("table.c","a")
	f.write("\n" + token + " hashFunction(int d,int rhs[],int rhs_size){\n\tlong unsigned int c=(long unsigned int)d;\nint i = 0;\n\tif(d==0) (c=0x01000193);\n\tfor(i=0;i<rhs_size;i++) c =((c * 0x01000193)^lhs[i]) & 0xffffffff;\nreturn c;} ")
	f.write("\n" + token + " lookUp(int rhs[],int rhs_size){\n\t " + getIntegerType(size) + " d = (" + getIntegerType(size) + ")hashFunction(0,rhs,rhs_size);\nif(d<0) return table[-d-1];\nreturn table[hashFunction(d,rhs,rhs_size)];}\n")
	

