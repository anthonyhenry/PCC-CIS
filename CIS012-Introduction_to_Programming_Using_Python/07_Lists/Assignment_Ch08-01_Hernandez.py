def createList(listSize):
    timeList = []
    for i in range(0,listSize):
        timeList.append(0)
    return timeList

def fillList(listSize, timeList):
    for i in range(0,listSize):
        timeList[i] = i

hoursList = createList(24)
minutesList = createList(60)
fillList(len(hoursList), hoursList)
fillList(len(minutesList), minutesList)

def collectUserInputTime():
    callStartTime = input("Enter the time the call starts in 24-hour rotation:\n")
    callStartTime = callStartTime.split(":")

    startHour = callStartTime[0]
    startMinute = callStartTime[1]

    return startHour, startMinute

def validateUserInputTime(startHour, startMinute):
    try:
        if int(startHour) not in hoursList:
            return False
        elif int(startMinute) not in minutesList:
            return False
        else:
            return True
    except:
        return False

daysList = ['mo', 'tu', 'we', 'th', 'fr', 'sa', 'su']

def collectUserInputDay():
    userInputDay = input("Enter the first two letters of the day of the week:\n")
    userInputDay = list(userInputDay)
    
    firstDayCharacter = userInputDay[0]
    secondDayCharacter = userInputDay[1]

    return firstDayCharacter, secondDayCharacter

def validateUserInputDay(firstDayCharacter, secondDayCharacter):
    userInputDay = firstDayCharacter + secondDayCharacter
    userInputDay = userInputDay.lower()

    if userInputDay in daysList:
        return True
    else:
        return False

def collectUserInputCallLength():
    callLength = input("Enter the length of the call in (hours:minutes):\n")
    callLength = callLength.split(":")
    callLengthHour = callLength[0]
    callLengthMinute = callLength[1]
    return callLengthHour, callLengthMinute

def validateUserInputCallLength(callLengthHour, callLengthMinute):
    try:
        if(int(callLengthHour) >= 0 and int(callLengthMinute) >= 0):
            return True
        else:
            return False  
    except:
        return False

def calculateTotalCost(startHour, startMinute, firstDayCharacter, secondDayCharacter, callLengthHour, callLengthMinute):
    # List of weekdays
    weekdays = ["mo", "tu", "we", "th", "fr"]

    day = firstDayCharacter + secondDayCharacter
    day = day.lower()

    # Determine the billing rate per minute
    if(day in weekdays):
        if(int(startHour) >= 8 and int(startHour) < 18):
            rate = 0.4
        else:
            rate = 0.25
    else:
        rate = .15

    # Calculate total cost
    totalCallMinutes = (60 * int(callLengthHour)) + int(callLengthMinute)
    totalCost = float(totalCallMinutes) * rate
    totalCost = round(totalCost, 2)
    
    return totalCost

responseList = ['y', 'n']

def collectUserInputYesNo():
    YesOrNo = input("Do you want to repeat the program (y/n)?\n>>")
    return YesOrNo

def validateUserInputYesNo(YesOrNo):
    # YesOrNo = YesOrNo.lower()

    if(YesOrNo in responseList):
        return True
    else:
        return False

runProgram = True
while(runProgram == True):
    # Prompt the user for a valid time
    validTime = False
    while(validTime == False):
        startHour, startMinute = collectUserInputTime()
        validTime = validateUserInputTime(startHour, startMinute)
        if(validTime == False):
            print("Invlid time input.\nPlease try again.\n")
    
    # Prompt the user for a valid day
    validDay = False
    while(validDay == False):
        firstDayCharacter, secondDayCharacter = collectUserInputDay()
        validDay = validateUserInputDay(firstDayCharacter, secondDayCharacter)

        if(validDay == False):
            print("Invalid day input.\nPlease try again.\n")

    # Prompt the user for a valid call length
    validCallLength = False
    while(validCallLength == False):
        callLengthHour, callLengthMinute = collectUserInputCallLength()
        validCallLength = validateUserInputCallLength(callLengthHour, callLengthMinute)

        if(validCallLength == False):
            print("Invalid call length input.\nPlease try again.\n")

    totalCostOutput = str(calculateTotalCost(startHour, startMinute, firstDayCharacter, secondDayCharacter, callLengthHour, callLengthMinute))
    totalCostOutput = totalCostOutput.split(".")
    if(len(totalCostOutput[1]) == 1):
        totalCostOutput = totalCostOutput[0] + "." + totalCostOutput[1] + "0"
    else:
        totalCostOutput = totalCostOutput[0] + "." + totalCostOutput[1]
    # totalCostOutput = totalCostOutput[0] + totalCostOutput[1]
    totalCostOutput = "Cost of the call: $" + totalCostOutput

    # totalCostOutput = "Cost of the call: $" + str(calculateTotalCost(startHour, startMinute, firstDayCharacter, secondDayCharacter, callLengthHour, callLengthMinute))
    print(totalCostOutput)
    
    # Prompt the user for a valid yes or no response
    validResponse = False
    while(validResponse == False):
        yesOrNo = collectUserInputYesNo()
        yesOrNo = yesOrNo.lower()
        validResponse = validateUserInputYesNo(yesOrNo)

        if(validResponse == False):
            print("Invalid response.\nPlease try again.\n")
    
    if(yesOrNo == "y"):
        runProgram = True
    else:
        runProgram = False