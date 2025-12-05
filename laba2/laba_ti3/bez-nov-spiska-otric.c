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

// Функция для сортировки отрицательных элементов по возрастанию модулей
void sortNegativeByAbsoluteValue(Node** negativeList) {
    if (*negativeList == NULL || (*negativeList)->next == NULL) return;

    int swapped;
    do {
        swapped = 0;
        Node* current = *negativeList;

        while (current != NULL && current->next != NULL) {
            if (fabs(current->data) > fabs(current->next->data)) {
                double temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

// Функция для перемещения отрицательных элементов в середину списка
Node* moveNegativesToMiddle(Node* head) {
    if (head == NULL) return NULL;

    Node* positiveList = NULL;
    Node* negativeList = NULL;
    Node* positiveTail = NULL;
    Node* negativeTail = NULL;

    Node* current = head;
    int positiveCount = 0;
    int negativeCount = 0;

    // Разделяем список на положительные/нулевые и отрицательные элементы
    while (current != NULL) {
        Node* nextNode = current->next;
        current->next = NULL;

        if (current->data < 0) {
            if (negativeList == NULL) {
                negativeList = current;
                negativeTail = current;
            }
            else {
                negativeTail->next = current;
                negativeTail = current;
            }
            negativeCount++;
        }
        else {
            if (positiveList == NULL) {
                positiveList = current;
                positiveTail = current;
            }
            else {
                positiveTail->next = current;
                positiveTail = current;
            }
            positiveCount++;
        }
        current = nextNode;
    }

    // Сортируем отрицательные элементы по возрастанию модулей
    sortNegativeByAbsoluteValue(&negativeList);

    // Объединяем списки: положительные -> отрицательные
    Node* newHead = NULL;

    if (positiveList != NULL) {
        newHead = positiveList;
        if (negativeList != NULL) {
            positiveTail->next = negativeList;
        }
    }
    else {
        newHead = negativeList;
    }

    printf("\nСтатистика:\n");
    printf("  Положительных/нулевых элементов: %d\n", positiveCount);
    printf("  Отрицательных элементов: %d\n", negativeCount);

    return newHead;
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

    Node* head = NULL;

    head = createListFromInput();

    if (head == NULL) {
        printf("Список пуст!\n");
        return 0;
    }

    printList(head, "Исходный список");

    printf("\n=== Выполняется преобразование списка ===\n");
    printf("1. Отрицательные элементы перемещаются в середину списка\n");
    printf("2. Отрицательные элементы сортируются по возрастанию модулей\n");

    head = moveNegativesToMiddle(head);

    printList(head, "Список после преобразования");

    printf("\nПреобразование выполнено:\n");
    printf("1. Все отрицательные элементы перемещены в середину списка\n");
    printf("2. Отрицательные элементы упорядочены по возрастанию их абсолютных значений\n");

    freeList(head);

    return 0;
}
