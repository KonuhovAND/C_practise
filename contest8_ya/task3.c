#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void print_queue(struct Node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->value);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void push(struct Node **first_elem, struct Node **tail, int *count) {
    struct Node *temp = malloc(sizeof(struct Node));
    if (temp == NULL) return;
    
    temp->value = ++(*count);
    temp->next = NULL;
    
    if (*first_elem == NULL) {
        *first_elem = *tail = temp;
    } else {
        (*tail)->next = temp;
        *tail = temp;
    }
}

void pop(struct Node **first_elem, struct Node **tail) {
    if (*first_elem == NULL) return;
    
    struct Node *temp = *first_elem;
    *first_elem = (*first_elem)->next;
    
    if (*first_elem == NULL) {
        *tail = NULL;
    }
    free(temp);
}

int main() {
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int counter = 0;
    int cmd;
    char c;

    while (1) {
        c = getchar();
        while (c == ' ' || c == '\t' || c == '\n') {
            c = getchar();
        }
        if (c == '.') {
            break;
        }
        ungetc(c, stdin);

        if (scanf("%d", &cmd) != 1) {
            break;
        }

        if (cmd == 0) {
            continue;
        }else 
        {

        if (cmd > 0) {
            for (int i = 0; i < cmd; i++) {
                push(&head, &tail, &counter);
            }
        } else {
            int steps = -cmd;
            for (int i = 0; i < steps; i++) {
                if (head == NULL) {
                    break;
                }
                pop(&head, &tail);
            }
        }
        print_queue(head);
        }
    }

    while (head) pop(&head, &tail);

    return 0;
}