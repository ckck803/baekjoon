import sys
input = sys.stdin.readline


class Stack:
    arr = []

    def push(self, value):
        self.arr.append(value)

    def top(self):
        if(len(self.arr) == 0):
            print(-1)
        else:
            print(self.arr[len(self.arr) - 1])

    def size(self):
        print(len(self.arr))

    def pop(self):
        size = len(self.arr)
        if(size == 0):
            print(-1)
        else:
            print(self.arr[size - 1])
            self.arr.pop(size - 1)

    def empty(self):
        if(len(self.arr) == 0):
            print(1)
        else:
            print(0)


n = int(input())
s = Stack()

for i in range(n):
    commands = input().split()

    if(commands[0] == 'push'):
        s.push(commands[1])

    elif(commands[0] == 'top'):
        s.top()

    elif(commands[0] == 'size'):
        s.size()

    elif(commands[0] == 'pop'):
        s.pop()
    elif(commands[0] == 'empty'):
        s.empty()
