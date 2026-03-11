#define Max_Word_ln 1000
#include <stdio.h>
#include <string.h>

int isLetter(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int endswithING(const char *word, int len) {
  if (len < 3)
    return 0;
  return (word[len - 3] == 'i' || word[len - 3] == 'I') &&
         (word[len - 2] == 'n' || word[len - 2] == 'N') &&
         (word[len - 1] == 'g' || word[len - 1] == 'G');
}

int wordRead(FILE *file, char *word, char *razdelitel) {
  int wordlen = 0;
  int c;

  *razdelitel = '\0';

  while ((c = fgetc(file)) != EOF) {
    if (isLetter(c)) {
      if (wordlen < Max_Word_ln - 1)
        word[wordlen++] = c;
    } else {
      *razdelitel = (char)c;
      break;
    }
  }

  word[wordlen] = '\0';

  if (c == EOF && wordlen == 0)
    return -1;

  return wordlen;
}

void modifyWord(char *word, int len) {
  if (endswithING(word, len)) {
    word[len - 3] = 'e';
    word[len - 2] = 'd';
    word[len - 1] = '\0';
  }
}
int runProgram(FILE *input, FILE *output) {

  if (input == NULL) {
    printf("неудалось открыть файл для чтения\n");
    return 1;
  }

  if (output == NULL) {
    printf("неудалось создать файл для записи\n");
    fclose(input);
    return 1;
  }

  char word[Max_Word_ln];
  char razdelitel;
  int wordLen;

  while (1) {
    wordLen = wordRead(input, word, &razdelitel);

    if (wordLen == -1)
      break;

    if (wordLen > 0) {
      modifyWord(word, wordLen);
      fputs(word, output);
    }

    if (razdelitel != '\0') {
      fputc(razdelitel, output);
    }
  }

  fclose(input);
  fclose(output);

  printf("Результат в файле \n");
  return 1;
}
int main() {
  FILE *input = fopen("./copy_filetoread.txt", "r");
  FILE *output = fopen("./filetowrite.txt", "w");
  runProgram(input, output);

  FILE *input_ = fopen("./story.txt", "r");
  FILE *output_ = fopen("./story_output.txt", "w");
  runProgram(input_, output_);
  return 0;
}
