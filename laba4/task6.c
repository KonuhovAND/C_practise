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

void inputWord(char *word) {
    char ch;
    int i = 0;
    
    while (scanf("%c", &ch) == 1 && (ch == ' ' || ch == '\n')) {
    }
    
    if (ch != ' ' && ch != '\n') {
        word[i++] = ch;
    }
    
    while (scanf("%c", &ch) == 1 && ch != '\n' && ch != ' ') {
        if (i < MaxLen - 1) {
            word[i++] = ch;
        }
    }
    word[i] = '\0';
}

char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }
    return ch;
}

char toUpper(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 'A';
    }
    return ch;
}

int compareWords(char *str, int start, int end, char *word) {
    int wordLen = 0;
    while (word[wordLen] != '\0') {
        wordLen++;
    }
    
    int strLen = end - start + 1;
    
    if (strLen != wordLen) {
        return 0;
    }
    
    for (int i = 0; i < wordLen; i++) {
        if (toLower(str[start + i]) != toLower(word[i])) {
            return 0;
        }
    }
    
    return 1;
}

void removeWords(char *str, char *word) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    
    int readIndex = 0;
    int writeIndex = 0;
    int isFirstWord = 1;
    
    while (readIndex < len) {
        while (readIndex < len && str[readIndex] == ' ') {
            readIndex++;
        }
        
        if (readIndex >= len) break;
        
        int wordStart = readIndex;
        
        while (readIndex < len && str[readIndex] != ' ') {
            readIndex++;
        }
        
        int wordEnd = readIndex - 1;
        
        if (!compareWords(str, wordStart, wordEnd, word)) {
            if (!isFirstWord) {
                str[writeIndex++] = ' ';
            }
            
            for (int j = wordStart; j <= wordEnd; j++) {
                if (isFirstWord && j == wordStart) {
                    str[writeIndex++] = toUpper(str[j]);
                } else {
                    str[writeIndex++] = str[j];
                }
            }
            
            isFirstWord = 0;
        }
    }
    
    str[writeIndex] = '\0';
}

int main() {
    char str[MaxLen];
    char word[MaxLen];
    
    inputString(str);
    inputWord(word);
    removeWords(str, word);
    
    if (str[0] == '\0') {
        printf("Empty\n");
    } else {
        printf("%s.\n", str);
    }
    
    return 0;
}
