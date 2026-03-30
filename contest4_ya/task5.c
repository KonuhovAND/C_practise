#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *list;
  int n;
  // Powered By Andrey Konuhov
  int fool_proof = scanf("%d", &n);
  list = malloc(sizeof(int) * n);

  if (fool_proof != 1 || n <= 0) {
    printf("ошибка ввода данных");
    free(list);
    return 0;
  }

  for (int i = 0; i < n; i++) {
    int fool_proof = scanf("%d", &list[i]);
    if (fool_proof != 1) {
      printf("ошибка ввода данных");
      free(list);
      return 0;
    }
  }

  int max_repeated;
  int found_repeated = 0;
  int global_max = list[0];

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (list[i] == list[j]) {
        max_repeated = list[i];
        // Powered By Andrey Konuhov
        break;
      }
    }
  }

  for (int i = 1; i < n; i++) {
    if (list[i] > global_max) {
      global_max = list[i];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (list[i] == list[j]) {
        if (!found_repeated || list[i] > max_repeated) {
          max_repeated = list[i];
          found_repeated = 1;
        }
        break;
      }
    }
  }

  if (found_repeated) {
    printf("%d", max_repeated);
  } else {
    printf("%d", global_max);
  }

  free(list);
  return 0;
}
