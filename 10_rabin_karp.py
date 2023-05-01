# hash function 
    # a1 * 10^(m-1) + a2 * 10^(m-2) + a3 * 10^(m-3) .... 
    # Where m = len of pattern

# Rolling hash function
    # [ [ current_hash_value - a1 * 10^(m-1) ] * 10 ] + next_ele * 10^(m-3)
# Rolling hash function also called as rabin fingerprint function

# Time complexity
    # Average case = O (n - m + 1)
    # Worst case = O (mn)

# Worst case is when there are more spurious hits and the pattern has to be traversed manier times
import math
universe = {"a":1,"b":2,"c":3,"d":4,"e":5,"f":6,"g":7,"h":8,"i":9,"j":10}

def hash_function(trail,m):
    trail_hash = 0;
    for i in range(1,m+1):
        trail_hash += universe.get(trail[i-1]) * math.pow(10,m-i)

    return trail_hash

def rabin_karp(string, pattern):
    # Calculating the hash value of pattern
    m = len(pattern)
    pattern_hash = hash_function(pattern,m)

    for i in range(len(string)):
        p = string[i:m+i]
        if len(p) == m:
            hash_p = hash_function(p,m)
            if hash_p == pattern_hash:
                if pattern == p:
                    return i
                else:
                    print("Spurious hit!")
        else:
            return False



    

string = "ccaccaaeaba"
pattern = "dba"


index = rabin_karp(string,pattern)
if index:
    print(f'The value was found on index {index}')
else:
    print("Pattern was not found in the string!")
