test_case = int(input())

for i in range(test_case):
    car_price = int(input())
    options = int(input())
    for j in range(options):
        option_num, option_price = map(int, input().split())
        car_price = car_price + option_num * option_price

    print(car_price)
