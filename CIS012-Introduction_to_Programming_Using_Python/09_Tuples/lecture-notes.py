# Tuples
    # Tuples are like lists but they are immutable - you cannot alter the contents of a tuple
    # The only functions you can use with a tuple are count and index
t = tuple()
print(dir(t))

print("---")

# Tuples and Assignment
    # You can use tuples to assignments
(x, y) = (4, 'fred')
print(y)

(a, b) = (99, 98)
print(a)

print("---")

# Tuples and Dictionaries
    # The items() method for dictionaries returns a list of key,value tuples 
d = dict()
d['csev'] = 2
d['cwen'] = 4
print(d)
for (k, v) in d.items():
    print(k, v)

tups = d.items()
print(tups)

print("---")

# Comparing Tuples
    # The comparison operators work with tuples and other sequences. 
    # If the first item is equal, Python goes on to the next element,  and so on, until it finds elements that differ.
print((0, 1, 2) < (5, 1, 2))
print((0, 1, 2000000) > (0, 3, 4))
print(( 'Jones', 'Sally' ) < ('Jones', 'Sam'))
print(( 'Jones', 'Sally') < ('Adams', 'Sam'))

print("---")

# Sorting lists of tuples
    # We can take advantage of the ability to sort a list of tuples to get a sorted version of a dictionary
    # First we sort the dictionary by the key using the items() method and sorted() function
d = {'a':10, 'c':22, 'b':1}
print(d.items())
print(sorted(d.items()))

# Sorting by values instead of key
c = {'a':10, 'b':1, 'c':22}
tmp = list() # Create a blank list
for k, v in c.items() :
    tmp.append( (v, k) ) # Create a list of value-key pairs

print(tmp)
tmp = sorted(tmp, reverse=True) # Sort the value-key pair list fromm largest to smmallest value
print(tmp)
