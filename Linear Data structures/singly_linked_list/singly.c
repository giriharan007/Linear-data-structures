#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int size=0;
struct node *head=NULL;
struct node *tail=NULL;

struct node *create_node(int data){
    struct node *new_node=(struct node*) malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

void insert_beg(int data){
    struct node* new_node = create_node(data);
    if(head==NULL){
        head=new_node;
        tail=new_node;
        size++;
        return;
    }

    else{
        new_node->next=head;
        head=new_node;
        size++;
    }

}

void insert_end(int data){
    struct node *new_node=create_node(data);

    if(head==NULL){
        head=new_node;
        tail=new_node;
        size++;
        return;
    }

    else{
          tail->next=new_node;
          tail=new_node;
          size++;
          return;
    }
    
}

void insert_pos(int data,int pos){
    int i;
    struct node *new_node=create_node(data);

    if(pos>size){
        printf("we cannot insert at position");
    }

    if(head==NULL){
        printf("we cannot insert at position");
    }

    if(pos==1){
        insert_beg(data);
        size++;
        return;
        }
    
   else{
    struct node *ptr=head;
    for(i=1;i<pos-1;i++){
        ptr=ptr->next;
        }

    new_node->next=ptr->next;
    ptr->next=new_node;
    size++;

   }
   }

   
void delete_beg() {
    if (head == NULL) {
        printf("List is empty, cannot delete\n");
        return;
    }

    struct node *ptr = head;
    head = head->next;
    free(ptr);
    size--;

    if (head == NULL) { 
        tail = NULL;
    }
}

void delete_end(){
    if(head==NULL){
        printf("there is no list");
    }

    else{
        struct node *ptr=head;
        while(ptr->next->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=NULL;
        tail=ptr;
        size--;
    }
}

void delete_pos(int pos){
    int i;
    if(pos<1 || pos>size  || head==NULL){
        printf("we cannot delate");

    }
    struct node *ptr=head;
    for(i=1;i<pos-1;i++){
      ptr=ptr->next; 
    }
    ptr->next=ptr->next->next;
    size--;
   
}

   

void print(){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    insert_beg(3);
    insert_beg(2);
    insert_beg(1);
    insert_end(5);
    insert_end(6);
    insert_end(7);
    insert_pos(4,4);
    /*delete_beg();
    delete_end();
    delete_pos(4);*/


    print();
    return 0;
}