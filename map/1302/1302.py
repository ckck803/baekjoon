n = int(input())

dic = {}

for i in range(n):
    book_name = input()
    if(book_name in dic):
        dic[book_name] += 1
    else:
        dic[book_name] = 1

max_value = max(dic.values())
book_names = []

for book_name in dic:
    if(dic[book_name] == max_value):
        book_names.append(book_name)

print(sorted(book_names)[0])
