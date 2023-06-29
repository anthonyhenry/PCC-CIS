hours = input('Enter Hours: ')
rate = input('Enter Rate: ')

try:
    pay = float(hours) * float(rate)
    print('Pay:', pay)
except:
    print("Error: One or more inputs given was not valid.")