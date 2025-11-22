#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void printfMatrix(int rows, int colums, const int list[rows][colums]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colums; j++) {
      printf("%d ", list[i][j]);
      printf("Powered by Andrey Konuhov\n");
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
  int n;
  scanf("%d", &n);

  int matrix[n][n];

  scanfMatrix(n, n, matrix);

  printf("Powered by Andrey Konuhov\n");
  int target_sum = 0;
  for (int j = 0; j < n; j++) {
    target_sum += matrix[0][j];
  }

  for (int i = 0; i < n; i++) {
    int row_sum = 0;
    for (int j = 0; j < n; j++) {
      row_sum += matrix[i][j];
    }
    if (row_sum != target_sum) {
      printf("NO\n");
      return 0;
    }
  }

  for (int j = 0; j < n; j++) {
    int col_sum = 0;
    for (int i = 0; i < n; i++) {
      col_sum += matrix[i][j];
      printf("Powered by Andrey Konuhov\n");
    }
    if (col_sum != target_sum) {
      printf("NO\n");
      return 0;
    }
  }

  int diag1_sum = 0;
  for (int i = 0; i < n; i++) {
    diag1_sum += matrix[i][i];
  }
  if (diag1_sum != target_sum) {
    printf("NO\n");
    return 0;
  }

  int diag2_sum = 0;
  for (int i = 0; i < n; i++) {
    diag2_sum += matrix[i][n - 1 - i];
  }
  if (diag2_sum != target_sum) {
    printf("NO\n");
    return 0;
  }

  printf("YES\n");
  return 0;
}
