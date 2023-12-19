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
    const double change = paid - price; // 计算须找零金额
    if (change <= 0) {
        printf("付款不足或无需找零。\n");
        return;
    }

    printf("找零: %.2lf\n", change);

    int remain = (int)(change * 100); // 以分为单位的找零金额
    int amount[12] = {0}; // 每个面额的张数

    for (int i = 0; i < 12; i++) {
        // 从大面额开始找零，循环每一个面额
        while (remain >= DENOMINATIONS[i]) {
            // 当前面额的金额仍然可以找零
            remain -= DENOMINATIONS[i]; // 扣除当前面额的金额
            amount[i]++; // 此面额的对应张数加一
        }
    }

    for (int i = 0; i < 12; i++) {
        if (amount[i] <= 0) continue; // 无需输出的面额直接跳过
        // 输出当前面额的金额(单位转换为元)和对应张数
        printf("# CNY %.2f × %d\n", DENOMINATIONS[i] / 100.0, amount[i]);
    }
}


int main() {
    double price, paid;
    printf("请输入 应付价格(元): ");
    scanf("%lf", &price);
    printf("\n");
    printf("请输入 实付价格(元): ");
    scanf("%lf", &paid);
    printf("\n");

    change(price, paid);
}
