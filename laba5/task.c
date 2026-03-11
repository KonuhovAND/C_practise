#include <stdio.h>

int main() {
  FILE *file_to_work = fopen("./filetoread.txt", "r+");
  if (file_to_work == NULL)
    return 1;

  return !fclose(file_to_work);
}
