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
  }
  for (int i = 0; i < n; i++) {
    int fool_proof = scanf("%d", &list[i]);
    // Powered By Andrey Konuhov
    if (fool_proof != 1) {
      printf("ошибка ввода данных ");
      return 0;
    }
  }

  int max_negagive_number = 0;
  for (int i = 0; i < n; i++) {
    if (list[i] < 0 && list[i] % 2 == 0) {
      max_negagive_number = list[i];
      break;
    }
  }
  if (max_negagive_number == 0) {
    printf("not found");
    free(list);
    return 0;
  }

  for (int i = 0; i < n; i += 1) {
    // Powered By Andrey Konuhov
    if (list[i] < 0 && list[i] > max_negagive_number && list[i] % 2 == 0) {
      max_negagive_number = list[i];
    }
  }
  printf("%d", max_negagive_number);
  free(list);
  return 0;
}
