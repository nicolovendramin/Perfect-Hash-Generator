#This module is meant to generate a dictionary (in Python style) in which the keys are lists of ints (the right hand sides) and the values are the corresponding left hand sides.
#Done this the module generates another dictionary of test cases (a subset of the initial dictionary) in C style to be used in a C program as a TestSuite

import sys
import struct


#Definition of the names of the Python and C file containing respectively the Dictionary and the Set of test Cases
pythonDictionary = "dictionary.py"
cTestCaseFile = "target/testCases.c"


#The number of keys to be generated is given as input parameter.
numberOfKeys = int(sys.argv[1])
keyLenghts = []
keySet = []
leftHandSides = []

#This function prints the randomly generated set of keys as a python dictionary
def printAsDictionary():
	dictionary = open("dictionary.py","w")
	dictionary.write("dictionary = {")
	for i in range(numberOfKeys):
		dictionary.write("("),
		for j in range(len(keySet[i])):
			dictionary.write(str(keySet[i][j]))
			if(j==len(keySet[i])-1) : dictionary.write(")")
			else : dictionary.write(",")
		dictionary.write(" : "),
		leftHandSides.append(i+1)
		dictionary.write(str(i+1))
		if(i != numberOfKeys-1) : dictionary.write(",")
	dictionary.write("}\n")

def printTestCases():
	"This function prints all the rhs in a c table"
	testCases = open(cTestCaseFile,"w")
	h = 0
	for i in range(numberOfKeys):
		for j in range(0,keyLenghts[i]):
			h  = h+1
	testCases.write("int testCases["+ str(h) + "] = {" + str(keySet[0][0]))
	for i in range(numberOfKeys):
		for j in range(0,keyLenghts[i]):
			if(i!=0 or j!=0):	
				testCases.write("," + str(keySet[i][j]))
	testCases.write("};\nint testCasesLenghts[" + str(numberOfKeys) + "] = {" + str(keyLenghts[0]))
	for i in range(1,numberOfKeys):
		testCases.write("," + str(keyLenghts[i]))
	testCases.write("};\nint *getTestCases(){\nreturn testCases;\n}\nint *getLenghts(){\nreturn testCasesLenghts;\n}\nint getNumberOfCases(){\nreturn " + str(numberOfKeys) + ";\n}\n")
	testCases.close()
	testCases = open("target/testCases.h","w")
	testCases.write("int *getTestCases();\nint *getLenghts();\nint getNumberOfCases();")

	
#This is the function which provides the very creation of the random set of keys.
#The number of keys that are randomly chosen is the one received as input parameter
def generateRandomSet():
	"This function initialize the set with values coming from the Linux Random Device"
	MAX = 10
	diml = 0
	_randomSource = open("/dev/urandom","rb")
	for i in range(0,numberOfKeys):
		bytes =	_randomSource.read(4)
		keyLenghts.append((struct.unpack("I",bytes)[0]%(MAX))+1)
		keySet.append([])
		for j in range(0,(keyLenghts[i])):
			bytes = _randomSource.read(4)
			keySet[i].append(struct.unpack("I",bytes)[0]%(3*numberOfKeys))


generateRandomSet()
printTestCases()
printAsDictionary()
print("All work done")			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
						
			
