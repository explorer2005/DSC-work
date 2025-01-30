#include <stdio.h>
#include <string.h>

// KMP Pattern Matching
void computeLPSArray(char* pattern, int M, int* lps) {
    int len = 0;  // Length of previous longest prefix suffix
    int i = 1;
    
    lps[0] = 0;  // First element is always 0
    
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* text, char* pattern) {
    int N = strlen(text);
    int M = strlen(pattern);
    int lps[M];  // Longest Prefix Suffix array
    
    computeLPSArray(pattern, M, lps);
    
    int i = 0;  // Index for text
    int j = 0;  // Index for pattern
    int found = 0;  // Flag to check if pattern is found
    
    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
            found = 1;
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    if (!found) {
        printf("Pattern not found\n");
    }
}

// Naive Pattern Matching (nfind)
void nfindSearch(char* text, char* pattern) {
    int N = strlen(text);
    int M = strlen(pattern);
    int found = 0;
    
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        
        if (j == M) {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Pattern not found\n");
    }
}

int main() {
    char text[100], pattern[100];
    int choice;
    
    while (1) {
        printf("\nPattern Matching Menu:\n");
        printf("1. KMP Pattern Matching\n");
        printf("2. Naive Pattern Matching (nfind)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear input buffer
        
        if (choice == 3) {
            break;
        }
        
        printf("Enter the text: ");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = 0;  // Remove newline
        
        printf("Enter the pattern to search: ");
        fgets(pattern, sizeof(pattern), stdin);
        pattern[strcspn(pattern, "\n")] = 0;  // Remove newline
        
        switch (choice) {
            case 1:
                printf("\nKMP Pattern Matching Result:\n");
                KMPSearch(text, pattern);
                break;
                
            case 2:
                printf("\nNaive Pattern Matching Result:\n");
                nfindSearch(text, pattern);
                break;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}