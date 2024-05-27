// global (SLL) Singly Linear LinkedList
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data; 
    struct node *next;
}node_t;
node_t *head; // struct node *head=NULL;
node_t* create_node(int value);
void add_first(int value);
void display_list();
void add_last(int value);
void add_at_position(int position, int value);
int count_nodes();
void trav_rev(node_t *trav);
int main()
{
    display_list();
    add_last(10);  
    display_list();  // 10--->
    add_last(20);
    display_list(); // 10--->20--->
    add_last(30);
    display_list();// 10--->20--->30--->
    add_last(40);
    display_list();// 10--->20--->30--->40--->
     add_last(50);
    display_list();// 10--->20--->30--->40--->50----->

    add_at_position(1, 5);
    display_list();// 5--->10--->20--->30--->40--->50----->

    add_at_position(7, 99);
    display_list();// 5--->10--->20--->30--->40--->50----->99--->

      add_at_position(3, 25);
    display_list();// 5--->10--->20--->25 ----> 30--->40--->50----->99--->
    


      add_at_position(7, 75);
    display_list();// 5--->10--->20--->25--->30--->40--->50----->99--->

    printf("\n=========================================\n");
    trav_rev(head);

    return 0;
}
void trav_rev(node_t *trav)
{
    if( trav==NULL)
        return;
    else 
        trav_rev(trav->next);
    printf("<---%d", trav->data);
    return;
}
void add_at_position(int position, int value)
{
    node_t *newnode=NULL, *trav=NULL;
    int i;
    if(position==1)
    {
        add_first(value);  // call function of add 1st
    }
    else if( position== (count_nodes()+1))
    {
        add_last(value); // call function of add last
    }
    else 
    {
         newnode= create_node(value);
         trav= head;  // store address of 1st node(head) into trav pointer
         for( i=1; i<position-1; i++)
         {
            trav= trav->next; // go to next node of liked list
         }
         newnode->next= trav->next; // store the address of trav->next into new nodes next pointer
         trav->next=newnode;  // store the address of new node into trav->next pointer
    }
    return;

}
int count_nodes()
{
    node_t * trav=NULL;
    int counter=0;
    if( head== NULL)
        printf("\n list is empty \n");
    else 
    {
        trav=head;  // store the address of 1st node( head) into trav pointer
        while(trav!=NULL)
        {
            counter++;//counter=counter+1;
            trav= trav->next;  // gotpo next node in linked linked
        }
        printf("\n");
    }
    return counter;
}
void add_last(int value)
{
    node_t * newnode =NULL;
    newnode= create_node(value);
    if( head == NULL) // if list is empty
    {   
        head= newnode;  // store address of new node into head pointer
    }
    else
    {
        node_t *trav=head;  // store the address of 1st node(head) into trav pointer
        while (trav->next!=NULL) // trav till last node linked list
        {
            trav=trav->next; // go to next node of linked list
        }
        trav->next= newnode; //store the address of new node into trav->next pointer

    }
    return;
}
void display_list()
{
    node_t * trav=NULL;
    if( head== NULL)
        printf("\n list is empty \n");
    else 
    {
        trav=head;  // store the address of 1st node( head) into trav pointer
        while(trav!=NULL)
        {
            printf("%5d--->", trav->data);  // print data of current node
            trav= trav->next;  // gotpo next node in linked linked
        }
        printf("\n");
    }
    return;
}
node_t* create_node(int value)
{
    node_t *new_node=NULL;
    new_node= (node_t*)malloc(1*sizeof(node_t));
    if( new_node==NULL)
    {
        printf("\n unable to allocate memory");
        exit(0);
    }
    else 
    {
        new_node->data= value;
        new_node->next=NULL;
    }
    return new_node;
}
void add_first(int value)
{
    node_t *newnode=NULL;
    newnode=create_node(value);
    if( head== NULL)  // if linked list is empty
    {
        head= newnode;  // store address of new node into head pointer
    }
    else 
    {
        newnode->next= head; // store the address of 1st node into next of newnode
        head= newnode; // store the address of new node into head pointer
    }
    return;
}
