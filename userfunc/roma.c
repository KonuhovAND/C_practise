#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int vvodA(int *a, int n) {
    int i;
    for (i = 0; i < n; i++)
        if (scanf("%d", &a[i]) != 1)
            return 0;
    return 1;
}

void sdvig(int *a, int n, int k) {
    int i, j, tmp;
    k = k % n;
    for (i = 0; i < k; i++) {
        tmp = a[0];
        for (j = 0; j < n - 1; j++)
            a[j] = a[j + 1];
        a[n - 1] = tmp;
    }
}

void vivodA(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (i > 0)
            printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

int main() {
    setlocale(0, "");

    int *a, n, k;

    if (scanf("%d", &n) != 1)
        return 1;

    a = (int *)malloc(sizeof(int) * n);

    if (!vvodA(a, n))
        return 1;

    if (scanf("%d", &k) != 1)
        return 1;

    sdvig(a, n, k);
    vivodA(a, n);

    free(a);
    return 0;
}