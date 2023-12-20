#include <stdio.h>

// 找零计算器，输入应付金额和实付金额，输出找零金额。
// 可找零钱有: 1分、2分、5分、1角、2角、5角、1元、2元、5元、10元、20元、50元
// 找到找零张数最少的方案，并输出每个面额的张数。

static const int DENOMINATIONS[] = {
    5000, 2000, 1000, // 50元, 20元, 10元
    500, 200, 100, // 5元, 2元, 1元
    50, 20, 10, 5, 2, 1 // 5角, 2角, 1角, 5分, 2分, 1分
};

static int size_of_denominations() {
    return sizeof(DENOMINATIONS) / sizeof(int);
}

void change(const double price, const double paid) {
    const double change = paid - price; // 计算须找零金额
    if (change <= 0) {
        printf("付款不足或无需找零。\n");
        return;
    }
    printf("共需找零: %.2lf\n", change);

    int remain = (int)(change * 100); // 以分为单位的找零金额

    // 从大面额开始找零，循环每一个面额
    for (int i = 0; i < size_of_denominations(); i++) {
        if (remain == 0) break; // 找零完成，退出循环

        const int denomination = DENOMINATIONS[i]; // 当前正在处理的面额
        const int amount = remain / denomination; // 当前面额的张数

        if (amount > 0) {
            remain -= amount * denomination; // 扣除已找零的金额
            printf("# CNY %.2f × %d\n", denomination / 100.0, amount);
        }
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
