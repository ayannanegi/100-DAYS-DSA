//Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.
#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int n;
    scanf("%d", &n);

    char votes[n][MAX];

    // Input votes
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    // Arrays to store unique names and counts
    char names[n][MAX];
    int count[n];
    int unique = 0;

    // Count frequency
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < unique; j++) {
            if (strcmp(votes[i], names[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(names[unique], votes[i]);
            count[unique] = 1;
            unique++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[MAX];

    for (int i = 0; i < unique; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        } 
        else if (count[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s\n", winner);

    return 0;
}
