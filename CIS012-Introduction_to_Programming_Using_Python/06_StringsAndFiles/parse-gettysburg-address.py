file = open(r"C:\GitHub-Repositories\References\Python\CIS012-Introduction_to_Programming_Using_Python\06_StringsAndFiles\TheGettysburgAddress.txt")
content = file.read()
content = content.split() # Create an array of words in the file

# Initialize most used word variables
mostUsedWord = ""
mostUsedWordCount = 0
# Initialize array of words that have already been checked
checkedWords = []

# Initialize a variable for going through the content words array
wordCount = 0

for word in content:
    # Store the lowercase form of the current word
    currentWord = content[wordCount]
    currentWord = currentWord.lower()

    # Skip words that have already been checked
    if(currentWord in checkedWords):
        wordCount = wordCount + 1
        continue
    else:
        # Add the current word to the checked words list
        checkedWords.append(currentWord)

        # Variable to count how many times the current word appears
        currentWordCount = 0
        # Variable that goes through the file to compare each word with the current word
        wordToCompare = 0

        for word2 in content:
            # Count how many times the current word appears
            if content[wordToCompare].lower() == currentWord:
                currentWordCount = currentWordCount + 1
            
            #Check the next word
            wordToCompare = wordToCompare + 1
        
        # Check if we have a new winner for most appearances
        if currentWordCount > mostUsedWordCount:
            mostUsedWord = currentWord
            mostUsedWordCount = currentWordCount
        
        #Check the next word on the next iteration of the loop
        wordCount = wordCount + 1
print("Most used word in The Gettysburg Address:", mostUsedWord)