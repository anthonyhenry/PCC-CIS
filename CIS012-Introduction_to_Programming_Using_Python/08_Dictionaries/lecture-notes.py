def newSect():
    print("---")

# Dictionaries are a collection
    # Dictionaries are not organized collections like lists
    # Items in a Dictionary come in key, value pairs

# Creating a dictionary
purse = dict()
purse["money"] = 12 # dict['key] = value
purse["candy"] = 3
purse["tissues"] = 75 

print(purse)

purse["money"] = 25

print(purse)

newSect()

# Dictionary literals
    # Another way to make a Dictionary
ages = {"chuck" : 55, "fred" : 42, "jan" : 32}
print(ages)

newSect()

# You can create an empty Dictionary
foo = {}
print(foo)
ooo = dict() # Or like this
print(ooo)

newSect()

# Histogram for the most common name
names = dict()
names["hank"] = 1
names["chen"] = 1
names["chen"] = names["chen"] + 1 # You can increment dictionary values like this
print(names)

newSect()

# This is how you check if a key exists in a dictionary and create it if not
counts = dict()
names = ["Zhen", "Chad", "Geoff", "Geoff", "Ashe"] # These values can be read in from a file
for name in names:
    if name not in counts:
        counts[name] = 1
    else:
        counts[name] = counts[name] + 1
print(counts)

newSect()

# The get() method for dictionaries
    # The get() method collapses the above code into one line
    # get() method checks if a key exists in a dictionary. If it does, it gets the value for that key. If it doesn't it creates the key with the default value
    # dictName.get(key, defaultValue)
newCounts = dict()
moreNames = ["Greg", "Dobby", "Job", "Celine", "Celine", "Peter", "Dobby", "Peter", "Parker"]
for name in moreNames:
    newCounts[name] = newCounts.get(name, 0) + 1
print(newCounts)

newSect()

# Definite loops and dictionaries 

# This program takes in user input then creates a dictionary of how many times each word appeared
counts = dict()
print('Enter a line of text:')
line = input('')

words = line.split()

print('Words:', words)

print('Counting...')
for word in words:
    counts[word] = counts.get(word,0) + 1
print('Counts', counts)

newSect()

# Dictionaries do not always have the same order
counts = {"chuck": 1, "fred" : 42, "jan" : 100}
for key in counts:
    print(key, counts[key])

newSect()

# You can retrieve just the keys or just the values or both from a dictionary
jjj = { 'chuck' : 1 , 'fred' : 42, 'jan': 100}
print(list(jjj))
print(list(jjj.keys()))
print(list(jjj.values()))
print(list(jjj.items()))

# Two iteration variables and items
for key,value in jjj.items():
    print(key, value)

newSect()

# Program to find the word that occurs the most in an input

entry = input("Type something, and I will tell you word appeared most: ")

wordCounts = dict()
words = entry.split()

for word in words:
    wordCounts[word] = wordCounts.get(word, 0) + 1

bigcount = None
bigword = None
for word,count in wordCounts.items():
    if bigcount is None or count > bigcount:
        bigword = word
        bigcount = count

print("Most frequent word:", bigword, "-", bigcount)