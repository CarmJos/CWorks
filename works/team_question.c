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

bool full(const char *arr, int len) {
    for (int i = 0; i < len; ++i) {
        if (arr[i] == '0') return false;
    }
    return true;
}

int main() {
    char opponents[3] = {'0', '0', '0'};
    char teamA[3] = {'C', 'A', 'B'};
    char teamB[3] = {'X', 'Y', 'Z'};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (full(opponents, 3)) break; // All players have been assigned, break!
            if (contains(opponents, 3, teamB[j])) continue; // The player has been assigned.
            if (teamA[i] == 'C' && (teamB[j] == 'Z' || teamB[j] == 'X')) continue; // C not vs X,Z
            if (teamA[i] == 'A' && teamB[j] == 'X') continue; // A not vs X
            opponents[i] = teamB[j]; // Assign the player.
        }
    }

    for (int i = 0; i < 3; ++i) { // Print the result.
        printf("Team1 %c vs Team2 %c\n", teamA[i], opponents[i]);
    }

    return 0;
}
