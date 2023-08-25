# Write a python program that lets a user enter and view information about their friends/contacts.

# The program should use a dictionary, with the key being the name of the friend, and the value being their age.
# The program should let the user add new entries until they decide to quit, then using the two-iteration variable method, print the entire dictionary.
# so step 1 is to have a loop where you ask the user to input their friends names and their age. Loop until the users types "end" for a friends name.

# step 2 use the two-iteration variable method (look at the 2nd for loop on page 28 of the Powerpoints) to go through the dictionary and print the names and ages of the friends in the dictionary.

friendAges = {}

nameEntry = input("Please enter the name of your friend: ")

while nameEntry != "end":
    agePrompt = "How old is " + nameEntry + "? "
    ageEnry = input(agePrompt)
    friendAges[nameEntry] = ageEnry

    nameEntry = input("Please enter another friend's name. If you are done entering friends, type 'end': ")

for friend, age in friendAges.items():
    print("Your friend", friend, "is", age, "years old")