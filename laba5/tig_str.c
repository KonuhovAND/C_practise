#include <stdio.h>

#define MAX_LEN 101

int is_latin(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    char str[MAX_LEN];
    int i = 0;
    char c;

    printf("Enter string (end with '.'): ");
    
    while (1) {
        int rer = scanf("%c",&c);
        if (rer == 0) return 1;
        if (c == '.') break;
        if (c == '\n') break; 

        if (is_latin(c) == 0 && c != ' '){ printf("Not latin bukva"); return 1;}
        if (i < MAX_LEN - 1) {
            str[i] = c;
            i++;
        } else {printf("vvedeno bolshe %d simvlov\n",MAX_LEN - 1); return 1;}
    }
    str[i] = '\0';

    int k;
    printf("Enter k: ");
    if (scanf("%d", &k) != 1 || k <= 0) {
        printf("Invalid k\n");
        return 1;
    }

    int current_word = 0;
    int found = 0;
    i = 0;
    
    while (str[i] != '\0') {
        while (str[i] != '\0' && !is_latin(str[i])) {
            i++;
        }
        if (str[i] == '\0') break;

        int start = i;
        while (str[i] != '\0' && is_latin(str[i])) {
            i++;
        }
        int end = i;

        current_word++;
        if (current_word == k) {
            for (int j = end - 1; j >= start; j--) {
                printf("%c", str[j]);
            }
            printf("\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Word %d not found\n", k);
    }

    return 0;
}
