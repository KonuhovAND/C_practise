
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>

struct List {
    int value;
    struct List *next;
};

struct List *createList(int data) {
  struct List *newList = (struct List *)malloc(sizeof(struct List));
  if (newList == NULL)
    return NULL;
  newList->value = data;
  newList->next = NULL;
  return newList;
}

void push_back(struct List **head, int data) {
  struct List *newList = createList(data);
  if (newList == NULL)
    return;

  if (*head == NULL) {
    *head = newList;
    return;
  }

  struct List *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newList;
}

struct List *inputList(const char *listName) {
  struct List *head = NULL;
  int num;
  char ch;

  printf("%s 1 1 1; для конца: \n", listName);
  while (scanf("%d%c", &num, &ch) == 2) {
    push_back(&head, num);
    if (ch == ';') break;
    if (ch == '\n' || ch == EOF) break;
  }

  return head;
}

void print_list(struct List *head) {
    for (struct List *p = head; p; p = p->next)
        printf("%d ", p->value);
    printf("\n");
}

void free_list(struct List *head) {
    while (head) {
        struct List *t = head->next;
        free(head);
        head = t;
    }
}

struct List *filter_list(struct List *head) {
    if (!head)
        return NULL;

    int first = head->value;

    struct List *p = head;
    struct List *prev = NULL;

    while (p) {
        if (p->value > first) {
            struct List *del = p;
            p = p->next;
            if (prev) prev->next = p;
            else {     
            head = p;}
            if (!head) return NULL;
            free(del);
        } else {
            prev = p;
            p = p->next;
        }
    }
    return head;
}

int main(void) {
    int n, x;
    struct List *head = NULL;

    head = inputList("");
    printf("Исходный список:\n");
    print_list(head);

    head = filter_list(head);

    printf("Преобразованный список:\n");
    print_list(head);

    free_list(head);
    return 0;
}
