def count_range(number, start, end): 
    count = 0
    for num in range(start, end + 1):
        if num == number:
            count += 1
    return count

num = int(input("Please give me a value: "))
start = int(input("Please give me a lower bound to a range: "))
end = int(input("Please give me an upper bound to a range: "))

occurrences = count_range(num, start, end)

print(f"The number {num} appears {occurrences} time(s) in the range {start} to {end}.")


