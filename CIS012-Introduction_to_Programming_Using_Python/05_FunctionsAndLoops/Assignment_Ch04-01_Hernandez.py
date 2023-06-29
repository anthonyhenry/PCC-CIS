vowels = ["a", "A", "e", "E", "i", "I", "o", "O", "u", "U"]

numVowels = len(vowels)

def isVowel(letter):
    print(numVowels)
    for i in range(0,numVowels):
        print(i)
        if(letter == vowels[i]):
            print(letter, "is", vowels[i])
            return True
        elif(i == numVowels-1):
            print(letter, "is not a vowel")
            return False
        else:
            print(letter, "is not", vowels[i])
            continue
    
usrLetter = input("Enter a character between a and z (or A and Z): ")

print(usrLetter, "is a vowel:", isVowel(usrLetter))