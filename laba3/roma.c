#include <stdio.h>
#define N 20
#define M 20

int find_str(int a[], int m) {
    for (int j = 0; j < m; j++)
        if (a[j] % 2 != 0)
            return 0;
    for (int j = 1; j < m; j++)
        if (a[j] < a[j - 1])
            return 0;

    return 1;                 
}

int main() {
    int A[N][M], B[N][M];
    int n, m;

    printf("Введите количество строк: ");
    if(scanf("%d", &n)!=1 || n<=0){
        printf("Ошибка");
        return 0;
    }
    printf("Введите количество столбцов: ");
    if(scanf("%d", &m)!=1 || m<=0){
        printf("Ошибка");
        return 0;
    }
    printf("Введите матрицу %d x %d:\n", n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);

    int del = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (find_str(A[i], m)) {
            del = i;
            break;
        }
    }
    int new_n = n;
    if (del != -1) new_n--;   

    int bi = 0;
    for (int i = 0; i < n; i++) {
        if (i == del) continue;
        for (int j = 0; j < m; j++)
            B[bi][j] = A[i][j];
        bi++;
    }

    printf("Матрица B:\n");
    for (int i = 0; i < new_n; i++) {
        for (int j = 0; j < m; j++)
            printf("%3d", B[i][j]);
        printf("\n");
    }

    return 0;
}