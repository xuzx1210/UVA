while True:
    num=input()
    if num=="*":
        break
    if num.isnumeric():
        n=int(num)
        tmp=n
        string=[]
        while tmp>0:
            string.append((tmp%26)+ord('a')-1)
            tmp//=26
        string.reverse()
        for c in string:
            print(chr(c), end='')
        for i in range(22-len(string)):
            print(' ', end='')
        print('{:,}'.format(n))
    else:
        n=0
        for c in num:
            n*=26
            n+=(ord(c)-ord('a')+1)
        print(num, end='')
        for i in range(22-len(num)):
            print(' ', end='')
        print('{:,}'.format(n))