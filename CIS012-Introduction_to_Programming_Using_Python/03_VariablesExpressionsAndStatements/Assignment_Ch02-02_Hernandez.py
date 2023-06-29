num1 = 125
num2 = 28
num3 = -25

# The round() function returns a floating point value with the given number of decimals
# round() takes two arguments round(number, digits)
# number - the number to be rounded
# digits - Up to how many decimals the number needs to be rounded
average = round(((num1 + num2 + num3) / 3) , 2)

#average = (num1 + num2 + num3) / 3
#average = round(average, 2)

# The str() function converts a variable to a string
print("num1 is " + str(num1) + ".\n")
print("num2 is " + str(num2) + ".\n")
print("num3 is " + str(num3) + ".\n")
print("The average of num1, num2, and num3 is " + str(average) + ".")