#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) return NULL;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

struct Node* inputList(const char* listName) {
    struct Node* head = NULL;
    int num;
    char ch;
    
    printf("%s (1 2 3 . для конца): ", listName);
    while (scanf("%d%c", &num, &ch) == 2) {
        if (ch == '.') break;
        append(&head, num);
    }
    
    return head;
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("пусто
");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("
");
}

void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

void mergeLists(struct Node** temp1, struct Node** temp2, struct Node** Result, struct Node** resultTail) {
    while (*temp1 != NULL && *temp2 != NULL) {
        struct Node* node1 = *temp1;
        *temp1 = node1->next;
        node1->next = NULL;
        node1->prev = NULL;
        
        if (*Result == NULL) {
            *Result = *resultTail = node1;
        } else {
            (*resultTail)->next = node1;
            node1->prev = *resultTail;
            *resultTail = node1;
        }
        
        struct Node* node2 = *temp2;
        *temp2 = node2->next;
        node2->next = NULL;
        node2->prev = NULL;
        
        (*resultTail)->next = node2;
        node2->prev = *resultTail;
        *resultTail = node2;
    }
    
    while (*temp1 != NULL) {
        struct Node* node1 = *temp1;
        *temp1 = node1->next;
        node1->next = NULL;
        node1->prev = NULL;
        
        (*resultTail)->next = node1;
        node1->prev = *resultTail;
        *resultTail = node1;
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* result = NULL;
    
    list1 = inputList("Первый список");
    list2 = inputList("Второй список");
    
    printf("
List1: "); printList(list1);
    printf("List2: "); printList(list2);
    
    struct Node* temp1 = list1;
    struct Node* temp2 = list2;
    struct Node* resultTail = NULL;
    
    mergeLists(&temp1, &temp2, &result, &resultTail);
    
    printf("
Результат: "); printList(result);
    
    if (temp1 != NULL) {
        printf("Остаток List1: "); printList(temp1);
    } else if (temp2 != NULL) {
        printf("Остаток List2: "); printList(temp2);
    } else {
        printf("Остатка нет
");
    }
    
    freeList(result);
    freeList(temp1);
    freeList(temp2);
    
    return 0;
}