userNum = int(input("Provde an integer and I will tell you if it is divisible by 3 and/or 5: "))

if ((userNum % 3 == 0) and (userNum % 5 == 0)):
    print("The integer is divisible by 3 and 5")
elif (userNum % 3 == 0):
    print("The integer is divisible by 3")
elif (userNum % 5 == 0):
    print("The integer is divisible by 5")
else:
    print("Not divisible by 3 or 5")