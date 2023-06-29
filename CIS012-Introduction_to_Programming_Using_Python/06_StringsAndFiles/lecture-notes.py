def newSection():
    print("\n")

# Strings
    # For Strings, + means concatenate
    # Strings can include numbers
    # Convert strings to integers using int()

str1 = "Hello"
str2 = "there"
str3 = str1 + str2
print(str3)

newSection()

# Looking inside strings
    # You can look at any single character in a string using an index
fruit = "banana"
letter = fruit[5]
print(letter)

newSection()

# Strings have length
    # Use len() to find the length of a string
fruit = "apple"
print(len(fruit))
print(fruit[len(fruit)-1])

newSection()

# Looping through strings
fruit = "orange"
index = 0
while(index < len(fruit)):
    letter = fruit[index]
    letter = str(index) + ": " + letter
    print(letter)
    index = index + 1

print("---")

index = 0
while(index < len(fruit)):
    if(index % 2 == 0):
        letter = fruit[index]
        print(letter)
    index = index + 1

print("---")

for letter in fruit:
    print(letter)

newSection()

#Slicing Strings
    # You can look at any continuous section of a string using a colon operator
    # The second number is one beyond the end of the slice - “up to but not including”
    # If the second number is beyond the end of the string, it stops at the end 
name = "Monty Python"
print(name[0:5])
print(name[6:7]) # This only prints 1 character
print(name[6:20]) # This one goes over the string length

newSection()

# Using in as a logical operator
    # With strings, the in keyword can be used to check if one string is included in another
fruit = "melon"
print("n" in fruit)
print("no" in fruit)
print("on" in fruit)

newSection()


# String Comparison
word = "baast"

if word == 'banana':
    print('All right, bananas.')

if word < 'banana':
    print('Your word,' + word + ', comes before banana.')
elif word > 'banana':
    print('Your word,' + word + ', comes after banana.')
else:
    print('All right, bananas.')

newSection()

#String Library
greet = "Hello Bob"
print(greet)

greet = greet.lower() # Makes all the characters lowercase
print(greet)

nameStart = greet.find(" ") # Find a character in a string
print(greet[(nameStart + 1):len(greet)].upper()) # Make all characters uppercase

greet = greet.replace("bob", "Jane") # Replace all occurances of the search string with the replacement string
print(greet)

greet = "   Hello Bob  "
print(greet)
greet = greet.lstrip() # Removes white space from the start of a string
print(greet)
greet = greet.rstrip() # Removes white space from the end of a string
print(greet)

print(greet.startswith("hello"))
print(greet.startswith("Hello"))

newSection()

# Parsing and extracting
data = 'From stephen.marquard@uct.ac.za Sat Jan  5 09:14:16 2008'
atPos = data.find("@") # Find the position of the @ symbol
print(atPos)
spacePos = data.find(" ", atPos) # Find the first space after the @
print(spacePos)
host = data[atPos+1:spacePos]
print(host)

## Files
    # Use the open() function to access files
file = open(r"C:\GitHub-Repositories\References\Python\CIS012-Introduction_to_Programming_Using_Python\06_StringsAndFiles\hello-world.txt")
print(file)

lineCount = 0
for line in file: # This will loop for as many lines as there are in file
    lineCount = lineCount + 1

print(lineCount, "lines in file")

newSection()

# You can read the contents of a file using the .read() function
file = open(r"C:\GitHub-Repositories\References\Python\CIS012-Introduction_to_Programming_Using_Python\06_StringsAndFiles\hello-world.txt")
content = file.read()
print(content)

newSection()

file = open(r"C:\GitHub-Repositories\References\Python\CIS012-Introduction_to_Programming_Using_Python\06_StringsAndFiles\hello-world.txt")
content = file.read()
print(content[:4]) # Print first 4 characters of the file

newSection()

# Print only certain lines from a file
mboxfile = open(r"C:\GitHub-Repositories\References\Python\CIS012-Introduction_to_Programming_Using_Python\06_StringsAndFiles\mbox.txt")

for line in mboxfile:
    line = line.rstrip() # Use .rstrip() to remove new lines from the end of a line
    if line.startswith("From: "):
        print(line)

newSection()

mboxfile = open(r"C:\GitHub-Repositories\References\Python\CIS012-Introduction_to_Programming_Using_Python\06_StringsAndFiles\mbox.txt")

for line in mboxfile:
    line = line.rstrip()
    if not "anthony" in line:
        continue
    print(line)


filename = input("Enter the file name: ")
try:
    filehandle = open(filename)
except:
    print("File cannot be opened", filename)
    quit() # You can exit a program with quit()

print("Success!")