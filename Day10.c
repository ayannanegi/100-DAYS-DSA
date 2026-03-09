//Problem: Read a string and check if it is a palindrome using two-pointer comparison.
//Input:- Single line: string s, Output:- Print YES if palindrome, otherwise NO

#include <stdio.h>
int main() {
    char str[1000];
    scanf("%s", str);
    int left = 0;
    int right = strlen(str) - 1;
    bool isPalindrome = true;
    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = false;
            break;
        }
        left++;
        right--;
    }
    printf("%s\n", is Palindrome ? "YES" : "NO");
    return 0;
}
