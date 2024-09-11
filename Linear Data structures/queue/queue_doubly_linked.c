#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;

};

int size=0;
struct node *front=NULL;
struct node *rear=NULL;

struct node *create_node(int data){
    struct node *new_node =(struct node *)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    new_node->prev=NULL;
    return new_node;
}

void enqueue(int data){
    struct node *new_node=create_node(data);
    if(front==NULL){
        front=new_node;
        rear=new_node;
        size++;
        return;
    }

    else{
        rear->next=new_node;
        new_node->prev=rear;
        rear=new_node;
    }
    size++;
}

int dequeue(){
    if(front==NULL){
        printf("queue is empty");
    }

    else{
        struct node *temp=front;
        int data=front->data;
        front=front->next;
        free(temp);
        size--;
        return data;
    }
}

void print(){
    struct node *temp=front;
    if(front==NULL){
        printf("queue is empty\n");
        return;
    }
    else{
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }

    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    print();
    printf("size before deleting is %d\n",size);
    int deleted_data=dequeue();
    printf("deleted data is %d\n",deleted_data);
    print();
    printf("size after deleting is %d\n",size);
    return 0;

}