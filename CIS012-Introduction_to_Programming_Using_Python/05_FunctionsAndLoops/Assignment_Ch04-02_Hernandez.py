year = int(input("Enter a year between 1000 to 3000:"))

def returnRomanOnesPlace(year):
    year = year % 10

    if(year == 0):
        year = ""
    elif(year <= 3):
        if(year == 1):
            year = "I"
        elif(year == 2):
            year = "II"
        else:
            year = "III"
    elif(year <= 8):
        if(year == 4):
            year = "IV"
        elif(year == 5):
            year = "V"
        elif(year == 6):
            year = "VI"
        elif(year == 7):
            year = "VII"
        else:
            year = "VIII"
    else:
        year = "IX"

    return year

def returnRomanTensPlace(year):
    year = (year % 100) - (year % 10)

    if(year == 0):
        year = ""
    elif(year <= 30):
        if(year == 10):
            year = "X"
        elif(year == 20):
            year = "XX"
        else:
            year = "XXX"
    elif(year <= 80):
        if(year == 40):
            year = "XL"
        elif(year == 50):
            year = "L"
        elif(year == 60):
            year = "LX"
        elif(year == 70):
            year = "LXX"
        else:
            year = "LXXX"
    else:
        year = "XC"

    return year

def returnRomanHundredsPlace(year):
    year = (year % 1000) - (year % 100)

    if(year == 0):
        year = ""
    elif(year <= 300):
        if(year == 100):
            year = "C"
        elif(year == 200):
            year = "CC"
        else:
            year = "CCC"
    elif(year <= 800):
        if(year == 400):
            year = "CD"
        elif(year == 500):
            year = "D"
        elif(year == 600):
            year = "DC"
        elif(year == 700):
            year = "DCC"
        else:
            year = "DCCC"
    else:
        year = "CM"

    return year

def returnRomanThousandsPlace(year):
    year = (year %10000) - (year % 1000)

    if(year == 0):
        year = ""
    elif(year == 1000):
        year = "M"            
    elif(year == 2000):
        year = "MM"
    else:
        year = "MMM"

    return year

formattedYear = returnRomanThousandsPlace(year) + returnRomanHundredsPlace(year) + returnRomanTensPlace(year) + returnRomanOnesPlace(year)

print("Your number in roman numerals is:", formattedYear)