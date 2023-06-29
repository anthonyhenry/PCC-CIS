# Store reusable pieces of code in a function
# Use the def keyword to create a function
    # Do not give your function the same name as a variable
    # Indent the body of your function
    # You must call your function somewhere in your code in order for it to run

def print_lyrics():
    print("I'm a lumberjack, and I'm okay.")
    print("I sleep all night and I work all day")

print("Function has not run yet")
print("Function will run now")
print_lyrics() # Function call
print("Let's run the function again!")
print_lyrics()

print("\n")

# Void (non-fruitful) Functions
    # When a function does not return a value, we call it a void function

def newLine():
    print("\n")

# Parameters
    # A parameter is a variable used in a function definition
    # Function calls pass arguments to fill function parameters

def greet(lang): # Function with a parameter called "lang"
    if lang == "es":
        print("Hola")
    elif lang == "fr":
        print("Bonjour")
    else:
        print("Hello")

# Function calls with arguments
greet("es")
greet("fr")
greet("en")

newLine()

# Return Values
    # Often a function will do some computation with its arguments and return a value to be used in the calling expression
    # The return keyword is used to return values in a function
    # Return statemnts end the function exection
def advancedGreeting(lang):
    if lang == "es":
        return "Hola"
    elif lang == "fr":
        return "Bonjour"
    else:
        return "Hello"
    
print(advancedGreeting("en"), "Glen")
print(advancedGreeting("es"), "Sally")
print(advancedGreeting("fr"), "Michael")

newLine()

# Multiple Parameters/Arguments
    # You can definde more than one parameter in the function definition
    # Seperate additional parameters with a comma

def addtwo(a, b):
    return a + b

print(addtwo(3, 5))

newLine()

# Loops and Iterations
    # You can repeat steps of code with loops
    # Loops have iteration variables that change throughout the loop to control how long the loop lasts
    # Always remember to alter your iteration variables so that you do not create an infinite loop

# The While Loop
n = 5
while n > 0: # Loop to countdown from 5
    print(n)
    n = n - 1
print("Blastoff!") # Say "Blastoff" when the loop finishes

newLine()

# Breaking out of a loop
    # The break statement ends the current loop and jumps to the statement immediately following the loop

print("Type 'done' to exit the loop")
while True: # This loop will always be true
    line = input("> ")
    if(line == "done"):
        break # Only if the user types "done" will break out of the loop
    print(line)
print("Done!")

newLine()

# Finishing an iteration with continue
    # The continue statement ends the current iteration and jumps to the top of the loop and starts the next iteration

print("Type 'done' to exit the loop. Start your input with a ! to not have it repeated back to you")
while True:
    line = input('> ')
    if line[0] == '!' : # This checks if the first character in the input is a '!'
        continue
    if line == 'done' :
        break
    print(line)
print('Done!')

newLine()

# For Loops

for i in [5, 4, 3, 2, 1]:
    print(i)
print("Blastoff")

newLine()

# A for loop using range
for i in range(0,5):
    print(i)

print("----")

for i in range(0,5):
    print(5-i)
print("Blastoff!")

newLine()

#C-style for loop
for index in range(0,5):
    print("index = ", index)

newLine()

# A for loop with strings
friends = ["Joseph", "Glen", "Sally"]
for friend in friends:
    print("Happy New Year", friend)

newLine()

# Looping through a set
print('Before')
for thing in [9, 41, 12, 3, 74, 15] :
     print(thing)
print('After')

# Find the largest number
largestSoFar = None # None is a keyword meaning the variable has no value
for i in [9, 41, 12, 3, 74, 15]:
    print(i)
    if largestSoFar == None:
        largestSoFar = i
    elif i > largestSoFar:
        largestSoFar = i
print("Largest number in the set is", largestSoFar)

newLine()

# Counting in a loop
loopNum = 0
print('Before', loopNum)
for thing in [9, 41, 12, 3, 74, 15] :
    loopNum = loopNum + 1
    print(loopNum, thing)
print('After', loopNum)

newLine()

# Summing in a loop
loopSum = 0
for number in [9, 41, 12, 3, 74, 15] :
    loopSum = loopSum + number
    print("+", number)
print("----")
print(loopSum)

newLine()

#Finding the average in a loop
count = 0
sum = 0
for number in [9, 41, 12, 3, 74, 15] :
    print(number)
    count = count + 1
    sum = sum + number
average = sum/count
print("average:", average)

newLine()

# Filtering in a loop
print('Before')
for value in [9, 41, 12, 3, 74, 15] :
    if value > 20:
 	    print('Large number',value)
print('After')

newLine()

# Search using a Boolean
found = False
for number in [9, 41, 12, 3, 74, 15] :
    print(number)
    if(number == 3):
        found = True
        break
print("Found the number 3!")