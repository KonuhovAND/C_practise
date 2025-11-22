

## Правила:
- написана по принципу черного ящика, все ошибки проверяем внутри функции
- не может изменить свои параметры, типа  данные, которые мы передаем, мы не можем их изменить(работает с копиями)
- функция делает что-то одно

## Лекция

```c

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>


int calcInt(int x,int y){
    int sum;
    sum = x + y;
    return sum;
}

// * - указатель
void swap(int *x,int *y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
    return;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int a,b,s;
    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);
    s = calcInt(a,b);
    printf("%d+%d=%d\n",a,b,s);

    swap(&a,&b);
    printf("a=%d b=%d\n",a,b);

    // & - для указателей
    swap(&a,&b);
    printf("a=%d b=%d\n",a,b);


    return 0;
}
```

Не очень хорошо всегда использовать всегда указатели!
Потому что не явно указаны указатели!

### Прототипы функции
```c
int calcInt(int ,int );
void swap(int *,int *);
```

### Примеры функции

```c
int divisionInt(int x,int y, int *res)
{
    if (y == 0){
        return 0;
    }
    *res = x /y;
    return 1;
}

int main() {


    setlocale(LC_ALL, "Russian");
    int a,b;
    int res;
    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);

    if (divisionInt(a,b,&res) == 0){
        printf("Division by 0!\n");
    }
    printf("\n%d / %d = %d",a,b,res);

    return 0;
}

```


### Пример функц деления 

```c

int divisionInt(int x,int y, float *res)
{
    if (y == 0){
        return 0;
    }
    *res = 1.0 * x /y ;
    return 1;
}

int main() {


    setlocale(LC_ALL, "Russian");
    int a,b;
    float res;
    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);

    if (divisionInt(a,b,&res) == 0){
        printf("Division by 0!\n");
    }
    printf("\n%d / %d = %.2f",a,b,res);

    return 0;
}
```


### Передача массивов


```c
// * -для массива используется только указатели
void scanfMasCh(char *mas,int size)
{
    for (int i = 0; i < size;i++ ){
        scanf("%c",&mas[i]);
    }
    return;
}


// int return 1 - если все успешно, и 0 если не очень.
// int потому что мы вводим еще защиту от дурака
int scanfMasInt(int *mas,int size);

```

```c
// * -для массива используется только указатели
void scanfMasCh(char *mas,int size)
{
    for (int i = 0; i < size;i++ ){
        scanf("%c",&mas[i]);
    }
    return;
}
// * - очень правильно, потому что мы можем изменить внутри, но в целом ок
// но когда я убрал у меня компилятор ругался
void printMas(char *mas,int size){
    for (int i = 0; i < size; i++){
        printf("%c ",mas[i]);
    }
    return;
}

// с const нельзя ничего внутри изменить, что будет правильно
void printMas(const char *mas,int size){
    for (int i = 0; i < size; i++){
        printf("%c ",mas[i]);
    }
    return;
}

int main(){
    int mass[20]; // одномерные массивы это указатели
    scanfMasCh(mass,20);
    //...

}
```



### Матрицы


```c
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

```