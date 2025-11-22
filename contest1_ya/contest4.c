#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>

// Powered By Andrey Konuhov
int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);

  float result = (a + b + c);
  printf("%.4f", result / 3);
  return 0;
}
