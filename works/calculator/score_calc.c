#include <stdio.h>
#include <math.h>
#include <stdbool.h>

static bool closer(const double avg, const double a, const double b) {
    return fabs(avg - a) < fabs(avg - b);
}

static bool farther(const double avg, const double a, const double b) {
    return fabs(avg - a) > fabs(avg - b);
}

int main() {
    double scores[10];
    printf("Please input the scores: \n");
    for (int i = 0; i < 10; i++) {
        scanf("%lf", &scores[i]);
    }

    double min = -1, max = -1, total = 0;
    for (int i = 0; i < 10; i++) {
        total += scores[i];
        if (min == -1 || scores[i] < min) min = scores[i];
        if (max == -1 || scores[i] > max) max = scores[i];
    }
    double avg = (total - min - max) / 8;
    printf("Max score is %.2lf, skipped.\n", max);
    printf("Min score is %.2lf, skipped.\n", min);
    printf("Average score is %.2lf\n", avg);

    double closest = -1, farthests = -1;
    for (int i = 0; i < 10; i++) {
        if (scores[i] == min || scores[i] == max) continue;
        if (closest == -1 || closer(avg, scores[i], closest)) {
            closest = scores[i];
        }
        if (farthests == -1 || farther(avg, scores[i], farthests)) {
            farthests = scores[i];
        }
    }

    printf("Closest score is %.2lf\n", closest);
    printf("Farthest score is %.2lf\n", farthests);
    return 0;
}
