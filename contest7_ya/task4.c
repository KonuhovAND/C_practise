#define MaxLenth 101
#include <stdio.h>

int enterStr(char *str) {
    char ch;
    int i = 0;
    char prev = '\0'; 
    
    while (scanf("%c", &ch) == 1 && ch != '.') {
        if (ch == ' ' && prev == ' ') {
            continue;
        }
        
        if (i < MaxLenth - 1) {
            str[i++] = ch;
            prev = ch;
        }
    }
    str[i] = '\0';
    return 0;
}

void isPassword(char *str) {
    int i = 0;
    int isFoundAny = 0;

    while (str[i] != '\0') {
        while (str[i] != '\0' && !(
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= '0' && str[i] <= '9')
        )) {
            i++;
        }

        if (str[i] == '\0') break;

        int istart = i;
        int hasA = 0, hasa = 0, hasd = 0;

        while (str[i] != '\0' && (
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= '0' && str[i] <= '9')
        )) {
            if (str[i] >= 'a' && str[i] <= 'z') hasa = 1;
            else if (str[i] >= 'A' && str[i] <= 'Z') hasA = 1;
            else if (str[i] >= '0' && str[i] <= '9') hasd = 1;
            i++;
        }

        int length = i - istart;

        if (length >= 8 && hasA && hasa && hasd) {
            isFoundAny = 1;
            for (int j = istart; j < i; j++) {
                printf("%c", str[j]);
            }
            printf("\n");
        }
    }

    if (isFoundAny == 0) {
        printf("not found");
    }
}

int main() {
    char str[MaxLenth];
    enterStr(str);
    isPassword(str);
    return 0;
}