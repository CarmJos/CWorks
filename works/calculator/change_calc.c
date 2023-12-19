#include <stdio.h>

// 找零计算器，输入应付金额和实付金额，输出找零金额。
// 可找零钱有: 1分、2分、5分、1角、2角、5角、1元、2元、5元、10元、20元、50元
// 找到找零张数最少的方案，并输出每个面额的张数。

static const int DENOMINATIONS[] = {
    5000, 2000, 1000, // 50元, 20元, 10元
    500, 200, 100, // 5元, 2元, 1元
    50, 20, 10, 5, 2, 1 // 5角, 2角, 1角, 5分, 2分, 1分
};

void change(const double price, const double paid) {
    double change = paid - price;
    printf("Change: %.2lf\n", change);

    if (change <= 0) {
        printf("No any change.\n");
        return;
    }

    int remain = (int)(change * 100);
    int amount[12] = {0};

    for (int i = 0; i < 12; i++) {
        while (remain >= DENOMINATIONS[i]) {
            remain -= DENOMINATIONS[i];
            amount[i]++;
        }
    }

    for (int i = 0; i < 12; i++) {
        if (amount[i] <= 0)continue;
        printf("# CNY %.2f × %d\n", DENOMINATIONS[i] / 100.0, amount[i]);
    }
}


int main() {
    double price, paid;
    printf("Please input the price: ");
    scanf("%lf", &price);
    printf("\n");
    printf("Please input the paid: ");
    scanf("%lf", &paid);
    printf("\n");

    change(price, paid);
}
