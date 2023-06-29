rectLength = input("Please enter the length of the rectangle:")
rectWidth = input("Please enter the width of the rectangle:")

#print(type(rectLength))
#print(type(rectWidth))

# input() takes in strings, so they need to be converted to floats
rectLength = float(rectLength)
rectWidth = float(rectWidth)

#print(type(rectLength))
#print(type(rectWidth))

# Calculate diagonal
rectDiagonal = (rectLength**2 + rectWidth**2) ** (1/2)
# Display only 2 decimal points
rectDiagonal = round(rectDiagonal, 2) 

print("The diagonal of the rectangle is:", rectDiagonal)