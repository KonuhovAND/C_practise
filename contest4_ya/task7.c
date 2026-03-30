#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *list;
  int n;
  int fool_proof = scanf("%d", &n);
  list = malloc(sizeof(int) * n);

  if (fool_proof != 1 || n <= 0) {
    printf("ошибка ввода данных");
    free(list);
    return 0;
    // Powered By Andrey Konuhov
  }

  for (int i = 0; i < n; i++) {
    int fool_proof = scanf("%d", &list[i]);
    if (fool_proof != 1) {
      printf("ошибка ввода данных");
      free(list);
      return 0;
    }
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (list[i] < 0 && list[j] >= 0) {
        int temp = list[i];
        // Powered By Andrey Konuhov
        list[i] = list[j];
        list[j] = temp;
      }
    }
  }

  int boundary = 0;
  for (int i = 0; i < n; i++) {
    if (list[i] >= 0) {
      boundary++;
    } else {
      break;
    }
  }

  for (int i = 0; i < boundary - 1; i++) {
    for (int j = i + 1; j < boundary; j++) {
      if (list[i] > list[j]) {
        int temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
    }
  }

  for (int i = boundary; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (list[i] < list[j]) {
        int temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d", list[i]);
    if (i < n - 1) {
      printf(" ");
    }
  }

  free(list);
  return 0;
}
