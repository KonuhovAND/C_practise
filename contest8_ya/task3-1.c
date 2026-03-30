#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
};


void print_q(struct node *node){
    if (node == NULL){printf("0\n");return ;}
    struct node *temp = NULL;
    for (temp = node;temp != NULL;temp = temp->next)
    {
        printf("%d",temp->value);
        if (temp->next != NULL) {printf(" ");}

    }
    printf("\n");
}

void push_t(struct node **node,struct node **tail,int *counter){
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL) return;
    temp->value = (*counter)++;
    temp->next = NULL; 
    
    if (*node == NULL){ *node = *tail = temp;}
    else {
        (*tail)->next = temp;
        (*tail) = (*tail)->next;
    }
    
}

void pop_smoke(struct node **node,struct node **tail){
    if (*node == NULL) return;
    struct node *temp = *node;
    *node = (*node)->next;
    if (*node == NULL) *tail = NULL;
    temp->next = NULL;
    free(temp);
}

int main(){
    int counter = 1;
    struct node *node = NULL,*tail = NULL;
    char ch;
    int value,i =0,flag = 0;
    while (1){
        int res = scanf("%d",&value);
        if (res == 1){
        
        if (value == 0 ) continue;
        else if (value > 0)
        {   flag = 0;
            for (i=0;i < value;i++){push_t(&node,&tail,&counter);}
        }
        else if (value <0){
            for (i=0;i < -value;i++){
                if (node == NULL){flag= 1;break;};
                pop_smoke(&node,&tail);
                flag = 0;    
            }
            }
        print_q(node);
        }else {
            if (getchar() == '.'){
                if (node == NULL && counter == 1 && !flag) printf("0\n");
                break;
            }
        }
    }
    while (node != NULL){pop_smoke(&node,&tail);}
    return 0;
}