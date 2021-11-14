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