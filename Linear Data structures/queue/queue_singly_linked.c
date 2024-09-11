#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int size=0;
struct node *front=NULL;
struct node *rear=NULL;

struct node *create_node(int data){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

void enqueue(int data){
   struct node *new_node= create_node(data);
   if(front==NULL){
    front=new_node;
    rear=new_node;
    size++;
    return;
   }

   else{
     rear->next=new_node;
     rear=new_node;
     size++;
     return;
   }
}

int dequeue(){
    int data;
    if(front==NULL){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        int data = front->data;
        struct node *temp = front;
        front = front->next;

        if(front == NULL){
            rear = NULL;
    }
    
    free(temp); 
    return data;

}

}

void print(){
    struct node *temp=front;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    int value=dequeue();
    print();    
    printf("dequeued value is : %d\n",value);

    return 0;
}