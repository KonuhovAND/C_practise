

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

#define MAXIM 101

int end_stroki(char ch) {
    return ch == '.';
}

int bukva_li(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void print_words_same_letter(char *str) {
    int i = 0;
    int start, end;
    char first_letter;
    
    while (str[i] != '\0') {
        while (str[i] != '\0' && !bukva_li(str[i])) {
            i++;
        }
        
        if (str[i] == '\0') break;
        
        start = i;
        first_letter = str[i];
        
        while (str[i] != '\0' && bukva_li(str[i])) {
            i++;
        }
        end = i - 1;
        
        char last_letter = str[end];
        if (first_letter == last_letter || 
            first_letter == last_letter + 32 || 
            first_letter == last_letter - 32) {
            for (int j = start; j <= end; j++) {
                printf("%c", str[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    char str[MAXIM];
    char ch;
    int i = 0;
    
    setlocale(0, "");
    printf("Vvedite predlozhenie: ");
    
    while (scanf("%c", &ch) == 1) {
        if (end_stroki(ch)) {
            break;
        }
        if (i < MAXIM - 1) {
            str[i] = ch;
            i++;
        }  else {
            printf("\nError: string too long (max %d symbols)\n", MAXIM - 1);
            while (!end_stroki(ch) && scanf("%c", &ch) == 1);
            return 1;
        }
    }
    str[i] = '\0';
    
    printf("\nWords starting and ending with same letter:\n");
    print_words_same_letter(str);
    
    return 0;
}
