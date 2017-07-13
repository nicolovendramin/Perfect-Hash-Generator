import sys
import dictionaries
import cfileprinter
numericDictionary = dictionaries.dictionary
lhsides = dictionaries.testCases



#DICTIONARY = "/usr/share/dict/words"
#TEST_WORDS = sys.argv[1:]
#if len(TEST_WORDS) == 0:
#    TEST_WORDS = ['hello', 'goodbye', 'dog', 'cat']
Gsize = int((int(sys.argv[1])*len(numericDictionary))/100)
print("Size of the disambiguation table : %d" %Gsize)

# Calculates a distinct hash function for a given string. Each value of the
# integer d results in a different hash value.
def hashFunction( d, listInt ):
    if d == 0: d = 0x01000193

    # Use the FNV algorithm from http://isthe.com/chongo/tech/comp/fnv/ 
    for c in listInt:
        d = ( (d * 0x01000193) ^ int(c) ) & 0xffffffff;

    return d

# Computes a minimal perfect hash table using the given python dictionary. It
# returns a tuple (G, V). G and V are both arrays. G contains the intermediate
# table of values needed to compute the index of the value in V. V contains the
# values of the dictionary.
def CreateMinimalPerfectHash( dictionary ):
    size = len(dictionary)

    # Step 1: Place all of the keys into buckets
    buckets = [ [] for i in range(size) ]
    G = [0] * Gsize
    values = [None] * size
    
    for key in dictionary.keys():
        buckets[hashFunction(0, list(key)) % Gsize].append( key )

    # Step 2: Sort the buckets and process the ones with the most items first.
    buckets.sort( key=len, reverse=True )        
    for b in xrange( Gsize ):
        bucket = buckets[b]
        if len(bucket) <= 1: break
        
        d = 1
        item = 0
        slots = []

        # Repeatedly try different values of d until we find a hash function
        # that places all items in the bucket into free slots
        while item < len(bucket):
            slot = hashFunction( d, bucket[item] ) % size
            if values[slot] != None or slot in slots:
                d += 1
                item = 0
                slots = []
            else:
                slots.append( slot )
                item += 1

        G[hashFunction(0, bucket[0]) % Gsize] = d
        for i in range(len(bucket)):
            values[slots[i]] = dictionary[bucket[i]]

        if ( b % 1000 ) == 0:
            print "bucket %d    r" % (b),
            sys.stdout.flush()

    # Only buckets with 1 item remain. Process them more quickly by directly
    # placing them into a free slot. Use a negative value of d to indicate
    # this.
    freelist = []
    for i in xrange(size): 
        if values[i] == None: freelist.append( i )

    for b in xrange( b, Gsize ):
        bucket = buckets[b]
        if len(bucket) == 0: break
        slot = freelist.pop()
        # We subtract one to ensure it's negative even if the zeroeth slot was
        # used.
        G[hashFunction(0, bucket[0]) % Gsize] = -slot-1 
        values[slot] = dictionary[bucket[0]]
        if ( b % 1000 ) == 0:
            print "bucket %d    r" % (b),
            sys.stdout.flush()

    return (G, values)        

# Look up a value in the hash table, defined by G and V.
def PerfectHashLookup( G, V, key ):
    d = G[hashFunction(0,key) % len(G)]
    if d < 0: return V[-d-1]
    return V[hashFunction(d, key) % len(V)]

print "Reading words"
#dictionary = {}
#line = 1
#for key in open(DICTIONARY, "rt").readlines():
#    dictionary[key.strip()] = line
#    line += 1
dictionary = numericDictionary
print "Creating perfect hash"
(G, V) = CreateMinimalPerfectHash( dictionary )

print "Disambiguation Table. size : %d" % len(G)
print(G)

print "Hashing Table. size : %d" % len(V)
print(V)
failures = 0
for lhs in lhsides:
	if (PerfectHashLookup(G,V,lhs)!=dictionary[lhs]) :
		print("Failed Test!")
		failures = failures + 1
		
print("Failures encountered : %d " %failures)

cfileprinter.printAll("disambiguationTable",G,len(G),"table",V,len(V))
if(len(G)==len(V)):
	number = 0
	for i in G:
		if(i==0) : number = number + 1
	print(len(G)-number)
