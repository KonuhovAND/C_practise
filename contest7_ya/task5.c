#include <stdio.h>
#define MaxLen 1001

void inputString(char *str) {
    char ch;
    int i = 0;
    while (scanf("%c", &ch) == 1 && ch != '.') {
        if (i < MaxLen - 1) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
}

void reverseRange(char *str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int stringLength(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char toUpperCase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 'A';
    }
    return ch;
}

char toLowerCase(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }
    return ch;
}

void reverseWords(char *str) {
    int len = stringLength(str);
    
    reverseRange(str, 0, len - 1);
    
    int i = 0;
    int wordCount = 0;
    
    while (i < len) {
        while (i < len && str[i] == ' ') {
            i++;
        }
        if (i >= len) break;
        
        wordCount++;  
        
        int wordStart = i;
        while (i < len && str[i] != ' ') {
            i++;
        }
        int wordEnd = i - 1;
        reverseRange(str, wordStart, wordEnd);
    }
    
    if (len > 0 && str[0] != ' ') {
        str[0] = toUpperCase(str[0]);
    }
    
    if (wordCount > 1) {
        i = 0;
        int lastWordStart = 0;
        while (i < len) {
            if (str[i] != ' ') {
                lastWordStart = i;
                while (i < len && str[i] != ' ') {
                    i++;
                }
            } else {
                i++;
            }
        }
        str[lastWordStart] = toLowerCase(str[lastWordStart]);
    }
}


void printString(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        printf("%c", str[i]);
        i++;
    }
    printf(".\n");
}

int main() {
    char str[MaxLen];
    inputString(str);
    reverseWords(str);
    printString(str);
    return 0;
}
