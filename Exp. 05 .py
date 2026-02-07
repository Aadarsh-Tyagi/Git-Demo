# Count occurrences of numbers in range 0-3
n = int(input("Enter number of values: "))
values = []

for i in range(n):
    num = int(input("Enter value (0-3): "))
    if 0 <= num <= 3:
        values.append(num)

for i in range(4):
    print(f"{i} occurred {values.count(i)} times")
