//Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.
#include <stdio.h>
#include <string.h>

char firstNonRepeating(char str[]) {
    int freq[26] = {0};

    // Step 1: Count frequency
    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i] - 'a']++;
    }

    // Step 2: Find first non-repeating
    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[str[i] - 'a'] == 1) {
            return str[i];
        }
    }

    return '$'; // if all repeat
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    char result = firstNonRepeating(str);

    if (result != '$')
        printf("First non-repeating character: %c\n", result);
    else
        printf("All characters are repeating\n");

    return 0;
}
