try:
    while True:
        A=input().split(' ')
        B=input().split(' ')
        a=set()
        b=set()
        for num in A:
            a.add(int(num))
        for num in B:
            b.add(int(num))
        if a==b:
            print('A equals B')
        elif a&b==set():
            print('A and B are disjoint')
        elif a<b:
            print('A is a proper subset of B')
        elif b<a:
            print('B is a proper subset of A')
        else:
            print('I\'m confused!')
except EOFError:
    pass