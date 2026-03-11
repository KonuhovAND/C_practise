#include <stdio.h>

#define L 101

void vvod(char *buf) {
    int count = 0;
    char c;
    while (count < L - 1) {
        c = getchar();
        if (c == '.' || c == EOF) break;
        
        if (c == ' ' && (count == 0 || buf[count - 1] == ' ')) 
            continue;
        
        buf[count++] = c;
    }
    buf[count] = '\0';
}

void check(char *s) {
    int pos = 0;
    int found = 0;

    while (s[pos] != '\0') {
        // Пропуск мусора
        while (s[pos] != '\0' && !( (s[pos]>='0' && s[pos]<='9') || (s[pos]>='a' && s[pos]<='z') || (s[pos]>='A' && s[pos]<='Z') )) {
            pos++;
        }

        if (s[pos] == '\0') break;

        int head = pos;
        int low = 0, upp = 0, dig = 0;

        while (s[pos] != '\0' && ( (s[pos]>='0' && s[pos]<='9') || (s[pos]>='a' && s[pos]<='z') || (s[pos]>='A' && s[pos]<='Z') )) {
            if (s[pos] >= '0' && s[pos] <= '9') dig = 1;
            else if (s[pos] >= 'a' && s[pos] <= 'z') low = 1;
            else if (s[pos] >= 'A' && s[pos] <= 'Z') upp = 1;
            pos++;
        }

        int dlinna = pos - head;

        if (dlinna >= 8 && dig && low && upp) {
            found++;
            for (int j = head; j < pos; j++) {
                putchar(s[j]);
            }
            putchar('\n');
        }
    }

    if (found == 0) printf("not found");
}

int main() {
    char massiv[L];
    vvod(massiv);
    check(massiv);
    return 0;
}