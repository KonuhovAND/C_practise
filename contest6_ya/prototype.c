#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
  int inf;
  struct node *next;
};
void clear_line_with_scanf() {
  char c;
  while (scanf("%c", &c) == 1 && c != '\n') {
  }
}
int welcome() {
  int a;

  printf("Enter element 1(yes)/0(no): ");
  while (scanf("%d", &a) != 1 || a < 0 || a > 1) {
    printf("Entered incorrect data for a, try again: ");
    clear_line_with_scanf();
  }
  clear_line_with_scanf();

  if (a == 0) {
    printf("Process of adding element in node is ended! GoodBye!\n");
    return 0;
  }
  return 1;
}
void enterdata(struct node *t) {
  printf("Enter value for element: ");
  while (scanf("%d", &t->inf) != 1) {
    printf("You entred incorect data for element, please enter correct");
    clear_line_with_scanf();
  }
  clear_line_with_scanf();
}
void clear_node(struct node *b) {
  struct node *t;
  while (b != NULL) {
    t = b->next;
    free(b);
    b = t;
  }
}
struct node *vvodnode(struct node *b) {
  // b - начало линейного масива, e - конец линейного масива, t - временный
  // указатель
  struct node *e, *t;
  b = e = t = NULL;
  while (1) {
    if (welcome() == 0) {
      break;
    }
    t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL) {
      printf("Error in extrating memory for temp.pointer");
      break;
    }

    t->next = NULL;
    enterdata(t);

    if (b == NULL) {
      b = t;
      e = t;
    } else {
      e->next = t;
      e = t;
    }
    printf("Node is finished\n");
  }

  return b;
}

void printnode(struct node *b) {
  struct node *t;
  printf("Print node");
  for (t = b; t != NULL; t = t->next) {
    printf("%d ", t->inf);
  }
}

int main() {
  struct node *b, *t, *e;
  b = t = e = NULL;
  b = vvodnode(b);
  printnode(b);
  clear_node(b);
  return 0;
}
