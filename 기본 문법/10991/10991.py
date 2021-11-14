n = int(input())

for i in range(n):
    print(' '*(n-1-i), end='')
    print('* '*(i+1))
