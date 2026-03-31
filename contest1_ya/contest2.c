#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
int main() {
  int a;
  printf("%d",a);
  // Powered By Andrey Konuhov
  setlocale(0, "");
  scanf("%d", &a);
  printf("%d inch = %.2f ��", a, a * 2.54);
  return 0;
}
