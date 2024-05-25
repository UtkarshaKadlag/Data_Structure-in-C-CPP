//global lineaer queue//
#include<stdio.h>
#define MAX 5
int front;
int rear;
int A[MAX];
void add_queue(int value);
void delete_queue();
int peek();
void print_queue();
void init_queue();
int is_Empty();
int is_Full();
int menu_choice();
int main(void)
{
    int data, choice;
    init_queue();
    print_queue();
    do
    {
        choice= menu_choice();
        switch(choice)
        {
            default : printf("\n Invalid input");
                      continue;

            case 1: // add element to queue//
                    {
                        if(!is_Full())
                        {
                            printf("\n Enter the value to add to queue:");
                            scanf("%d", &data);
                            add_queue(data);
                        }
                        else
                        {
                            printf("\n Queue is full");
                        }
                    }
                    break;

            case 2: //delete element from queue//
                    {
                        if(!is_Empty())
                        {
                            data = peek();
                            delete_queue();
                            printf("\n Deleted value: %d", data);
                        }
                        else
                        {
                            printf("\n Queue is Empty");
                        }
                    }
                    break;

            case 3: //peek//
                    {
                        if(!is_Empty())
                        {
                            data=peek();
                            printf("\n Peek Value : %d", data);
                        }
                        else
                        {
                            printf("\n Queue is Empty");
                        }
                    }
                    break;

            case 4: //print queue//
                    {
                        print_queue();
                    }
                    break;

            case 0: //exit//
                    return 0;
        }
        print_queue();
        printf("\n Enter 1 to continue and 0 to exit:");
        scanf("%d", &choice);
    }while (choice!=0);
    
    return 0;
    
}
void init_queue()
{
    int index;
    front=-1;
    rear=-1;
    for(index=0;index<MAX;index++)
    {
        A[index]=-1;
    }
    return;
}
void add_queue(int value)
{
    rear++;
    A[rear]= value;
    return;
}
void delete_queue()
{
    front++;
    A[front]=-1;
    return;
}
int peek()
{
    int value;
    value= A[front+1];
    return value;
}
void print_queue()
{
    int index;
    printf("\n=============================================================================================\n");
    printf("\n data \t index \n");
    for(index=0;index<MAX;index++) 
    {
        printf("\n %d \t %d", A[index], index);
    }
    return;
}
int is_Full()
{
    return(rear==MAX-1 ? 1 : 0);
}
int is_Empty()
{
    return(front==rear ? 1 : 0);    
}
int menu_choice()
{
    int choice;
    printf("\n 1.Add Element \n 2.Delete Element \n 3.Peek \n 4.Print Queue \n 0.Exit::");
    printf("\n Enter your choice:");
    scanf("%d", &choice);
    return choice;
}