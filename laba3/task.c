#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 50
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }

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

void printList(struct Node* head) {
    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int getLength(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    setlocale(0, "");
    struct Node* First1 = NULL;
    struct Node* First2 = NULL;
    struct Node* Result = NULL;
    struct Node* Remainder = NULL;

    int n1, n2, value;

    printf("Введите количество элементов первого списка(от 0 до %d): ", MAX_SIZE);
    if (scanf("%d", &n1) != 1 || n1 < 0 || n1 > MAX_SIZE) {
        printf("Error in reading\n");
        return 0;
    }

    if (n1 > 0) {
        printf("Введите элементы первого списка: ");
        for (int i = 0; i < n1; i++) {
            if (scanf("%d", &value) != 1) {
                printf("error in entering data\n");
                return 0;
            }
            append(&First1, value);
        }
    }

    printf("Введите количество элементов второго списка(от 0 до %d): ", MAX_SIZE);
    if (scanf("%d", &n2) != 1 || n2 < 0 || n2 > MAX_SIZE) {
        printf("Error in reading\n");
        return 0;
    }

    if (n2 > 0) {
        printf("Введите элементы второго списка: ");
        for (int i = 0; i < n2; i++) {
            if (scanf("%d", &value) != 1) {
                printf("error in entering data\n");
                return 0;
            }
            append(&First2, value);
        }
    }

    printf("\nПервый список: ");
    printList(First1);
    printf("Второй список: ");
    printList(First2);

    struct Node* temp1 = First1;
    struct Node* temp2 = First2;
    struct Node* resultTail = NULL;

    while (temp1 != NULL && temp2 != NULL) {
        struct Node* newNode1 = createNode(temp1->data);
        if (newNode1 == NULL) {
            printf("error in allocating memory\n");
            return 0;
        }

        if (Result == NULL) {
            Result = newNode1;
            resultTail = newNode1;
        } else {
            resultTail->next = newNode1;
            newNode1->prev = resultTail;
            resultTail = newNode1;
        }

        struct Node* newNode2 = createNode(temp2->data);
        if (newNode2 == NULL) {
            printf("error in allocating memory\n");
            return 0;
        }
        resultTail->next = newNode2;
        newNode2->prev = resultTail;
        resultTail = newNode2;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    struct Node* remainderSource = NULL;
    if (temp1 != NULL) {
        remainderSource = temp1;
        printf("\nПервый список длиннее. Остаток:\n");
    } else if (temp2 != NULL) {
        remainderSource = temp2;
        printf("\nВторой список длиннее. Остаток:\n");
    }

    if (remainderSource != NULL) {
        while (remainderSource != NULL) {
            append(&Remainder, remainderSource->data);
            remainderSource = remainderSource->next;
        }
        printList(Remainder);
        int remainderCount = getLength(Remainder);
        printf("Количество элементов в остатке: %d\n", remainderCount);
    } else {
        printf("\nОба списка одинаковой длины. Остатка нет.\n");
    }

    printf("\nРезультирующий объединенный список:\n");
    printList(Result);

    freeList(First1);
    freeList(First2);
    freeList(Result);
    freeList(Remainder);

    return 0;
}
