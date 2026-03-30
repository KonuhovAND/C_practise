#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
  int rows, colums;
  char elem;
  scanf("%d%d", &rows, &colums);
  scanf("%c", &elem);
  // Powered By Andrey Konuhov
  scanf("%c", &elem);
  for (int row = 1; row <= rows; row += 1) {
    for (int colum = 1; colum <= colums; colum += 1) {
      printf("%c", elem);
    }
    printf("\n");
  }
  return 0;
}
