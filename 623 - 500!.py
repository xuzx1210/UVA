try:
    while True:
        n=int(input())
        result=1
        for i in range(1, n+1):
            result*=i
        print(f'{n}!')
        print(result)
except EOFError:
    pass