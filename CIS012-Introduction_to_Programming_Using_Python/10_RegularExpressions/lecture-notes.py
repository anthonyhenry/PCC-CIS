def newSect():
    print("---")

# Regular Expression Quick Guide
# ^        Matches the beginning of a line
# $        Matches the end of the line
# .        Matches any character
# \s       Matches whitespace
# \S       Matches any non-whitespace character
# *        Repeats a character zero or more times
# *?       Repeats a character zero or more times (non-greedy)
# +        Repeats a character one or more times
# +?       Repeats a character one or more times (non-greedy)
# [aeiou]  Matches a single character in the listed set
# [^XYZ]   Matches a single character not in the listed set
# [a-z0-9] The set of characters can include a range
# (        Indicates where string extraction is to start
# )        Indicates where string extraction is to end

# Before you can use Regular Expressions, you need to import the regular expression library
import re # how to import the regular expression library

# You can use re.search() to see if a string matches a regular expression, similar to using the find() method for strings
test = input("Say something: ")

test2 = re.search('test', test)

print(test2)

newSect()

# If we actually want the matching strings to be extracted, we use re.findall()
x = 'My 2 favorite numbers are 19 and 42'
y = re.findall('[0-9]+',x)
print(y)

newSect()

# Greedy matching
    # The repeat characters (* and +) push outward in both directions (greedy) to match the largest possible string
x = 'From: Using the : character'
y = re.findall('^F.+:', x)
print(y)

newSect()

# Non-Greedy matching
    # Not all regular expression repeat codes are greedy!  If you add a ? character, the + and * chill out a bit...
x = 'From: Using the : character'
y = re.findall('^F.+?:', x)
print(y)

newSect()

teststring = "From Stephen.marquard@uct.ac.za"
find = re.findall('\S+@\S+', teststring)
print(find)

newSect()

# Parentheses can be used to tell where to start and stop what string to extract
find2 = re.findall('^From (\S+@\S+)', teststring)
print(find2)