def newSect():
    print("---")

# A collection allows you to put many values in a single variable

friends = ["Joseph", "Glenn", "Sally"]
carryon = ["socks", "shirt", "perfume"]

print([1, 24, 76])
print(['red', 'yellow', 'blue'])
print(['red', 24, 98.6])
print([ 1, [5, 6], 7])
print([])

newSect()

# Lists and Definite Loops

for friend in friends:
    print("Happy New Year", friend)

for item in carryon:
    print("I'm bringing", item)

newSect()

# Looking inside lists
print(friends[1])

newSect()

# Lists are mutable - you can change an element of a list using the index operator

lotto = [2, 14, 26, 41, 63]
print(lotto)
lotto[2] = 28
print(lotto)

# Finding the length of a list
    # Use len() to find the length of a list
print(len(lotto))

newSect()

# Using the range function with 
print(range(4))
friends = ['Joseph', 'Glenn', 'Sally']
print(len(friends))
print(range(len(friends)))  # Does not print what is expected

newSect()

# Lists can be concatenated
a = [1, 2, 3]
b = [4, 5, 6]
c = a + b
print(c)
print(a)

newSect()

# Lists can be sliced using ":"
t = [9, 41, 12, 3, 74, 15]
print(t[1:3])
print(t[:4])
print(t[3:])
print(t[:])

newSect()

# Checking a list
some = [1, 9, 21, 10, 16]
if 9 in some:
    print("9 is in the list")
if 20 not in some:
    print("20 is not in the list")

newSect()

# Sorting lists using .sort()
print(friends)
print(friends[1])
friends.sort() # This overwrites the list
print(friends)
print(friends[1])

newSect()

# Some hand list functions
nums = [3, 41, 12, 9, 74, 15]
print(len(nums))
print(max(nums))
print(min(nums))
print(sum(nums))
print(sum(nums)/len(nums))

newSect()

# Adding to a list
numlist = list()
numlist.append(1)
print(numlist)
numlist.append(12)
print(numlist)
numlist.append(72)
print(numlist)
numlist.append(4)
print(numlist)
