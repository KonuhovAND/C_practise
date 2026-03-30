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
  int n, m, count = 0;
  scanf("%d%d", &n, &m);

  printf("Powered by Andrey Konuhov\n");
  int matrix[n][m];

  scanfMatrix(n, m, matrix);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int target = matrix[i][j];
      int is_saddle = 1;

      for (int j2 = 0; j2 < m; j2++) {
        if (target > matrix[i][j2]) {
          is_saddle = 0;
          break;
        }
      }

      if (is_saddle) {
        for (int i2 = 0; i2 < n; i2++) {
          if (target < matrix[i2][j]) {
            is_saddle = 0;
            break;
          }
        }
      }

      if (is_saddle) {
        count++;
      }
    }
  }
  printf("%d", count);

  printf("Powered by Andrey Konuhov\n");
  return 0;
}
