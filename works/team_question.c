#include <stdio.h>
#include <stdbool.h>
// A competition has 3 teams, each team has 3 players.
// Team1 A B C
// Team2 X Y Z
// A not vs X
// C not vs X,Z
// Print 3 pairs of players that can play against each other.

bool contains(const char *arr, int len, char c) {
    for (int i = 0; i < len; ++i) {
        if (arr[i] == c) return true;
    }
    return false;
}

int main() {
    char opponents[3] = {'0', '0', '0'};
    char teamA[3] = {'C', 'A', 'B'};
    char teamB[3] = {'X', 'Y', 'Z'};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (contains(opponents, 3, teamB[j])) continue;
            if (teamA[i] == 'C' && (teamB[j] == 'Z' || teamB[j] == 'X')) continue;
            if (teamA[i] == 'A' && teamB[j] == 'X') continue;
            opponents[i] = teamB[j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        printf("Team1 %c vs Team2 %c\n", teamA[i], opponents[i]);
    }

    return 0;
}
