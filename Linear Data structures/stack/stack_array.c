#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int size;
int top = -1;
int stack[MAX];

void push(int data){
    if(top == MAX-1){
        printf("Stack is full\n");
    }
    else{
        top++;
        stack[top] = data;
        size++;
    }
}


void pop(){
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        top--;
        size--;
    }
}


void print(){
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        int i;
        for(i = top; i >= 0; i--){
            printf("%d ", stack[i]);
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