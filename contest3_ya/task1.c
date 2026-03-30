#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <locale.h>

// Powered By Andrey Konuhov
// Powered By Andrey Konuhov
int main() {

  int n, s = 0, j = 0;

  int x = scanf("%d", &n);
  if (x == 0 || n <= 0) {
    printf("ошибка ввода данных");
    return 0;
  }
  for (int I = 2;; I += 2) {
    if (j == n) {
      break;
    }
    j++;
    s += I;
  }

  printf("Сумма первых %d положительных четных чисел равна %d", n, s);
  return 0;
}
