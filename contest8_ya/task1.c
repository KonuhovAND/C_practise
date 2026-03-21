#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

int vvod_Node(struct Node **FirstElemNode) {
    struct Node *LastElemNode, *TempNode;
    int value;
    char ch;
    *FirstElemNode = LastElemNode = TempNode = NULL;
    while (1) {
        int res = scanf("%d", &value);
        if (res != 1) {
            if (scanf(" %c", &ch) != 1 || ch == '.') break;
            break;
        }
        TempNode = (struct Node*)malloc(sizeof(struct Node));
        if (TempNode == NULL) return 0;
        TempNode->value = value;
        if (*FirstElemNode == NULL) {
            *FirstElemNode = TempNode;
            TempNode->next = *FirstElemNode;
            LastElemNode = TempNode;
        } else {
            LastElemNode->next = TempNode;
            TempNode->next = *FirstElemNode;
            LastElemNode = TempNode;
        }
    }
    return (*FirstElemNode != NULL);
}

void print_Node(struct Node* FirstElemNode) {
    if (FirstElemNode == NULL) return;
    struct Node *TempNode = FirstElemNode;
    do {
        printf("%d", TempNode->value);
        TempNode = TempNode->next;
        if (TempNode != FirstElemNode) printf(" ");
    } while (TempNode != FirstElemNode);
    printf("\n");
}

void free_young_thug(struct Node **FirstElemNode) {
    if (*FirstElemNode == NULL) return;
    struct Node *Current = *FirstElemNode;
    struct Node *Last = *FirstElemNode;
    while (Last->next != *FirstElemNode) {
        Last = Last->next;
    }
    Last->next = NULL;
    while (Current != NULL) {
        struct Node *NextNode = Current->next;
        free(Current);
        Current = NextNode;
    }
    *FirstElemNode = NULL;
}

int main() {
    struct Node *FirstElemNode = NULL;
    struct Node *OriginalFirst = NULL;
    struct Node *SearchNode = NULL;
    struct Node *TargetNode = NULL;
    int k;

    if (!vvod_Node(&FirstElemNode)) {
        printf("0\n");
        return 0;
    }
    
    OriginalFirst = FirstElemNode;

    if (scanf("%d", &k) != 1) {
        print_Node(FirstElemNode);
        free_young_thug(&OriginalFirst);
        return 0;
    }

    print_Node(FirstElemNode);

    SearchNode = FirstElemNode;
    do {
        if (SearchNode->value == k) {
            TargetNode = SearchNode;
            break;
        }
        SearchNode = SearchNode->next;
    } while (SearchNode != FirstElemNode);

    if (TargetNode != NULL) {
        print_Node(TargetNode);
    } else {
        print_Node(FirstElemNode);
    }

    free_young_thug(&OriginalFirst);
    return 0;
}