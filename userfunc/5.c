#include <stdio.h>

#define SIZE 1001

void get_text(char *s) {
    int n = 0;
    char c;
    while (scanf("%c", &c) == 1 && c != '.') {
        if (n < SIZE - 1) s[n++] = c;
    }
    s[n] = '\0';
}

void flip(char *s, int i, int j) {
    while (i < j) {
        char t = s[i];
        s[i++] = s[j];
        s[j--] = t;
    }
}

void process(char *s) {
    int len = 0;
    while (s[len]) len++;
    
    if (len == 0) return;

    flip(s, 0, len - 1);

    int cur = 0;
    int words = 0;
    int last_start = 0;

    while (cur < len) {
        while (s[cur] == ' ' && cur < len) cur++;
        if (cur >= len) break;

        int start = cur;
        while (s[cur] != ' ' && s[cur] != '\0') cur++;
        
        flip(s, start, cur - 1);
        
        if (words == 0) {
            if (s[start] >= 'a' && s[start] <= 'z') 
                s[start] = s[start] - 32;
        }
        
        last_start = start;
        words++;
    }

    if (words > 1) {
        if (s[last_start] >= 'A' && s[last_start] <= 'Z') 
            s[last_start] = s[last_start] + 32;
    }
}

int main() {
    char str[SIZE];
    get_text(str);
    process(str);
    
    // Вывод
    for (int i = 0; str[i]; i++) putchar(str[i]);
    printf(".\n");

    return 0;
}