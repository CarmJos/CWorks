#include <stdio.h>

// N 个人围成一圈，顺序从1~3报数，若报到3则离开队伍
// 最后剩下的是第几个人

int first_in(const int *people, int n) {
    for (int i = 0; i < n; ++i) {
        if (people[i] != 0) {
            return people[i];
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the number of people: ");
    scanf("%d", &n);

    // Initialize people's index
    int people[n];
    for (int i = 0; i < n; ++i) {
        people[i] = i + 1;
    }

    // Start counting, 1~3 ,remove all 3
    int count = 0;
    int left = n;
    int i = 0;
    while (left > 1) {
        if (people[i] != 0) { // If this person is not removed
            count++;
            if (count == 3) {
                people[i] = 0; // Remove this person
                count = 0; // reset count
                left--; // left people -1
            }
        }
        i = (i + 1) % n; // loop for i;
    }

    printf("\nThe last person is: %d\n", first_in(people, n));
    return 0;
}