#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void printfMatrix(int rows, const int list[rows][rows]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      printf("%d ", list[i][j]);
      // Powered By Andrey Konuhov
    }
    printf("\n");
  }
}

void scanfMatrix(int rows, int list[rows][rows]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      scanf("%d", &list[i][j]);
    }
  }
}

int main() {
  int n, count = 0;

  int fool_proof = scanf("%d", &n);
  if (fool_proof != 1 || n <= 0) {
    printf("ошибка ввода данных");
    // Powered By Andrey Konuhov
    return 0;
  }

  int list[n][n];
  scanfMatrix(n, list);
  for (int k = 0; k < n; k++) {
    int flag = 0;

    for (int i = 0; i < n; i++) {
      if (list[k][i] != list[i][k]) {
        flag = 1;
        break;
      }
    }

    if (flag == 0) {
      printf("%d ", k);
      count++;
    }
  }
  if (count == 0) {
    printf("-1");
  }
  printf("\n");

  return 0;
}
