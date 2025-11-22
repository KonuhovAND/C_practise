#define _CRT_SECURE_NO_WARNINGS
#define N 100
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  setlocale(0, "");
  // its correct >>
  int i;
  char *massive, buff;
  int n;
  printf("Enter size of list: \n");
  int fool_proof = scanf("%d", &n);
  scanf("%c", &buff); // >> important for characters

  // int m[n]; - can be possible, but its incorrect

  // динамично выделили память, не из стека, а из кучи
  massive = malloc(sizeof(char) * n);

  if (massive == NULL) {
    printf("Error in memory\n");
    return 0;
  }
  printf("Enter elem of list: \n");
  for (int i = 0; i < n; i++) {
    int fool_proof = scanf("%c", &massive[i]);
  }

  // printf("Entered list: \n");
  // for (i= 0;i < n; i++){
  //     printf("%d ",massive[i]);
  // }
  // printf("\n");
  // for (int i = 0; i < n; i++)
  // {
  //     /* code */
  //     if (massive[i] % 3 == 0){
  //         printf("%d ",i);
  //     }
  // }

  // printf("\n");
  //  int min,max;
  //  int imin,imax;
  //  min = max = massive[0];
  //  imax = imin = 0;
  //  for (int i = 0; i < n; i++)
  //  {
  //      if (max < massive[i]){
  //          max = massive[i];
  //          imax = i;
  //      }

  //     if (min > massive[i]){
  //         min = massive[i];
  //         imin = i;
  //     }
  // }
  // printf("\n max = %d\n min = %d",max,min);
  // printf("imax = %d\n imin = %d\n",imax,imin);

  // massive[imin] = max;
  // massive[imax] = min;
  // int flag = 0;

  // for (int i = 0; i < n - 1; i++)
  // {
  //     /* code */
  //     if (massive[i] > massive[i+1]){
  //         printf("Massive is not sorted!\n");
  //         flag = 1;
  //         //return 0; -- okay, but break more suitable
  //         break;
  //     }

  // }
  // if (!flag){
  // printf("Massive is sorted!))\n");
  // }

  // int tmp,k = 1;
  // while (k){
  //     for (i = 0,k = 0; i < n - 1; i++)
  //     {
  //         if (massive[i] > massive[i+1]){
  //             tmp = massive[i];
  //             massive[i] = massive[i+1];
  //             massive[i+1] = tmp;
  //             k++;
  //         }
  //    }
  // }

  printf("Entered list: \n");
  for (int i = 0; i < n; i++) {
    printf("%c ", massive[i]);
  }

  free(massive);
  return 0;
}
