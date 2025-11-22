#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>

int main() {

  // Powered By Andrey Konuhov
  int first_n, second_n;
  setlocale(0, "");
  scanf("%d%d", &first_n, &second_n);
  if (second_n == 0) {
    printf("деление на 0");
    return 0;
  }
  if (first_n % second_n != 0) {
    printf("%d не делится на %d", first_n, second_n);
    return 0;
  }
  if (first_n % second_n == 0) {
    printf("%d делится на %d", first_n, second_n);
    return 0;
  }
  return 0;
}
