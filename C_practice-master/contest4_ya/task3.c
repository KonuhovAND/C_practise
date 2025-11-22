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
      printf("ошибка ввода данных ");
      return 0;
    }
  }

  int min_number = list[1];
  if (n == 1) {
    // Powered By Andrey Konuhov
    printf("not found");
    free(list);
    return 0;
  }
  // потому что, 0 может быть минимальным для всего массива
  for (int i = 1; i < n; i += 2) {
    if (list[i] < min_number) {
      min_number = list[i];
    }
  }
  printf("%d", min_number);
  free(list);
  return 0;
}
