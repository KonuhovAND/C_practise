#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>

int main() {
  setlocale(0, "");

  // Powered By Andrey Konuhov
  int cows;
  int res = scanf("%d", &cows);

  if (res != 1) {
    printf("ошибка ввода данных");
    return 0;
  }

  if (cows <= 0 || cows >= 100) {
    printf("ошибка ввода данных");
    return 0;
  }

  int last_digit = cows % 10;
  int last_two = cows % 100;

  if (last_digit == 1 && last_two != 11) {
    printf("На лугу пасется %d корова.", cows);
  } else if (last_digit >= 2 && last_digit <= 4 &&
             !(last_two >= 12 && last_two <= 14)) {
    printf("На лугу пасется %d коровы.", cows);
  } else {
    printf("На лугу пасется %d коров.", cows);
  }

  return 0;
}
