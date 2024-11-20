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

struct node* linklist_delete_at_first(struct node *head){
    struct node *ptr = (struct node*)malloc(sizeof(struct node*));
    ptr = head;
    head = head->next;
    free(ptr);
    return head;

}

// case 2

struct node* linklist_delete_at_index(struct node *head, int index){
    struct node *p = (struct node*)malloc(sizeof(struct node*));
    struct node *q = (struct node*)malloc(sizeof(struct node*));
    p = head;
    q = head->next;
    int i = 0;
while(i<index-1)
{
    p = p->next;
    q = q->next;
    i++;
}
    p->next = q->next;
    free(q);
    return head;
}

// case 3

struct node* linklist_delete_at_node(struct node *head){
    struct node *p = (struct node*)malloc(sizeof(struct node*));
    struct node *q = (struct node*)malloc(sizeof(struct node*));
    p = head;
    q = head->next;
while(q->next!=NULL)
{
    p = p->next;
    q = q->next;
    
}
    p->next = q->next;
    free(q);
    return head;
}

// case 4

struct node* linklist_delete_at_given_node(struct node *head, int data){
    struct node *p = (struct node*)malloc(sizeof(struct node*));
    struct node *q = (struct node*)malloc(sizeof(struct node*));
    p = head;
    q = head->next;
while(q->data!=data && q->next!=NULL)
{
    p = p->next;
    q = q->next;
    
}
    p->next = q->next;
    free(q);
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
    printf("\nLinklist before deletion\n\n");
    linked_list_traversal(head);
    // head = linklist_delete_at_first(head);
    // linked_list_traversal(head);
    printf("\nLinklist after deletion\n\n");
    // head = linklist_delete_at_index(head,2);
    // linked_list_traversal(head);
    // head = linklist_delete_at_node(head);
    // linked_list_traversal(head);
    head = linklist_delete_at_given_node(head,9);
    linked_list_traversal(head);
    return 0;
}