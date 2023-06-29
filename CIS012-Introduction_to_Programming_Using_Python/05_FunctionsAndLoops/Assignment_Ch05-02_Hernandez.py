# Write a Python program that prints a multiplication table. 

# Use loops to display the table. You can nest one loop inside another. Also look into making the columns line up. See if you can find how to align (format) numbers in Python so you get a nice looking table. Google opportunity.


print("Multiplication Table:")
for factor1 in range(0,11): # Columns
    for factor2 in range(0,11): # Rows
        # First Row 
        if(factor1 == 0):
            if(factor2 == 0):
                print("X", end = "\t") # Print X instead of multiplying 0 by 0
            else:    
                print(factor2, end = "\t") # First row is just factor 2
        # First Column
        elif(factor2 == 0):
            print(factor1, end = "\t") # First column is just factor1
        # Everything else
        else:
            product = factor1 * factor2 # Multiply factors
            print(product, end = "\t")
    print("")