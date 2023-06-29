# If Statements
x = 5
if x < 10:
    print('Smaller')
if x > 20:
    print('Bigger')

print("\n")

# Conditional Operators
if x == 5 : 
    print('Equals 5')
if x > 4 : 
   print('Greater than 4')
if  x >= 5 :
    print('Greater than or Equals 5')
if x < 6 : 
    print('Less than 6') 
if x <= 5 :
    print('Less than or Equals 5')
if x != 6 :
    print('Not equal 6')

print("\n")

# Indentation
    # Indentation is important
    # Indent after if and for statments
    # Indents are 4 spaces
    # All lines at the same indent level are apart of the same block and affected by the same if/for statment preceding
    # If you only need one line in a block you can keep it in line with the if/for statement
if x == 5: print("X is 5")
if x > 2:
    print("Bigger than 2")
    print("Still bigger")

print("\n")

# Nested If Statments
if x > 1 :
    print('More than one')
    if x < 100 : 
        print('Less than 100') 
print('All done')

print("\n")

# Two Way Decisions
if x > 2 :
    print('Bigger')
else :
    print('Smaller')
print('All done')

print("\n")

# Multi-way Branch
    # if, elif, and else
x = 0 
print('x = 0')
if x < 2 :
    print('small')
elif x < 10 :
    print('Medium')
else :
    print('LARGE')

x = 5
print('x = 5')
if x < 2 :
    print('small')
elif x < 10 :
    print('Medium')
else :
    print('LARGE')

x = 12
print('x = 12')
if x < 2 :
    print('small')
elif x < 10 :
    print('Medium')
else :
    print('LARGE')

print("\n")

# You can have as many elifs as needed
if x < 2 :
    print('Small')
elif x < 10 :
    print('Medium')
elif x < 20 : 
    print('Big')
elif x < 40 : 
    print('Large')
elif x < 100:
    print('Huge')
else :
    print('Ginormous')

print("\n")

# try/except Structure
    # You can surround code that might crash with try and except
astr = 'Hello Bob'
try:
    istr = int(astr) # This fails because you can't turn a string into an integer
except:
    istr = -1 # Instead stopping the program and outputting an error, this except path will activate
print('First', istr)

astr = '123'
try:
    istr = int(astr)
except:
    istr = -1
print('Second', istr)

# Best practice to only put 1 or very few lines in a try statement because lines following the failing line will not run
astr = 'Bob'
try:
    print('Hello')
    istr = int(astr)
    print('There') # This code will never run, because the try statement fails before ever getting here 
except:
    istr = -1
print('Done', istr)