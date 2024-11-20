#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void linked_list_traversal(struct node * head){
    struct node *ptr;
    ptr = head;
    do{
    printf("Element : %d\n", ptr->data);
    ptr = ptr->next;
    } while(ptr!=head);
}

// case 1
struct node* linklist_insert_at_first(struct node *head,int data){
    struct node *ptr = (struct node*)malloc(sizeof(struct node*));
    ptr->data = data;
    struct node *p = head->next;
    while(p->next!=head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;

}

// case 2

struct node* linklist_insert_at_index(struct node *head, int index, int data){
    struct node *ptr = (struct node*)malloc(sizeof(struct node*));
    ptr->data = data;
    struct node *p = head->next;
    int i = 1;
while(i!=index-1){
    p = p->next;
    i++;
}
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// case 3

struct node* linklist_insert_after_a_node(struct node *head,struct node *prevnode, int data){
    struct node *ptr = (struct node*)malloc(sizeof(struct node*));
    ptr->data = data;
    ptr->next = prevnode->next;
    prevnode->next = ptr;
    return head;
}

// case 4

struct node* linklist_insert_at_end(struct node *head, int data){
    struct node *ptr = (struct node*)malloc(sizeof(struct node*));
    ptr->data = data;
    struct node *p;
    p = head->next;
    int i = 0;
while(p->next!=head)
{
    p = p->next;
    i++;
    
}
    ptr->next = p->next;
    p->next = ptr;
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
    fourth->next = head;
    printf("\nCircular linklist before insertion\n\n");
    linked_list_traversal(head);
    printf("\nCircular Linklist after insertion\n\n");
    // head = linklist_insert_at_first(head,20);
    // linked_list_traversal(head);
    head = linklist_insert_at_index(head,2,30);
    linked_list_traversal(head);
    // head = linklist_insert_after_a_node(head,second,43);
    // linked_list_traversal(head);
    // head = linklist_insert_at_end(head,9);
    // linked_list_traversal(head);
    return 0;
}