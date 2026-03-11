#include <stdio.h>

#define N 1001

void get_input(char *s) {
    int i = 0;
    char c;
    while (scanf("%c", &c) == 1 && c != '.') {
        if (i < N - 1) s[i++] = c;
    }
    s[i] = '\0';
}

void solve() {
    char s[N], t[N], res[N];
    get_input(s);
    scanf("%s", t);

    int i = 0, k = 0, first = 1;
    int t_len = 0;
    while (t[t_len]) t_len++;

    while (s[i]) {
        while (s[i] == ' ') i++;
        if (!s[i]) break;

        int start = i;
        while (s[i] && s[i] != ' ') i++;
        int end = i;

        int match = 1;
        if (end - start != t_len) {
            match = 0;
        } else {
            for (int j = 0; j < t_len; j++) {
                char c1 = s[start + j];
                char c2 = t[j];
                if (c1 >= 'A' && c1 <= 'Z') c1 += 32;
                if (c2 >= 'A' && c2 <= 'Z') c2 += 32;
                if (c1 != c2) {
                    match = 0;
                    break;
                }
            }
        }

        if (!match) {
            if (!first) res[k++] = ' ';
            
            for (int j = start; j < end; j++) {
                char cur = s[j];
                if (first && j == start) {
                    if (cur >= 'a' && cur <= 'z') cur -= 32;
                }
                res[k++] = cur;
            }
            first = 0;
        }
    }
    res[k] = '\0';

    if (k == 0) printf("Empty\n");
    else printf("%s.\n", res);
}

int main() {
    solve();
    return 0;
}