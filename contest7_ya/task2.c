#define MaxLenth 101
#include <stdio.h>
#include <locale.h>

void printIndexOfMatchedWords(char *str, char *substr) {
    int i = 0, iWord = 1;
    int foundAny = 0;

    if (substr[0] == '\0') return;

    while (str[i] != '\0') {
        int wordMatch = 0;

        while (str[i] != ' ' && str[i] != '\0') {
            
            int j = 0;
            while (str[i + j] != '\0' && str[i + j] != ' ' && substr[j] != '\0') {
                char c1 = str[i + j];
                char c2 = substr[j];

                if (c1 >= 'A' && c1 <= 'Z') c1 += 32;
                if (c2 >= 'A' && c2 <= 'Z') c2 += 32;

                if (c1 != c2) break;
                j++;
            }

            if (substr[j] == '\0') {
                wordMatch = 1;
            }
            
            i++; 
        }

        if (wordMatch) {
            if (foundAny) printf(" "); 
            printf("%d", iWord);
            foundAny = 1;
        }

        if (str[i] == ' ') {
            iWord++;
            i++;
        }
    }

    if (!foundAny) {
        printf("Not found.");
    }
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

int enterSubstr(char *str) {
    char ch;
    int i = 0;
    do {
        if (scanf("%c", &ch) != 1) return 0;
    } while (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')));

    while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        str[i++] = ch;
        if (scanf("%c", &ch) != 1) break;
    }
    str[i] = '\0';
    return 0;
}

int main(){
    char str[MaxLenth],substr[MaxLenth];
    int indexOfWord,iChar=0,iWord =1;
    enterSentence(str);
    enterSubstr(substr);

    printIndexOfMatchedWords(str,substr);
    return 0;
}
