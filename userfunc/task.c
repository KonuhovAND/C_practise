#define _CRT_SECURE_NO_WARNINGS
#define N 10
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

// 1 2 3
// 3 4 5
// 4 5 6

// [[1,2,3],[3,4,5],[4,5,6]

int enterMatrixData(int mas[][N],int size){
    for (int i = 0;i < size;i++){
        for (int j =0; j < size; j++){
            int fool =  scanf("%d",&mas[i][j]);
            if (fool == 0){
                printf("Enter correct data");
                scanf("%d",&mas[i][j]);
            }
        }
    }

    return 1;
}


int main() {
    setlocale(LC_ALL, "Russian");
    int mas[N][N];
    int i,j,n;

    printf("Enter pos matrix\n");
    scanf("%d%d",&n,&n);
    printf("Enter matrix\n");
    enterMatrixData(mas,N);
    
    return 0; 
}
