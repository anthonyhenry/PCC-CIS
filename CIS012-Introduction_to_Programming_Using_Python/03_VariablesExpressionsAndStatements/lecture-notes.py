# Python variable name rules
    # Must start with a letter or underscore
    # Must conist of letters, numbers, and underscores
    # Case sensiteve

# Constants vs Variables
print(123) #constant
a = 123 #variable
print(a)

print('\n')

# Expressions
    # Operator
        # +  | Addition
        # -  | Substraction
        # *  | Multiplication
        # /  | Division
        # ** | Power
        # %  | Remainer
    # Operator Precedence
        # Parenthesis
        # Power
        # Multiplication, Division, and Remainder
        # Addition and Subtraction
        # Left to Right
b = 1 + 2 ** 3 / 4 * 5
print('b =', b) # b = 11.0

print('\n')

# Variable types
    # Python can tell the difference between integer numbers and strings
    # We can ask Python what type something is by using the type function
c = 1 + 4
print(c) # Prints: 5
print('type(c) =', type(c))

print('\n')

d = 'hello ' + 'there'
print(d) # Prints: hello there
type(d)
print('type(d) =', type(d))

print('\n')

    # When you put an integer and floating point in an expression, the integer is implicitly converted to a float
    # You can contril this with the built in functions int() and float()
print(float(99) + 100)
print(99.0 + 100)

print('\n')

e = 42
print(e, type(e)) # Prints: <class 'int'>
f = 42.0
print(f, type(f)) # Prints: <class 'float'>
ef = e + f;
print('e + f =', ef, type(ef)) # Prints: <class 'float'>

print('\n')

    # Integer division always produces a floating point result
g = 10
print('g = 10', 'type(g):', type(g))
h = 2
print('h = 2', 'type(h):', type(h))
i = g/h
print('i = g/h', 'type(i):', type(i))

print('\n')

    #You can use int() and float() to convert between strings and integers
sval = '123'
print(type(sval)) # Prints: <class 'str'>

ival = int(sval)
print(type(ival)) # Prints: <class 'int'>

print('\n')

#User Input
    #You can instruct Python to pause and read data from user input with the input() function
    #This function returns a string

nam = input('Who are you?')
print('Welcome', nam)

print('\n')

#Elevator Conversion Program
eufloor = input('European floor number?')
usfloor = int(eufloor) + 1
print('US Floor:', usfloor)

print('\n')

# Exercise
# Write a program to prompt the user for hours and rate per hour to compute gross pay
hours = input('Enter Hours: ')
rate = input('Enter Rate: ')
pay = float(hours) * float(rate)
print('Pay:', pay)