#define _CRT_SECURE_NO_WARNINGS
// макро определение
#define INCH 2.54 
#include <stdio.h>
#include <locale.h>



// int main(){
//     int a;
//     scanf("%d",&a);
//     float r = a * INCH;
//     printf("%.2f",r);
//     return 0;
// }

// Условный оператор
int ifelseexample(){
    int a;
    float b,r1,r2;
    r1 = 10; r2 = 10;
    setlocale(0,"");
    scanf("%d%f",&a,&b);

    // bad example, deep diving in that radit hole 
    // if (a > b)
    //     printf("%d > %d",a,b);
    // else
    //     if (a < b)
    //         printf("%d<%d",a,b);
    //         else
    //             printf('%d = %d',a,b);

    if (a > b)
        {
        printf("%d > %.2f",a,b);
        return 0;
        }
    if (a < b)
        {
        printf("%d<%.2f",a,b);
        return 0;
        }
    if (a == b)
        {
        printf("%d = %.2f",a,b);
        return 0;
        }
    return 0;
}


int scanf_example(){
    int a,b,x;
    setlocale(0,"");
    // защита от дурака
    x = scanf("%d",&a);
    // a = '',x = 0
    // a = 123, x = 1
    // a = 123.456,x = 0
    if(x == 0){
        printf("Entered not number!");
        return 0;
    }

    // b = 1.2, x = 1

    x = scanf("%d",&b);
     if(x == 0){
        printf("Entered not number!");
        return 0;
    }

   
    if (a > b)
        {
        printf("%d > %d",a,b);
        return 0;
        }
    if (a < b)
        {
        printf("%d<%d",a,b);
        return 0;
        }
    if (a == b)
        {
        printf("%d = %d",a,b);
        return 0;
        }
    return 0;
}

int protect_from_fool(){
    // int x; -> useless
    char a,b;
    setlocale(0,"");
    // useless
    // a = "any stuff", x = 1
    //     if(x == 0){
    //     printf("Entered not number!");
    //     return 0;
    // }

    // x = scanf("%d",&b);
    //  if(x == 0){
    //     printf("Entered not number!");
    //     return 0;
    // }

    // work poorly 
    // Enter... : a b
    // output: a
    scanf("Enter two characters: %c%c",&a,&b);
    
    char buf;
    scanf("%c",&a);
    scanf("%c",&buf);
    scanf("%c",&b);


    printf("%c %c",a,b);
   
    return 0;
}

int main(){
    char a,b,buf;
    setlocale(0,"");

    printf("Enter character\n");
    
    scanf("%c",&a);
    // (!(...)) - not 
    // (...) - character 
    if (!(a >= 'a' && a <= 'z'|| a >= 'A' && a <= 'Z')){
        printf("Enter character: ");
        scanf("%c",&a);
        return 0;

    }
    scanf("%c",&buf);
    scanf("%c",&b);

    printf("%c%c%c");    
    printf("%c >> %d",a,a);
    return 0;
}