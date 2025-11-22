#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <locale.h>
int is_prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}
int main() {
  int n;
  int x = scanf("%d", &n);
  if (x == 0 || n <= 0) {
    printf("ERROR");
    // Powered By Andrey Konuhov
    return 0;
  }
  if (is_prime(n)) {
    printf("YES");
    return 0;
  } else {
    printf("NO");
    // Powered By Andrey Konuhov
    return 0;
  }
}
