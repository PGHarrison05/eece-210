def frequency(period):
    return 1/period

while True:
    period= input("Enter the period in seconds or q to quit: ")
    if period== 'q':
        print("Thank you for using this program!")
        break
    else:
            period=float(period)
            print("The frequency is ", frequency(period), " Hz." )
