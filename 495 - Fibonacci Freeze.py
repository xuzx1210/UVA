fibonacci=[0, 1]
for i in range(2, 5001):
    fibonacci.append(fibonacci[-1]+fibonacci[-2])
try:
    while True:
        n=int(input())
        print(f'The Fibonacci number for {n} is {fibonacci[n]}')
except EOFError:
    pass