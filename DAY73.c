#include <stdio.h>
#include <string.h>

char firstNonRepeating(char *str) {
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

    return '$'; // If none found
}

int main() {
    char str[100];

    printf("Enter string: ");
    scanf("%s", str);

    char result = firstNonRepeating(str);

    printf("First non-repeating character: %c\n", result);

    return 0;
}
