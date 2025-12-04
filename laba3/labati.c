#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int read_numbers(int *numbers, int max_size) {
  int count = 0;
  printf("Введите числа:\n");
  while (scanf("%d", &numbers[count]) == 1 && count < max_size) {
    count++;
  }
  return count;
}

int extract_negative(int *numbers, int count, int *negative) {
  int neg_count = 0;
  for (int i = 0; i < count; i++) {
    if (numbers[i] < 0) {
      negative[neg_count++] = numbers[i];
    }
  }
  return neg_count;
}

void sort_array(int *array, int size) {
  qsort(array, size, sizeof(int), compare);
}

void print_result(int *negative, int neg_count) {
  printf("Результат:\n");
  if (neg_count == 0) {
    printf("Отрицательных элементов нет\n");
  } else {
    for (int i = 0; i < neg_count; i++) {
      printf("%d ", negative[i]);
    }
    printf("\n");
  }
}

int main() {
  int max_size = 1000;
  int *numbers = (int *)malloc(max_size * sizeof(int));
  int *negative = (int *)malloc(max_size * sizeof(int));

  setlocale(0, "");
  if (numbers == NULL || negative == NULL) {
    printf("Ошибка выделения памяти\n");
    return 1;
  }

  int count = read_numbers(numbers, max_size);
  int neg_count = extract_negative(numbers, count, negative);
  sort_array(negative, neg_count);
  print_result(negative, neg_count);

  free(numbers);
  free(negative);

  return 0;
}
