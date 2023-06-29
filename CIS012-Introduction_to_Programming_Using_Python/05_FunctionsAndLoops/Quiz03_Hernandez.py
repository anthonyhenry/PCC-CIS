# Write a function called Apple that prints "Apples are good".

# Write a function called Orange that prints "Oranges are delicious". 

# From your main Python program call the Apple function once and the Orange function twice.

def Apple():
    print("Apples are good")

def Orange():
    print("Oranges are good")

Apple()
Orange()
Orange()

# Write a function called InfoOnNumbers that receives two arguments, both integers and prints both of them.

# Call this function from your main python program twice. The first time pass it 5 and 6, the second time, pass it 17 and 18.

def InfoOnNumbers(num1, num2):
    print(num1, num2)

InfoOnNumbers(5, 6)
InfoOnNumbers(17, 18)

# Write a function that returns the number 6 called myFunction.

# Call this function from your main Python program twice and each time print what it returns.

def myFunction():
    return 6

print(myFunction())
print(myFunction())

# Write a function that receives two integers called Summed.

# This function is to add the two arguments it receives and return their sum.

# Call this function from your main Python program, pass it 5 and 6 and assign what it returns to the variable x.

# Print the variable x.

# Call this function again from your main Python program, this time from inside a print statement and pass it 24 and 25. So the print statement will end up printing the sum of 24 and 25.

def Summed(num1, num2):
    return num1 + num2

x = Summed(5,6)
print(x)

print(Summed(24,25))