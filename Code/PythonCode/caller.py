import os
import sys

if(len(sys.argv) < 3) :
	print("Invalid argument exception: first argument must be the number of keys, second the dimension of the indexing table in percentage with respect to the total size")
	sys.exit()

numberOfKeys = sys.argv[1]
percentageSize = sys.argv[2]

token = " python generator.py " + numberOfKeys + " > dictionaries.py"
os.system(token)
token2 = " python buckets2.py " + percentageSize
os.system(token2)
