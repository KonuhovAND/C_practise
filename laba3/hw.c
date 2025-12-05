
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL)
    return NULL;
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

void append(struct Node **head, int data) {
  struct Node *newNode = createNode(data);
  if (newNode == NULL)
    return;

  if (*head == NULL) {
    *head = newNode;
    return;
  }

  struct Node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->prev = temp;
}

struct Node *inputList(const char *listName) {
  struct Node *head = NULL;
  int num;
  char ch;

  printf("%s (1 2 3. для конца): \n", listName);
  while (scanf("%d%c", &num, &ch) == 2) {
    append(&head, num);
    if (ch == '.')
      break;
  }

  return head;
}

void printList(struct Node *head) {
  if (head == NULL) {
    printf("пусто\n");
    return;
  }
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int getLength(struct Node *head) {
  int count = 0;
  struct Node *temp = head;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}

void freeList(struct Node *head) {
  while (head != NULL) {
    struct Node *temp = head;
    head = head->next;
    free(temp);
  }
}

/* Сливаем попеременно узлы из temp1 и temp2 в Result */
void mergeLists(struct Node **temp1, struct Node **temp2, struct Node **Result,
                struct Node **resultTail) {
  while (*temp1 != NULL && *temp2 != NULL) {
    // берём узел из первого списка
    struct Node *node1 = *temp1;
    *temp1 = node1->next;
    if (*temp1 != NULL)
      (*temp1)->prev = NULL;
    node1->next = NULL;
    node1->prev = NULL;

    if (*Result == NULL) {
      *Result = *resultTail = node1;
    } else {
      (*resultTail)->next = node1;
      node1->prev = *resultTail;
      *resultTail = node1;
    }

    // берём узел из второго списка
    struct Node *node2 = *temp2;
    *temp2 = node2->next;
    if (*temp2 != NULL)
      (*temp2)->prev = NULL;
    node2->next = NULL;
    node2->prev = NULL;

    (*resultTail)->next = node2;
    node2->prev = *resultTail;
    *resultTail = node2;
  }
}

void task(struct Node **temp1, struct Node **temp2, struct Node **Result,
          struct Node **resultTail) {
  int length_1 = getLength(*temp1);
  int length_2 = getLength(*temp2);

  mergeLists(temp1, temp2, Result, resultTail);

  if (length_1 > length_2 && *temp1 != NULL) {
    struct Node *node1 = *temp1;
    *temp1 = node1->next;
    if (*temp1 != NULL)
      (*temp1)->prev = NULL;
    node1->next = NULL;
    node1->prev = NULL;

    if (*Result == NULL) {
      *Result = *resultTail = node1;
    } else {
      (*resultTail)->next = node1;
      node1->prev = *resultTail;
      *resultTail = node1;
    }
  }
}

int main() {
  setlocale(0, "");
  struct Node *list1 = NULL;
  struct Node *list2 = NULL;
  struct Node *result = NULL;

  list1 = inputList("Первый список");
  list2 = inputList("Второй список");

  printf("List1: \n");
  printList(list1);
  printf("List2: \n");
  printList(list2);

  struct Node *temp1 = list1;
  struct Node *temp2 = list2;
  struct Node *resultTail = NULL;

  task(&temp1, &temp2, &result, &resultTail);

  printf("Результат: \n");
  printList(result);

  if (temp1 != NULL) {
    printf("Остаток List1: \n");
    printList(temp1);
  } else if (temp2 != NULL) {
    printf("Остаток List2: \n");
    printList(temp2);
  } else {
    printf("Остатка нет\n");
  }

  freeList(result);
  freeList(temp1);
  freeList(temp2);

  return 0;
}
