# Write a Python program that creates and stores a multiplication table in a 2D list called MT
MT = []

# Counter for creating lists within MT
nestedListCounter = 0
# While loop to add nested lists to MT
while nestedListCounter <= 10:
    # Initiliaze a nested list
    nestedList = []
    
    # Counter for adding items to the nested list 
    nestedListItem = 0

    # While loop to add ten 0s to each nested list
    while nestedListItem <= 10:
        nestedList.append(0)
        nestedListItem += 1

    # Add the nested list to MT
    MT.append(nestedList)

    nestedListCounter += 1

# Reset nested loop counter for updating nested loop values
nestedListCounter = 0
# While loop to update nested loop values
while nestedListCounter <= 10:
    nestedListItem = 0
    # Update each list item to be the list counter multiplied by the list item
    while nestedListItem <= 10:
        MT[nestedListCounter][nestedListItem] = nestedListCounter * nestedListItem
        nestedListItem += 1
    nestedListCounter += 1

# Display table
print("Multiplication Table:")
row = 0
while row <= 10:
    col = 0
    while  col <= 10:
        # Display column numbers
        if row == 0:
            # Very first cell is an X
            if col == 0:
                print("X", end='\t')
            else:
                print(col, end='\t')
        # Display row numbers
        elif col == 0:
            print(row, end='\t')
        # Display products
        else:
            print(MT[row][col], end='\t')

        col += 1
    print("")

    row += 1