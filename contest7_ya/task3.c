#define MaxLenth 101
#include <stdio.h>
#include <locale.h>

void isPolindom(char *str){
    int i= 0,ir = -1;
    int isNotPolindrom = 0;
    while(str[i] != '\0'){ 
        ir++;
        i++;
    }
    i = 0;

    while (i < ir){
        if (str[i] == ' '){ 
            i++;
            continue;
        }
        if (str[ir] == ' '){
            ir--;
            continue;}
        char c1 = str[i];
        char c2 = str[ir];
        if (c1 >= 'A' && c1 <= 'Z') c1 += 32;
        if (c2 >= 'A' && c2 <= 'Z') c2 += 32;

        if (c1 != c2) {
            printf("NO\n");
            return; 
        }

        i++;
        ir--;
    }

    printf("YES\n");
}

int enterSentence(char *str){
    char ch;
    int i= 0;
    scanf("%c",&ch);
    while (1){
        while((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
            str[i] = ch;
            i++;
            if (i >= MaxLenth-1){
                printf("String is overload");
                return 1;
            }
            scanf("%c",&ch);
        }
        if(ch == ' '&& i!=0){
            str[i] = ' ';
            i++;
            if (i >= MaxLenth-1){
                printf("String is overload");
                return 1;
            } 
        }

        while(ch == ' ') 
            {scanf("%c",&ch);}
        
        if (ch =='.'){
            str[i] = '\0';
            break;
        }
    }
    return 0;
}



int main(){
    char str[MaxLenth];
    enterSentence(str);
    isPolindom(str);
    printf("%s.",str);
    return 0;
}
