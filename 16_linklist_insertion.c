#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void linked_list_traversal(struct node * ptr){
    while(ptr!=NULL){
    printf("Element : %d\n", ptr->data);
    ptr = ptr->next;
    }
}

// case 1

struct node * insertatfirst(struct node *head , int data){
    struct node *ptr = (struct node* )malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// case 2

struct node * insertatindex(struct node *head , int data, int index){

    struct node *ptr = (struct node* )malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;

    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// case 3

struct node * insertatend(struct node *head , int data){

    struct node *ptr = (struct node* )malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    int i = 0;

    while(p->next!=NULL)
    {
        p = p->next;
        i++;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// case 4

struct node * insertafternode(struct node *head , struct node *prevnode , int data){
    struct node *ptr = (struct node* )malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prevnode->next;
    prevnode->next = ptr;
   
    return head;
}
int main (){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    // Allocate memory for node in the linklist in heap
    head   = (struct node *)malloc(sizeof(struct node *));
    second = (struct node *)malloc(sizeof(struct node *));
    third  = (struct node *)malloc(sizeof(struct node *));
    fourth = (struct node *)malloc(sizeof(struct node *));

    // link first and second node
    head->data = 7;
    head->next = second;

    // link first and second node

    second->data = 8;
    second->next = third;

    // link first and second node

    third->data = 9;
    third->next = fourth;

    // link first and second node

    fourth->data = 10;
    fourth->next = NULL;
    printf("\nLinklist before insertion\n\n");
    linked_list_traversal(head);
    // head = insertatfirst(head,45);
    // head = insertatend(head,45);
    printf("\nLinklist after insertion\n\n");
    // linked_list_traversal(head);
    head = insertafternode(head,second,45);
    linked_list_traversal(head);
    return 0;
}