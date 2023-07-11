# Write a function that receives a string, prints it and returns an integer.

def printString(string):
    print(string)
    try:
        return int(string)
    except:
        return 404
    
a = printString("5")
b = printString("apple")

print(a)
print(b)

# Write a function that receives a list and prints it and returns two integers 5 and 7 which are assigned to the x and y variables in your main Python program.
nums = [3, 41, 12, 9, 74, 15]

def listFunc(list):
    print(list)
    return [5, 7]

returnValues = listFunc(nums)
x = returnValues[0]
y = returnValues[1]
print(x)
print(y)

# Write a function that recieves 5 integers and returns a string made up of all of them concatenated together.

def concatInts(int1, int2, int3, int4, int5,):
    str1 = str(int1)
    str2 = str(int2)
    str3 = str(int3)
    str4 = str(int4)
    str5 = str(int5)

    returnString = str1 + str2 + str3 + str4 + str5
    return returnString

numString = concatInts(1, 8, 5, 6, 3)
print(h)