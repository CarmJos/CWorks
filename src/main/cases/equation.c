
#include <stdio.h>

// 某饭店招待国外考察团。
// 按照标准，对领导是400元/人，随团职员200元/人，对司机50元/人。
// 考察团共36人，招待费结算为3600元，请问领导、职员、司机各几人。

//int main() {
//    // 通过穷举法解决
//    int leader, staff, driver;
//    int matched = 0;
//
//    // 穷举所有可能的组合
//    for (leader = 0; leader <= 36; leader++) {
//        for (staff = 0; staff <= 36 - leader; staff++) {
//            driver = 36 - leader - staff;
//            if (leader * 400 + staff * 200 + driver * 50 == 3600) {
//                printf("leader: %d , staff: %d, driver: %d\n", leader, staff, driver);
//                matched++;
//            }
//        }
//    }
//
//    if (!matched) printf("Nothing matched.\n");
//    return 0;
//}


int main() {
    // 方程法
    int leader, staff, driver;

    // 根据题意，设领导x人，职员y人，司机z人
    // 则有
    // |> x + y + z = 36 (1)
    // |> 400x + 200y + 50z = 3600 (2)

    // 从(1)式得到 z = 36 - x - y
    // 代入(2)式得到 400x + 200y + 50(36 - x - y) = 3600
    // 化简得 350x + 150y = 1800
    // 进一步化简 7x + 3y = 36

    int matched = 0;
    for (leader = 0; leader <= 36; leader++) {
        if ((36 - 7 * leader) % 3 != 0) continue;

        staff = (36 - 7 * leader) / 3;
        driver = 36 - leader - staff;
        if (driver < 0 || staff < 0) continue;

        printf("leader: %d , staff: %d, driver: %d\n", leader, staff, driver);
        matched++;
    }

    if (!matched) printf("Nothing matched.\n");
    return 0;
}