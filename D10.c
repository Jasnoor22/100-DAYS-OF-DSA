// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

// Input:
// - Single line: string s

// Output:
// - Print YES if palindrome, otherwise NO

// Example:
// Input:
// level

// Output:
// YES

// Explanation: String reads same forwards and backwards
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);
    int len = strlen(s);
    int left = 0;
    int right = len - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            printf("NO\n");
            return 0;
        }
        left++;
        right--;
    }
    printf("YES\n");
    return 0;
}