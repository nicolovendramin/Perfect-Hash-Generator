import os
import sys


arguments = [" 10 "," 100 "," 250 "," 500 "," 1000 "," 2000 "," 2500 "," 5000 "," 7500 "," 8000 "," 9000 "," 10000 "]
for i in range(0,12):
	
	token = "python generator.py " + arguments[i] + " > dictionaries.py"
	print("TIME TEST " + str(i+1))
	os.system(token)
	os.system("time python buckets2.py 25")
	
