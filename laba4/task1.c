#define MaxLenth 101
#include <stdio.h>
#include <locale.h>

int findFirstNumber(){
    int index = 0;
    char ch;
    while (scanf("%d",&index) != 1){
        scanf("%c",&ch);
    }
    if (index >=1){
        return index;
    }
    return 0;
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
    int indexOfWord,iChar=0,iWord =1;
    enterSentence(str);
    indexOfWord = findFirstNumber();
    

    while (str[iChar] != '\0'){
        if (indexOfWord == iWord){
            while(str[iChar] != ' ' && str[iChar] != '\0'){
                printf("%c",str[iChar]);
                iChar++;
            }
            return 0;
        }
        while(str[iChar] != ' ' && str[iChar] != '\0'){
            iChar++;
        }
        if (str[iChar] == ' '){
            iChar++;
            iWord++;
        }
    }
    printf("Not found");
    return 0;
}
