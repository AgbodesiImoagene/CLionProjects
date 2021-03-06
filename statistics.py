print("To use functions in descriptive statistics enter 1")
a = eval(input())
if a == 1:
    print("To calculate the mean of some values enter 1")
    b = eval(input())
    if b == 1:
        print("How many values are there?")
        N = eval(input())
        arr = []
        for i in range(N):
            print("Enter value", i + 1)
            arr.append(eval(input()))
        print(arr)
        x = sum(arr)
        mean = x / N
        print("The mean of your values is", mean)
