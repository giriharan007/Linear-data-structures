#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

int size;
struct node *top;

struct node* createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode; 
}

void push(int data){
    struct node *newNode = createNode(data);
    if(top == NULL){
        top = newNode;
        size++;
    }
    else{
        newNode->next = top;
        top->prev = newNode;
        top = newNode;
        size++;
    }
}

void pop(){
    if(top == NULL){
        printf("Stack is empty\n");
    }
    else{
        struct node *temp = top;
        top = top->next;
        top->prev = NULL;
        free(temp);
        size--;
    }
}

void print(){
    if(top == NULL){
        printf("Stack is empty\n");
    }
    else{
        struct node *temp = top;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    print();
    printf("Size: %d\n", size);

    pop();
    print();
    printf("Size: %d\n", size);
    return 0;
}