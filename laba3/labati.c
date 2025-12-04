#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node *next;
};

struct Node *create_node(int value) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  if (new_node == NULL) {
    printf("Ошибка выделения памяти\n");
    return NULL;
  }
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

struct Node *add_node(struct Node *head, struct Node *new_node) {
  if (head == NULL) {
    return new_node;
  }
  struct Node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
  return head;
}

struct Node *read_numbers(struct Node *head, int max_size) {
  int count = 0;
  int value;
  printf("Введите числа:\n");
  while (scanf("%d", &value) == 1 && count < max_size) {
    struct Node *new_node = create_node(value);
    if (new_node != NULL) {
      head = add_node(head, new_node);
      count++;
    }
  }
  return head;
}

struct Node *extract_negative(struct Node *head, struct Node *negative_head) {
  struct Node *current = head;
  while (current != NULL) {
    if (current->value < 0) {
      struct Node *new_node = create_node(current->value);
      if (new_node != NULL) {
        negative_head = add_node(negative_head, new_node);
      }
    }
    current = current->next;
  }
  return negative_head;
}

struct Node *sort_list(struct Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  int swapped;
  do {
    swapped = 0;
    struct Node *current = head;
    while (current->next != NULL) {
      if (current->value > current->next->value) {
        int temp = current->value;
        current->value = current->next->value;
        current->next->value = temp;
        swapped = 1;
      }
      current = current->next;
    }
  } while (swapped);
  return head;
}

void print_list(struct Node *head) {
  printf("Результат:\n");
  if (head == NULL) {
    printf("Отрицательных элементов нет\n");
    return;
  }
  struct Node *current = head;
  while (current != NULL) {
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
}

void free_list(struct Node *head) {
  struct Node *current = head;
  while (current != NULL) {
    struct Node *next = current->next;
    free(current);
    current = next;
  }
}

int main() {
  struct Node *head = NULL;
  struct Node *negative_head = NULL;

  head = read_numbers(head, MAX_SIZE);
  negative_head = extract_negative(head, negative_head);
  negative_head = sort_list(negative_head);
  print_list(negative_head);

  free_list(head);
  free_list(negative_head);

  return 0;
}
