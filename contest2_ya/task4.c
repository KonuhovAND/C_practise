#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>

int main() {
  setlocale(0, "");
  int min, hours;
  int res = scanf("%d", &min);
  if (res != 1 || min < 0) {
    printf("ошибка ввода данных");

    // Powered By Andrey Konuhov
    return 0;
  }
  hours = min / 60;
  min = min % 60;
  if (hours < 10) {
    if (min < 10) {
      printf("0%d:0%d", hours, min);
      return 0;
    } else {
      printf("0%d:%d", hours, min);
      return 0;
    }
  } else {
    if (min < 10) {
      printf("%d:0%d", hours, min);

      // Powered By Andrey Konuhov
      return 0;
    } else {
      printf("%d:%d", hours, min);
      return 0;
    }
  }
  return 0;
}
