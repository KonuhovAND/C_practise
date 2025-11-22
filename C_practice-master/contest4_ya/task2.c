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
      return 0;
    }
  }
  int count = 0;

  for (int i = 0; i < n; i++) {
    int is_unique = 1; // true
    for (int j = i + 1; j < n; j++) {
      if (list[i] == list[j]) {
        is_unique = 0; // false
        break;
        // Powered By Andrey Konuhov
      }
    }
    if (is_unique) {
      count++;
    }
  }
  printf("%d", n - count);
  free(list);
  return 0;
}
