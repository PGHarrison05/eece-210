def check_signal(samples):
    if all(value == samples[0] for value in samples):
        return "DC"
    else:
        return "AC"

user_input = input("Enter the signal values (separate them by spaces): ")

samples = [float(num) for num in user_input.split()]  

result = check_signal(samples)

print("The signal is:", result)