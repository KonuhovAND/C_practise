#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#define MAX_SIZE 20

void printMatrix(const double A[][MAX_SIZE], int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%8.2lf ", A[i][j]);
    }
    printf("\n");
  }
}

int enterMatrix(double A[][MAX_SIZE], int N) {
  printf("Введите элементы матрицы:\n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("A[%d][%d] = ", i, j);
      if (scanf("%lf", &A[i][j]) != 1) {
        printf("Ошибка ввода!\n");
        return 0;
      }
    }
  }
  return 1;
}

void buildNewMatrix(const double A[][MAX_SIZE], double B[][MAX_SIZE], int N) {
  int i, j;
  double sum;
  int neg_found = 0;
  double col_sum[MAX_SIZE];
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      sum = 0;
      for (int row = i; row < N; row++) {
        for (int column = j; column < N; column++) {
          if (A[row][column] < 0) {
            sum -= A[row][column];
            neg_found += 1;
          } else
            sum += A[row][column];
        }
      }
      B[i][j] = sum;
    }
  }

  printf("\nИсходная матрица A:\n");
  printMatrix(A, N);

  printf("\nРезультирующая матрица B:\n");
  printMatrix(B, N);

  if (!neg_found) {
    printf("\nВ матрице A нет строк с отрицательными элементами!\n");
  }
  if (B)
    printf("\nМатрица B успешно построена!\n");
}

int sizeMatrix(int *N) {
  printf("Введите размер матрицы N (не больше %d): ", MAX_SIZE);
  if (scanf("%d", N) != 1 || *N <= 0 || *N > MAX_SIZE) {
    printf("Ошибка: некорректный размер матрицы!\n");
    return 0;
  }
  return 1;
}

int main() {
  double A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE];
  int N;

  setlocale(0, "");
  if (!sizeMatrix(&N))
    return 1;

  if (!enterMatrix(A, N))
    return 1;
  buildNewMatrix(A, B, N);

  return 0;
}
