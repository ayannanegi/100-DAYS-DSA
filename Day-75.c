//Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
#include <stdio.h>

#define MAX 1000

int maxLenZeroSum(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Hash map simulation using arrays
    int hash[2 * MAX + 1];  // to handle negative sums
    for (int i = 0; i < 2 * MAX + 1; i++)
        hash[i] = -2;  // -2 means not visited

    int offset = MAX;  // shift index for negative sums

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum = 0 → from index 0 to i
        if (sum == 0) {
            maxLen = i + 1;
        }

        // Case 2: sum seen before
        if (hash[sum + offset] != -2) {
            int prevIndex = hash[sum + offset];
            int len = i - prevIndex;
            if (len > maxLen)
                maxLen = len;
        } else {
            // Store first occurrence
            hash[sum + offset] = i;
        }
    }

    return maxLen;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", maxLenZeroSum(arr, n));
    return 0;
}
