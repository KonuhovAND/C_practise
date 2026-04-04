#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
    struct node *prev;
};

void print_deque(struct node *head, struct node *tail) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->value);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void push_left(struct node **head, struct node **tail, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) return;
    new_node->value = value;
    new_node->next = *head;
    new_node->prev = NULL;
    if (*head == NULL) {
        *tail = new_node;
    } else {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void push_right(struct node **head, struct node **tail, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) return;
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = *tail;
    if (*tail == NULL) {
        *head = new_node;
    } else {
        (*tail)->next = new_node;
    }
    *tail = new_node;
}

void pop_left(struct node **head, struct node **tail) {
    if (*head == NULL) return;
    struct node *temp = *head;
    *head = (*head)->next;
    if (*head == NULL) {
        *tail = NULL;
    } else {
        (*head)->prev = NULL;
    }
    free(temp);
}

void pop_right(struct node **head, struct node **tail) {
    if (*tail == NULL) return;
    struct node *temp = *tail;
    *tail = (*tail)->prev;
    if (*tail == NULL) {
        *head = NULL;
    } else {
        (*tail)->next = NULL;
    }
    free(temp);
}

int main() {
    struct node *head = NULL;
    struct node *tail = NULL;
    int value;
    int flag = 0;

    while (1) {
    int res = scanf("%d", &value) == 1;
    if (res == 1) {
        if (value == 0) {
          continue;
        } else if (value > 0) {
            flag = 1;
          if (value % 2 == 0) {
              for (int i = 0;i < value ; i++) {
                  push_left(&head, &tail,i+1 );
              }
          } else {
              for (int i = 1; i <= value; i++) {
                  push_right(&head, &tail, i);
              }
          }
          print_deque(head, tail);
        } else {
            flag = 1;
            int count = -value;
            int removed = 0;
          if (count % 2 == 1) {
            for (int i = 0; i < count && head != NULL; i++) {
                pop_left(&head, &tail);
                removed++;
            }
          } else {
            for (int i = 0; i < count && tail != NULL; i++) {
                pop_right(&head, &tail);
                removed++;
            }
          }
            print_deque(head, tail);
        }
    } else {
        if (getchar() == '.') {
            if (head == NULL && !flag) printf("0\n");
            break;
        }
    }
    }
    
    while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }    
    return 0;
}
