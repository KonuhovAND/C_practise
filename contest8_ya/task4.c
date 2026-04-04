#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

void print_q(struct node *node) {
  if (node == NULL) {
    printf("0\n");
    return;
  }
  struct node *temp = NULL;
  for (temp = node; temp != NULL; temp = temp->next) {
    printf("%d", temp->value);
    if (temp->next != NULL) {
      printf(" ");
    }
  }
  printf("\n");
}

void push_t(struct node **node, int counter) {
  struct node *temp = malloc(sizeof(struct node));
  if (temp == NULL)
    return;
  temp->value = counter;
  temp->next = *node;
  *node = temp;
}

void pop_smoke(struct node **node) {
  if (*node == NULL)
    return;
  struct node *temp = *node;
  *node = (*node)->next;
  free(temp);
}

int main() {
  struct node *node = NULL;
  int size = 0;
  int value;
  int flag = 0;

  while (1) {
    int res = scanf("%d", &value) == 1;
    if (res == 1){
    if (value == 0) {
      continue;
    } else if (value > 0) {
      flag = 1;
      for (int i = 0; i < value; i++) {
        size++;
        push_t(&node, size);
      }
    } else if (value < 0) {
      int steps = -value;
      flag = 1;
      for (int i = 0; i < steps; i++) {
        if (node == NULL) {
          break;
        }
        pop_smoke(&node);
        size--;
      }
    }    print_q(node);
    }else {
        if (getchar() == '.'){
            if (node == NULL &&  !flag) printf("0\n");
            break;
        }
      }

  }
  
  while (node != NULL) {
    pop_smoke(&node);
  }
  
  return 0;
}
