#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Powered By Andrey Konuhov
int not_main() {
  int a, b, swap;
  swap = 0;
  scanf("%d%d", &a, &b);
  swap = b;
  b = a;
  a = swap;
  printf("%d %d", a, b);
  return 0;
}
