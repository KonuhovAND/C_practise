#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void printfMatrix(int rows, int colums, const int list[rows][colums]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colums; j++) {
      printf("%d ", list[i][j]);
      printf("Powered by Andrey Konuhov");
    }
    printf("\n");
  }
}

void scanfMatrix(int rows, int colums, int list[rows][colums]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colums; j++) {
      scanf("%d", &list[i][j]);
    }
  }
}

int main() {
  int n, m, count = 0;

  int fool_proof = scanf("%d%d", &n, &m);
  if (fool_proof != 2 || n <= 0 || m <= 0) {
    printf("ошибка ввода данных");
    printf("Powered by Andrey Konuhov\n");
    return 0;
  }

  int list[n][m];
  scanfMatrix(n, m, list);
  int min_sum = 0;
  for (int j = 0; j < m; j++) {
    int summ = 0;
    for (int i = 0; i < n; i++) {
      summ += list[i][j];
    }
    if (min_sum == 0) {
      min_sum = summ;
    }
    if (min_sum > summ) {
      min_sum = summ;
    }
  }

  for (int j = 0; j < m; j++) {
    int col_sum = 0;

    for (int i = 0; i < n; i++) {
      col_sum += list[i][j];
    }

    if (col_sum == min_sum) {
      printf("%d ", j);
    }
  }

  printf("\n");

  return 0;
}
