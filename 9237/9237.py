n = int(input())
time = sorted(list(map(int, input().split())), reverse=True)
Dday = 0

for i, j in enumerate(time):
    Dday = max(Dday, i+j+2)
print(Dday)
