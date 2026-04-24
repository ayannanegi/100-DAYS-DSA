//Problem Statement
//Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

#include <stdio.h>

char firstRepeatedChar(char str[]) {
    int visited[26] = {0};  // for 'a' to 'z'

    for (int i = 0; str[i] != '\0'; i++) {
        int index = str[i] - 'a';

        if (visited[index] == 1) {
            return str[i];  // first repeated character
        }

        visited[index] = 1;
    }

    return '\0'; // no repeated character
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    char result = firstRepeatedChar(str);

    if (result != '\0')
        printf("First repeated character: %c\n", result);
    else
        printf("No repeated character found\n");

    return 0;
}
