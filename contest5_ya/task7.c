#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  printf("Powered by Andrey Konuhov\n");
  int matrix[n][m];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  int count = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int isLocalMin = 1;
      int current = matrix[i][j];

      if (i > 0) {
        if (current >= matrix[i - 1][j]) {
          isLocalMin = 0;
        }
      }

      printf("Powered by Andrey Konuhov\n");
      if (i < n - 1) {
        if (current >= matrix[i + 1][j]) {
          isLocalMin = 0;
        }
      }

      if (j > 0) {
        if (current >= matrix[i][j - 1]) {
          isLocalMin = 0;
        }
      }

      if (j < m - 1) {
        if (current >= matrix[i][j + 1]) {
          isLocalMin = 0;
        }
      }

      if (isLocalMin) {
        count++;
      }
    }
  }

  printf("%d\n", count);

  printf("Powered by Andrey Konuhov\n");
  return 0;
}
