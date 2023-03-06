#include <stdio.h>
#include <string.h>

int hasPermutation(char pattern[], char text[]) {
    int count[26] = {0};
    int i, j, len1, len2;
    len1 = strlen(pattern);
    len2 = strlen(text);
    
    for (i = 0; i < len1; i++) {
        count[pattern[i] - 'a']++;
    }
    
    for (i = 0; i <= len2 - len1; i++) {
        int temp[26] = {0};
        int found = 1;
        for (j = 0; j < len1; j++) {
            if (temp[text[i + j] - 'a'] == count[text[i + j] - 'a']) {
                found = 0;
                break;
            } else {
                temp[text[i + j] - 'a']++;
            }
        }
        if (found) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int T, t;
    scanf("%d", &T);
    
    for (t = 1; t <= T; t++) {
        char pattern[100001], text[1000001];
        scanf("%s %s", pattern, text);
        if (hasPermutation(pattern, text)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}
