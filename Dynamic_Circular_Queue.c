//dyanamic circular queue//
#include<stdio.h>
int MAX;
int *A;
int front;
int rear;
void init_queue();
void print_queue();
void add_element(int value);
void delete_queue();
void free_queue();
int peek();
int menu_choice();
int is_Full();
int is_Empty();
int main(void)
{
    int choice, data;
    inint_queue();
    print_queue();
    do
    {
        choice = menu_choice();
        switch(choice)
        {
            default : printf("\n Invalid Input");
                      continue;

            case1: //add element//
                   {
                       if(!is_Fwull())
                       {
                            printf("\n Enter data to add:");
                            scanf("%d", &data);
                            add_element(data);
                       }
                       else
                       {
                           printf("\n Queue is full");
                       }
                   }    
                   break;

            case2 : //delete element//
                    {
                        if(!is_Empty())
                        {
                            data=peek();
                            delete_queue();
                            printf("\n Deleted value : %d", data);
                        }
                        else
                        {
                            printf("\n Queue is Empty");
                        }
                    }
                    break;

            case3: //peek//
                    {
                        if(!is_Empty())
                        {
                            data=peek();
                            printf("\n Peek value : %d", data);
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

            case0 : //Exit//
                    free_queue();
                    break;
                        
        }
        print_queue();
        printf("\n Enter 1 to continue and 0 to exit : ");
        scanf("%d", &choice);
    }while(choice!=0);
    free_queue();
    return 0;
}
void init_queue()
{
    rear=-1;
    front=-1;
    printf("\n Ho many elemnets do you want into Queue:");
    scanf("%d", &MAX);
    A = (int*)malloc(MAX*sizeof(int));
    if(A==NULL)
    {
        printf("\n Unable to allocate memory : ");
        exit(0);
    }
    else
    {
        int index;
        for(index=0;index<MAX;index++)
        {
            A[index]=-1;
        }
    }
    return;
}