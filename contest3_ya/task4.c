#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Powered By Andrey Konuhov
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
  int i = 1;
  int counter = 0;

  // Powered By Andrey Konuhov
  int x = scanf("%d", &n);
  if (x == 0 || n <= 0) {
    printf("ERROR");
    return 0;
  }

  while (counter < n) {
    if (is_prime(i)) {
      printf("%d ", i);
      counter += 1;
    }
    i++;
  }

  return 0;
}
