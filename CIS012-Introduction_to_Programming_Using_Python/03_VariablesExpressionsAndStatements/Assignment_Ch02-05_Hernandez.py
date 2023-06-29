seconds = int(input("Enter the elapsed time in seconds: "))

print("The elapsed time in seconds =", seconds)

#Find out how many hours are in the supplied seconds
secondsInAnHour = 60 * 60
hours = seconds / secondsInAnHour
# Convert the hours to an integer
hours = int(hours)
print(hours)

# Subtract the calculated hours from the given seconds
minutes = seconds - (hours * 60 * 60)
print(minutes) # This is how many seconds remain to calculate
# Find out how many minutes are in the remaining seconds
minutes = minutes / 60
# Convert the minutes to an integer
minutes = int(minutes)
print(minutes)

# Subtract the calculated hours and minutes from the given seconds
seconds = seconds - (hours * 60 * 60) - (minutes * 60)
# Turn the seconds into an integer
seconds = int(seconds)
print(seconds)

print("The equivalent time in hours:minutes:seconds = " + str(hours) + ":" + str(minutes) + ":" + str(seconds))

# How to do with mod:
# hours = int(seconds / (60**2))
# minutes = int((seconds / 60) % 60) 
# seconds = int(seconds % 60)