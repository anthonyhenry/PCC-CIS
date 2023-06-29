# Write a Python program that reads 10 integers and then finds and prints the sum of the even and odd integers.

# Use a while loop to calculate.  Allow the user to repeat the program(use a while loop).

repeatProgram = "y"

while(repeatProgram == "y"):
    evenSum = 0
    oddSum = 0

    print("Please enter 10 integers:")

    inputs = 0
    while inputs < 10:
        number = int(input(">"))

        if(number % 2 == 0):
            evenSum = evenSum + number
        else:
            oddSum = oddSum + number

        inputs = inputs + 1

    print("\nEven sum:", evenSum)
    print("Odd sum:", oddSum)

    print("\nDo you wish to repeat this program? (y/n)")
    repeatProgram = input(">")
    print(" ")

print("Done!")