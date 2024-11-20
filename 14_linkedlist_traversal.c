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
    linked_list_traversal(head);
    return 0;
}