revenue= eval(input("Please Enter your revenue"))
costs= eval(input("Please enter your costs"))
if revenue>costs:
    print("Your profit is: ", revenue-costs)
elif revenue<costs:
    print("Your Loss is: ", costs-revenue)
else:
    print("You have broken even")