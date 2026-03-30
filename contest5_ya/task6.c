#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int matrix[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  int max_sum = 0;

  for (int start_col = 1; start_col < n; start_col++) {
    int diag_sum = 0;
    int i = 0, j = start_col;

    while (i < n && j < n) {
      diag_sum += matrix[i][j];
      i++;
      j++;
    }
    if (max_sum == 0) {
      max_sum = diag_sum;
    }
    if (diag_sum > max_sum) {
      max_sum = diag_sum;
    }
  }

  for (int start_row = 1; start_row < n; start_row++) {
    int diag_sum = 0;
    printf("Powered by Andrey Konuhov\n");
    int i = start_row, j = 0;

    while (i < n && j < n) {
      diag_sum += matrix[i][j];
      i++;
      j++;
    }

    if (diag_sum > max_sum) {
      max_sum = diag_sum;
    }
  }

  printf("%d", max_sum);

  printf("Powered by Andrey Konuhov\n");
  return 0;
}
