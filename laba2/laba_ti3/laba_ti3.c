#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

typedef struct Node {
    double data;
    struct Node* next;
} Node;

Node* createNode(double value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Ошибка: не удалось выделить память\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addToEnd(Node** head, double value) {
    Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void insertSortedByAbsolute(Node** head, double value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Вставка в порядке возрастания модуля
    if (fabs(value) < fabs((*head)->data)) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    Node* current = *head;
    while (current->next != NULL && fabs(value) >= fabs(current->next->data)) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}

Node* createListFromInput() {
    Node* head = NULL;
    double value;
    char buffer[100];

    printf("Введите последовательность чисел (введите 'q' для завершения):\n");
    printf("(вводите построчно, разделяя числа пробелами или переносами)\n");

    while (1) {
        if (scanf("%99s", buffer) != 1) {
            printf("Ошибка ввода данных!\n");
            return head;
        }

        if (buffer[0] == 'q' || buffer[0] == 'Q') {
            break;
        }

        if (sscanf(buffer, "%lf", &value) == 1) {
            addToEnd(&head, value);
        }
        else {
            printf("Некорректный ввод, попробуйте снова или введите 'q' для завершения\n");
        }
    }

    return head;
}

void printList(Node* head, const char* title) {
    printf("\n%s: ", title);
    if (head == NULL) {
        printf("(пусто)\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("%.2lf ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Функция для создания нового списка с отрицательными элементами
// в порядке возрастания их абсолютных значений
Node* createNegativeSortedList(Node* head) {
    Node* negativeList = NULL;
    Node* current = head;
    
    // Собираем все отрицательные элементы
    while (current != NULL) {
        if (current->data < 0) {
            insertSortedByAbsolute(&negativeList, current->data);
        }
        current = current->next;
    }
    
    return negativeList;
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    Node* originalList = NULL;
    Node* negativeList = NULL;

    originalList = createListFromInput();

    if (originalList == NULL) {
        printf("Список пуст!\n");
        return 0;
    }

    printList(originalList, "Исходный список");

    printf("\n=== Создание нового списка с отрицательными элементами ===\n");
    printf("Отрицательные элементы сортируются по возрастанию модулей\n");
    
    negativeList = createNegativeSortedList(originalList);

    printList(negativeList, "Новый список (только отрицательные)");

    printf("\nСоздан новый список, содержащий только отрицательные элементы\n");
    printf("из исходного списка, упорядоченные по возрастанию их\n");
    printf("абсолютных значений (модулей).\n");
    
    printf("\nКоличество элементов:\n");
    printf("  Исходный список: ");
    int count = 0;
    Node* temp = originalList;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("%d\n", count);
    
    printf("  Новый список (отрицательные): ");
    count = 0;
    temp = negativeList;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("%d\n", count);

    freeList(originalList);
    freeList(negativeList);

    return 0;
}
