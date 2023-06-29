def YesNo(number):
    if( (number % 2 == 0 and number % 7 == 0 and number % 70 > 0) or (number % 57 == 0) ):
        return True
    else:
        return False

for number in range(1,1001):
    if(YesNo(number) == True):
        print("The number", number, "is divisible by both 2 and 7 but not 70, or is divisible by 57")