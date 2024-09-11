#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

int size;
struct node *head = NULL;
struct node * tail = NULL;

struct node *create_node(int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> next = NULL;
    new_node -> prev = NULL;
    return new_node;   
}

void print_forward(){
    if(head == NULL){
        printf("The list is empty! \n");
    }

    else{
        struct node* temp = head;
        while(temp!= NULL){
            printf("%d\n",temp->data);
            temp = temp->next;
        }
    }
}


void print_backward(){
    if(tail== NULL){
        printf("The list is empty! \n");
    }

    else{
        struct node* temp = tail;
        while(temp != NULL){
            printf("%d\n", temp->data);
            temp = temp->prev;
        }
    }
} 

void insert_at_beg(int data){
    struct node* new_node = create_node(data);
    if(head == NULL){
        head = new_node;
        tail = new_node;
        size++;
        return;
    }

    else{
        new_node->next = head;
        head -> prev = new_node;
        head = new_node;
        size++;
    }
}

void insert_at_end(int data){
    struct node* new_node = create_node(data);
    if(tail == NULL){
        head = new_node;
        tail = new_node;
        size++;
        return;
    }

    else{
        new_node ->prev = tail;
        tail-> next = new_node;
        tail = new_node;
        size++;
        return;
    }
    
}

void insert_at_pos(int data, int pos){
    int i=0;
    if(head == NULL){
        printf("The list is empty! to insert at position \n");
        return;
    }

    if(pos == 1){
        insert_at_beg(data);
        size++;
        return;
    }
    if(pos == size){
        struct node* new_ndoe = create_node(data);
        new_ndoe->next = tail;
        new_ndoe->prev= tail->prev;
        tail->prev->next = new_ndoe;
        tail->prev = new_ndoe;
        size++;
    }

    if(pos<= size/2){
        struct node* n_node = create_node(data);
        struct node* temp = head;
        
        for(i=1; i<pos-1; i++){
            temp = temp->next;
        }
        
        n_node->prev = temp;
        n_node ->next = temp->next;
        temp->next->prev = n_node;
        temp -> next = n_node;  
        size++;
    }

    else if(pos > size/2){
        struct node* n_node = create_node(data);
        struct node* temp = tail;
        
        for(i=size; i> pos-1; i--){
            temp = temp->prev;
        }
        n_node->prev = temp;
        n_node ->next = temp->next;
        temp->next->prev = n_node;
        temp -> next = n_node;
        size++;

    }
}

void del_beg(){
    struct node*ptr=head;
    head=head->next;
    head->prev=NULL;
    free(ptr);
    size--;
}

void del_end(){
    tail=tail->prev;
    tail->next=NULL;
    size--;
}

void del_pos(int pos){
    int i;
    struct node *ptr=head;
    if(pos<1 || pos>size || head==NULL){
        printf("we cannot delete");
    }

    else{
        for(i=1;i<pos-1;i++){
            ptr=ptr->next;
        }
        ptr->next=ptr->next->next;
        ptr->next->prev=ptr;
        size--;
    }
}

int main(){
    
    insert_at_beg(3);
    insert_at_beg(2);
     insert_at_beg(1);
    insert_at_end(5);
    insert_at_end(6);
    insert_at_end(7);
    insert_at_end(8);
    insert_at_end(9);
    insert_at_end(10);
    insert_at_pos(4,4); 
    //del_beg();
    del_pos(9);
    //del_end();
    print_forward();
    printf("===================%d\n", size);
    print_backward();
    

    return 0;
}