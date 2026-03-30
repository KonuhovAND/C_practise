#define Max_word_len 11
#define Max_sentence_len 40
#include <stdio.h>

int inputSentence(char sentence[][Max_word_len]) {
    char ch;
    int wordCount = 0;
    int charCount = 0;
    int hasWords = 0;
    
    while (scanf("%c", &ch) == 1) {
        if (ch == '.' || ch == '!' || ch == '?') {
            if (charCount > 0) {
                sentence[wordCount][charCount] = '\0';
                wordCount++;
                hasWords = 1;
            }
            break;
        }
        
        if (ch == ' ' || ch == '\n') {
            if (charCount > 0) {
                sentence[wordCount][charCount] = '\0';
                wordCount++;
                charCount = 0;
                hasWords = 1;
                
                if (wordCount >= Max_sentence_len) {
                    printf("Error: too many words (max 40)\n");
                    return -1;
                }
            }
        } else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (charCount >= 10) {
                printf("Error: word too long (max 10 characters)\n");
                return -1;
            }
            sentence[wordCount][charCount++] = ch;
        } else {
            printf("Error: invalid character (only Latin letters allowed)\n");
            return -1;
        }
    }
    
    if (!hasWords) {
        printf("Error: empty sentence\n");
        return -1;
    }
    
    return wordCount;
}

int stringLength(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }
    return ch;
}

int compareWordsIgnoreCase(char *word1, char *word2) {
    int i = 0;
    while (word1[i] != '\0' && word2[i] != '\0') {
        if (toLower(word1[i]) != toLower(word2[i])) {
            return 0;
        }
        i++;
    }
    return word1[i] == '\0' && word2[i] == '\0';
}

int isWordInSentence(char *word, char sentence[][Max_word_len], int count) {
    for (int i = 0; i < count; i++) {
        if (compareWordsIgnoreCase(word, sentence[i])) {
            return 1;
        }
    }
    return 0;
}

void findShortestUniqueWord(char sentence1[][Max_word_len], int count1, 
                            char sentence2[][Max_word_len], int count2) {
    int minLen = 11;
    int minIndex = -1;
    
    for (int i = 0; i < count1; i++) {
        if (!isWordInSentence(sentence1[i], sentence2, count2)) {
            int len = stringLength(sentence1[i]);
            if (len < minLen) {
                minLen = len;
                minIndex = i;
            }
        }
    }
    
    if (minIndex == -1) {
        printf("Not found\n");
    } else {
        printf("%s\n", sentence1[minIndex]);
    }
}

int main() {
    char sentence1[Max_sentence_len][Max_word_len];
    char sentence2[Max_sentence_len][Max_word_len];
    
    printf("Enter first sentence: ");
    int count1 = inputSentence(sentence1);
    if (count1 == -1) {
        return 1;
    }
    
    printf("Enter second sentence: ");
    int count2 = inputSentence(sentence2);
    if (count2 == -1) {
        return 1;
    }
    
    findShortestUniqueWord(sentence1, count1, sentence2, count2);
    
    return 0;
}
