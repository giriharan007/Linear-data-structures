#include<stdio.h>
#include<conio.h>

#define MAX 10

int front=-1;
int rear=-1;
int size=0;
int queue[MAX];

void enqueue(int data){
    if(rear==size){
        printf("queue is full\n");
        return;
    }
    else if(rear==-1 && front==-1){
        front=0;
        rear=0;
        queue[rear]=data;
        size++;
        return;
    }
    else{
          rear++;
          queue[rear]=data;
          size++;
          return;
    }
}

int dequeue(){
    if(rear==-1 && front==-1){
        printf("queue is empty\n");
        return;
    }
    else{
        int data=queue[front];
        front++;
        size--;
        return data;
    }
}

void print(){
    int i;
    for(i=front;i<=rear;i++){
        printf("%d\n",queue[i]);
    }
}

int main(){

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    print();
    int value=dequeue();
    printf("dequeued value is : %d\n",value);
    printf("size is :(%d)\n",size);
    return 0;
}