file = open(r"C:\GitHub-Repositories\References\Python\CIS012-Introduction_to_Programming_Using_Python\06_StringsAndFiles\Assignment_Ch07-01_Hernandez\data.txt")
# data = file.read()

# Create a list of unique names
names = []

for line in file:
    # Remove newlines
    line = line.strip() 
    # Find the location of the tab
    tabLocation = line.find("\t")
    # Grab just the first name
    name = line[:tabLocation]
    
    # Add unique names to the names list
    if name not in names:
        names.append(name)

data = open(r"C:\GitHub-Repositories\References\Python\CIS012-Introduction_to_Programming_Using_Python\06_StringsAndFiles\Assignment_Ch07-01_Hernandez\data.txt")
data = data.read()
data = data.split()

nameAppearances = []

# Loop through the unique names
for name in range(0, len(names)):
    currentName = names[name].lower()
    currentNameAppearance = 0

    # Loop through all the text in the data file
    for text in range(0, len(data)):
        # Check if part of the current string matches the current name we are looking for
        if currentName in data[text].lower():
            currentNameAppearance = currentNameAppearance + 1
    
    # Print the count for each name
    print(currentNameAppearance, "\t" , currentName)