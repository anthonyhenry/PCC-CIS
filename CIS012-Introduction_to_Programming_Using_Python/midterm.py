# Write a python program that prompts the user for three integers, then uses ONLY a conditional (if, else ...) and prints if each number is divisible by 7.
# For example, if the user enters 42, 12 ,99
# Your code should print:
# 42 is divisible by 7
# 12 is not divisible by 7
# 99 is not divisible by 7

print("Please provide 3 integers")
num1 = int(input("> "))
num2 = int(input("> "))
num3 = int(input("> "))

def multipleOf7(number):
    if(number % 7 == 0):
        print(number, "is divisible by 7")
    else:
        print(number, "is not divisible by 7")

multipleOf7(num1)
multipleOf7(num2)
multipleOf7(num3)

# Write a python program that uses a while loop to print the sum of all integers divisible by 7, but not divisible by 2, from 1 to 2000.

number = 1
sum = 0

while number <= 2000:
    if number % 7 == 0 and number % 2 != 0:
        sum = sum + number
    number += 1
print("The sum of all integers divisible by 7, but not divisible by 2, from 1 to 2000 is:", sum)

sum = 0

# Write a python function linear(m, x, b) that takes three numbers as parameters, and computes and returns the linear result. (Recall from math that linear functions are of the form y = mx+b). So your function would return y.

#  Evaluate the following expression using your function for m=1, x=2, b=3. DO NOT HARD CODE THE VALUES; use variables with the returned value from the linear function.

def linear(m, x, b):
    return (m * x) + b

y = linear(1,2,3)

print(y)

# Write a program that extracts the middle name of a person.
# Assume the person has a single middle name.
# Assume the first, middle and last names are separated by spaces.
# for example:
# "   Jaine Danger Doe   "
# Your program should extract and print "Danger".
# This is using string functions in Python.
# There can be leading and trailing spaces.

name = input("Please provide a first, middle, and last name separated by spaces. Ex: 'Jaine Danger Doe': ")

name = name.split()
print("Middle name is:", name[1])