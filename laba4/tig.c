#define Max_word_len 21
#define Max_sentence_len 31

#include <locale.h>
#include <stdio.h>

int inpt(char s[][Max_word_len]) {
    char c;
    int wc = 0;
    int cc = 0;
    int hw = 0;
    
    printf("Введите предложение (завершите '.', '!' или '?'): ");
    
    while (scanf("%c", &c) == 1) {
        if (c == '.' || c == '!' || c == '?') {
            if (cc > 0) {
                s[wc][cc] = '\0';
                wc++;
                hw = 1;
            }
            break;
        }
        
        if (c == ' ' || c == '\n') {
            if (cc > 0) {
                s[wc][cc] = '\0';
                wc++;
                cc = 0;
                hw = 1;
                
                if (wc >= Max_sentence_len) {
                    printf("Ошибка: слишком много слов (максимум 30)\n");
                    return -1;
                }
            }
        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (cc >= Max_word_len-1) {
                printf("Ошибка: слово слишком длинное (максимум 20 символов)\n");
                return -1;
            }
            s[wc][cc++] = c;
        } else {
            printf("Ошибка: недопустимый символ (разрешены только латинские буквы)\n");
            return -1;
        }
    }
    
    if (!hw) {
        printf("Ошибка: пустое предложение\n");
        return -1;
    }
    
    return wc;
}

int slen(char *str) {
    int l = 0;
    while (str[l] != '\0') {
        l++;
    }
    return l;
}

void plw(char s[][Max_word_len], int c) {
    int ml = 0;
    
    for (int i = 0; i < c; i++) {
        int l = slen(s[i]);
        if (l > ml) {
            ml = l;
        }
    }
    
    printf("\nСамые длинные слова (длина %d):\n", ml);
    int f = 0;
    for (int i = 0; i < c; i++) {
        if (slen(s[i]) == ml) {
            printf("%s\n", s[i]);
            f = 1;
        }
    }
    
    if (!f) {
        printf("Слова не найдены\n");
    }
}

int main() {
    setlocale(LC_ALL, "");

    char sent[Max_sentence_len][Max_word_len];
    
    int cnt = inpt(sent);
    if (cnt == -1) {
        return 1;
    }
    
    plw(sent, cnt);
    
    return 0;
}