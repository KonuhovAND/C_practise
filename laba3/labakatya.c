#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) return NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (newNode == NULL) return;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
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

struct Node *inputList(const char *listName) {
    struct Node *head = NULL;
    int num;
    char ch;
    
    printf("%s (1 1 1. / 1 2 2 3. - valid Nodes): \n", listName);
    while (scanf("%d%c", &num, &ch) == 2) {
        append(&head, num);
        if (ch == '.') break;
    }
    
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    printf("Список: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct Node *head) {
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

void splitAndSwap(struct Node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    
    int length = getLength(*head);
    int firstHalfLength = (length + 1) / 2;
    
    struct Node *firstHalfEnd = *head;
    for (int i = 1; i < firstHalfLength; i++) {
        firstHalfEnd = firstHalfEnd->next;
    }
    
    struct Node *secondHalfStart = firstHalfEnd->next;
    if (secondHalfStart == NULL) {
        return;
    }
    
    firstHalfEnd->next = NULL;
    
    struct Node *secondHalfEnd = secondHalfStart;
    while (secondHalfEnd->next != NULL) {
        secondHalfEnd = secondHalfEnd->next;
    }
    
    secondHalfEnd->next = *head;
    *head = secondHalfStart;
}

int main() {
    setlocale(0, "");
    
    struct Node* list = inputList("Введите список");
    
    printf("Исходный ");
    printList(list);
    
    splitAndSwap(&list);
    
    printf("После замены ");
    printList(list);
    
    freeList(list);
    
    return 0;
}
