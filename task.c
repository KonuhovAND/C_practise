#define _CRT_SECURE_NO_WARNINGS
#define K 2
#include <stdio.h>
#include <locale.h>
#include <ctype.h>


int isalpha_1(char ch){
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int main(int argc, char* argv[])
{
    FILE* in;
    char ch;
    int n;            
    int words;        
    int inWord;       
    long posStart;     
    long posEnd;      

    setlocale(0, "");

    if (argc != K)
    {
        printf("nevernoe kol-vo arg");
        return 1;
    }

    in = fopen(argv[1], "r");
    if (in == NULL)
    {
        printf("not found %s ", argv[1]);
        return 2;
    }

    printf("enter number of words: ");
    scanf("%d", &n);

    posStart = ftell(in);
    words = 0;
    inWord = 0;

    while (fscanf(in, "%c", &ch) == 1)
    {
        if (isalpha_1(ch))
        {
            if (inWord == 0)
            {
                inWord = 1;
                words++;
            }
        }
        else
        {
            inWord = 0;
            if (ch == '.' || ch == '?' || ch == '!')
            {
                posEnd = ftell(in);

                if (words == n)
                {
                    long cur = posEnd;
                    fseek(in, posStart, SEEK_SET);
                    long i;
                    for (i = posStart; i < posEnd; i++)
                    {
                        fscanf(in, "%c", &ch);
                        printf("%c", ch);
                    }
                    printf("\n");
                    fseek(in, cur, SEEK_SET);
                }

                posStart = posEnd;
                words = 0;
                inWord = 0;
            }
        }
    }

    fclose(in);
    return 0;
  }