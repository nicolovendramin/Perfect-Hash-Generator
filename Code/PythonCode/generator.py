import os
import struct
import time
import cfileprinter
import math
import sys

numberofKeys = int(sys.argv[1])
if(numberofKeys) == 0 : 
	numberofKeys = 100 #Total number of keys to be hashed
loosePercentage = 0 #Percentage additional space given to store the table
disambiguationTable = []
dtableLength = max(int(numberofKeys)/10,20)
tableSize = (numberofKeys + (numberofKeys*loosePercentage/100))
table = []
keySet = []
testCases = []
parameters = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
listatocheck = []
listdim = 0

for num in range(0,tableSize):
	table.append(-1)
for num in range(0,dtableLength):
	disambiguationTable.append(0)

#returns a list of N random ints in the interval between 0 and MAX 
def generateRandomSet():
	"This function initialize the set with values coming from the Linux Random Device"
	MAX = 10
	diml = 0
	_randomSource = open("/dev/urandom","rb")
	for i in range(0,numberofKeys):
		bytes =	_randomSource.read(4)
		rhsLength = (struct.unpack("I",bytes)[0]%(MAX))+2
		keySet.append([])
		for j in range(0,(rhsLength)):
			bytes = _randomSource.read(4)
			keySet[i].append(struct.unpack("I",bytes)[0]%3*numberofKeys)
		
	
#Prints a Set given its length
def printSet(anySet,setLength):
	"Just take a set of a certain lenght and prints it"
	for i in range(0,setLength):
		print(anySet[i])


#Randomizes the parameters used to build the hashing functions including the values contained in the disambiguation table
def randomize(inter):
	"No parameters, just acts on the list -parameters-"
	_randomSource = open("/dev/urandom","rb")
	for i in range(0,28):
		bytes = _randomSource.read(4)
		parameters[i] = struct.unpack("I",bytes)[0]
	if(inter==2):
		for i in range(0,dtableLength):
			bytes = _randomSource.read(4)
			disambiguationTable[i] = struct.unpack("I",bytes)[0]
	return 

def reset():
	""
	for i in range(0,tableSize):
		table[i] = -1

#Gives a single big Number from a list of integers
def intConcat(listofInts):
	"Takes a list of ints and gives back a very big int"
	i = 0 
	t = 0
	for j in listofInts:
		t = t + j*(10**(5*i))
		i = i+1			
	return t;

def printAsDictionary(keySet,numberOfKeys):
	print("{"),
	for i in range(numberOfKeys):
		print("("),
		for j in range(len(keySet[i])):
			print(keySet[i][j]),
			if(j==len(keySet[i])-1) : print(")"),
			else : print(","),
		print(" : "),
		print(i+1),
		if(i != numberOfKeys-1) : print(","),
	print("}")
		

def firstHash(rhsAsInt):
	"Takes the rhs already converted into bigint and gives back the corresponding value of the disambiguation table"
	h = 0
	for i in range(0,14):
		h = h + parameters[i] * (rhsAsInt**i)	
	return disambiguationTable[h%dtableLength]

def secondHash(disambiguationValue,rhsAsInt):
	"Takes the two values, makes one single and then calculates a second value"
	h = 0
	var = rhsAsInt%(disambiguationValue+1)
	for i in range(14,28):
		h = h + parameters[i] * (var**i)
	
	return h%tableSize

def lookUp(rhs,key):
	"Executes the lookup of the value of a rhs, returns 1 if found it empty 0 otherwise"
	b = intConcat(rhs)
	a = secondHash(firstHash(b),b)
	print("accessing index ")
	print(a)
	if(table[a] == -1) :
		table[a] = key
		return 1
	else :
		print(str(table[a]) + " "  + str(rhs))
		return 0

def selectTestCases():
	"Selects automatically some keys for the lookup"
	number = 0
	print("{"),
	for i in range(len(keySet)):
		if keySet[i][int((len(keySet[i]))/2)]%2 == 0 : 
			if(number == 0) : 
				print("("),
				number = 2
			else : print(",("),
			for j in range(len(keySet[i])) : 
				print(keySet[i][j]),
				if(j == len(keySet[i])-1) : print(")"),
				else : print(","),
	print("}")	
				
			


generateRandomSet()
print("dictionary = "),
printAsDictionary(keySet,numberofKeys)
print("\ntestCases = "),
selectTestCases()
#printSet(keySet,numberofKeys)
#raw_input("Press Enter to go on")
#iterator = 0
#cicle = 1
#while(iterator < numberofKeys/2):
#	iterator = 0
#	print("cicle number: ")
#	print(cicle)
#	cicle = cicle + 1
#	randomize(cicle)
#	reset()
#	cfileprinter.printTable(disambiguationTable,dtableLength)
#	for i in range(0,numberofKeys):
#		if(lookUp(keySet[i],i) == 0): break
#	printSet(table,tableSize)
#	printSet(disambiguationTable,dtableLength)
#	print("number of success: ")
#	print(i)
#	#time.sleep(2)
#print("Found the functions for MPHT") 
