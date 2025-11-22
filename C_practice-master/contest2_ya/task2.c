#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>

int main() {
  setlocale(0, "");
  float x, y;
  int flag1, flag2;

  // Powered By Andrey Konuhov

  double res;
  flag1 = scanf("%f", &x);
  flag2 = scanf("%f", &y);
  if (flag1 == 0 || flag2 == 0) {
    printf("ошибка ввода данных");
    return 0;
  }

  res = x * x + y * y;
  if (res <= 1.0) {
    printf("2 очка");
    return 0;
  } else if (res <= 4.0) {
    printf("1 очко");
    return 0;
  } else {
    printf("0 очков");
  }
  return 0;
}
