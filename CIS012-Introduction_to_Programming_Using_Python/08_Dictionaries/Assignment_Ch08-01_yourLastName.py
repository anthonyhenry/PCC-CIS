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
daysList = ['mo', 'tu', 'we', 'th', 'fr', 'sa', 'su']
responseList = ['y', 'n']

def collectUserInputTime():
    callStartTime = input("Enter the time the call starts in 24-hour rotation:\n")
    callStartTime = callStartTime.split(":")

    startHour = callStartTime[0]
    startMinute = callStartTime[1]

    return startHour, startMinute

startHour, startMinute = collectUserInputTime()

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

print(validateUserInputTime(startHour, startMinute))