# 백준 9325 - 얼마?

## 문제
해빈이는 학교를 다니면서 틈틈히 번 돈으로 자동차를 사려고 한다. 자동차에 여러 가지 옵션을 포함시킬 수 있는데 해빈이는 덧셈과 곱셈을 하지 못하기 때문에 친구 태완이에게 도움을 청했다. 하지만 태완이도 덧셈과 곱셈을 못한다. 불쌍한 이 두 친구를 위해 모든 옵션이 주어진 자동차를 구매하는데 필요한 액수를 계산해 주자.


## 입력
첫째 줄에 테스트 케이스의 개수가 주어진다.
각 테스트 케이스의 첫 줄엔 자동차의 가격 s가 주어진다. (1 ≤ s ≤ 100 000)
둘째 줄엔 해빈이가 구매하려고 하는 서로 다른 옵션의 개수 n이 주어진다. (0 ≤ n ≤ 1 000)
뒤이어 n개의 줄이 입력으로 들어온다. 각 줄은 q 와 p로 이루어져 있는데 q는 해빈이가 사려고 하는 특정 옵션의 개수이고 p는 해당 옵션의 가격이다. (1 ≤ q ≤ 100, 1 ≤ p ≤ 10 000)

## 출력
각 테스트 케이스 마다, 해빈이가 최종적으로 구매하려는 자동차의 가격을 한줄씩 출력한다.

## cpp 코드
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int test_case;
    scanf("%d", &test_case);

    while (test_case--) {
        int car_price;
        scanf("%d", &car_price);

        int options;
        scanf("%d", &options);
        while (options--) {
            int option_num, option_price;
            scanf("%d %d", &option_num, &option_price);

            car_price += option_num * option_price;
        }
        printf("%d\n", car_price);
    }

    return 0;
}
```

## python 코드
```python
test_case = int(input())

for i in range(test_case):
    car_price = int(input())
    options = int(input())
    for j in range(options):
        option_num, option_price = map(int, input().split())
        car_price = car_price + option_num * option_price

    print(car_price)
```

## java 코드
```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int test_case = Integer.parseInt(br.readLine().trim());

        while (test_case-- > 0) {
            int car_price = Integer.parseInt(br.readLine().trim());

            int options = Integer.parseInt(br.readLine().trim());
            while (options-- > 0) {
                st = new StringTokenizer(br.readLine().trim());
                int option_num = Integer.parseInt(st.nextToken());
                int option_price = Integer.parseInt(st.nextToken());

                car_price += option_num * option_price;
            }
            System.out.println(car_price);
        }

        br.close();
    }
}
```