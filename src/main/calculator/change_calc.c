// This project is a part of CWorks (C language practice project).
//     Copyright (C) 2024. CarmJos
//
//     This program is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     This program is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <stdio.h>

// 找零计算器，输入应付金额和实付金额，输出找零金额。
// 可找零钱有: 1分、2分、5分、1角、2角、5角、1元、2元、5元、10元、20元、50元
// 找到找零张数最少的方案，并输出每个面额的张数。

static const int DENOMINATIONS[] = {
    5000, 2000, 1000, // 50元, 20元, 10元
    500, 200, 100, // 5元, 2元, 1元
    50, 20, 10, 5, 2, 1 // 5角, 2角, 1角, 5分, 2分, 1分
};
static const int DENOMINATIONS_SIZE = sizeof(DENOMINATIONS) / sizeof(int);

void change(const double price, const double paid) {
    int remain = (int)((paid - price) * 100); // 计算以分为单位的找零金额
    if (remain <= 0) {
        printf("付款不足或无需找零。\n");
        return;
    }
    printf("共需找零: %.2lf\n", remain / 100.0);

    // 从大面额开始找零，循环每一个面额
    for (int i = 0; i < DENOMINATIONS_SIZE; i++) {
        if (remain == 0) break; // 找零完成，退出循环

        const int denomination = DENOMINATIONS[i]; // 当前正在处理的面额
        const int amount = remain / denomination; // 当前面额的张数

        if (amount == 0) continue;

        remain -= amount * denomination; // 扣除已找零的金额
        printf("# CNY %.2f × %d\n", denomination / 100.0, amount);
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
