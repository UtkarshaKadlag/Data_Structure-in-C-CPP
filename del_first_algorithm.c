#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node_t;
node_t *head;
node_t *create_node(int value);
void add_first(int value);
void add_last(int value);
int add_at_position(int position, int value);
void del_first();
void del_last();/*

*/
int del_at_position(int position);
void display_list();
int count_nodes();
int main()
{
    display_list();
    add_first(20);
    display_list();

    add_first(10);
    display_list();
    
    add_last(30);
    display_list();
    
    add_last(40);
    display_list();
    
    add_last(50);
    display_list();
    
    add_last(60);
    display_list();
    
    add_last(80);
    display_list();

    add_last(70);
    display_list();

    del_at_position(6);
    display_list();

    return 0;
}
node_t *create_node(int value)
{
    node_t *newnode = NULL;
    newnode = (node_t*)malloc(1*sizeof(node_t));
    if(newnode==NULL)
    {
        printf("\n List is empty");
        exit(0);
    } 
    else
    {
        newnode->data=value;
        newnode->next=NULL;
    }

    return newnode;
}
void add_first(int value)
{
    node_t *newnode = NULL;
    newnode = create_node(value);
    if(head==NULL)
    {
        head=newnode;
    } 
    else
    {
        newnode->next=head;
        head=newnode;
    }

    return;
}
void add_last(int value)
{
    node_t *newnode = NULL;
    newnode = create_node(value);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        node_t *trav = head;
        while (trav->next!=NULL)
        {
            trav=trav->next;
        }
        trav->next = newnode;
    }

    return;
}
void del_first()
{
    
}
int del_at_position(int position)
{
    int i, value;
    node_t *trav=NULL;
    node_t *temp=NULL;
    trav=head;
    for(i=1; i<position; i++)
    {
        trav=trav->next;
    }
    temp=trav->next;
    trav->next=temp->next;
    temp->data=value;
    free(temp);
    temp=NULL;

    return value;
}
void display_list()
{
    node_t *trav = NULL;
    trav=head;
    if(head==NULL)
     printf("\n list is empty \n");
    else
    {
        trav=head;
        while (trav!=NULL)
        {
            printf("%d--->", trav->data);
            trav=trav->next;
        } 
        printf("\n");
    }
    return;
}