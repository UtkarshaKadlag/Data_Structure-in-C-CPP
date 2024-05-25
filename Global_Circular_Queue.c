// global circular queue   --->  FIFO   / LILO
#include<stdio.h>
#define MAX 5
int arr[ MAX ] ;
int rear; // to add element from rear end
int front; // to delete element from front end
void init_queue();
void add_queue(int value); //insert/ push/ joined add element into queue from rear end
void delete_queue(); // delete /pop / remove remove  element from front end
int peek(); // check top most element from queue and display
int is_empty(); // check queue is empty or not
int is_full(); // check queue is full or not
int menu_choice();
void print_queue(); // print contents of queue
int main()
{
    int choice, data;
    init_queue();
    print_queue();
    do 
    {
          choice= menu_choice();
          switch (choice)
          {
                default: printf("\n invalide choice :: ");
                        continue; // go to next itration
                case 1: //  add element into queue
                        {
                            if( !is_full())  // if(!1 )   false   if (!0)  true
                            {
                                printf("\n Enter data =");
                                scanf("%d", &data);
                                add_queue(data);
                            }
                            else
                            {
                                printf("\n queue is full \n");
                            }
                        }
                        break;
                case 2: // remove element from queue
                        {
                            if( !is_empty())
                            {
                                data= peek();
                                delete_queue();
                                printf("\n deleted value =%d \n ", data);

                            }
                            else 
                                printf("\n queue is empty \n");
                        }
                        break;
                case 3: // peek element  from queue
                        {
                            if( !is_empty())
                            {
                                data= peek();
                                printf("\n peek value =%d \n ", data);
                            }
                            else 
                                printf("\n queue is empty \n");
                        }
                        break;
                case 4: // print queue
                        print_queue();
                       break;  
                case 0: // exit
                        return 0; //    exit(0);  stdlib.h
          }   // end of switch case 
          print_queue();
          printf("\n Enter 1 to continue or 0 to exit :: ");
          scanf("%d", &choice);
    }while(choice!=0);
    return 0;
}
void init_queue()
{
    rear=-1; // init postion of rear element as -1
    front=-1; // init postion of front element as -1
    int index;
    for( index=0; index<MAX; index++)
    {
        arr[index]=-1; // init every elements of queue as -1
    }
    return;
}
void add_queue(int value) // add element into queue from rear end
{
    if( rear== MAX-1)
        rear=0;  // rear=-1; rear++;
    else
        rear++; //rear= rear+1;  increment value of rear by 1
    arr[rear]=value;  // add new element at rear position at array
    return;
}
void delete_queue()// remove front most element from queue
{
    if( front== MAX-1)
        front=0; // front=-1; front+;
    else 
        front++; //front= front+1;  increment value of front by 1        
    arr[front]=-1;  // over right front most eleement with -1
    if( front== rear)
    {
        front= rear=-1;  // reset rear and front to -1 when u add 5 elements in queue and remove 5 elements from queue
    }
    
    return;
}
int peek() // check front most element from queue and display
{
    int value;
    if(front== MAX-1)
        value= arr[0]; // if front == 4   then pick oth element from queue
    else 
        value= arr[front+1];  // take front most element from  queue and assign to value
    return value;    // return value
}
int is_empty() // check queue is empty or not
{
   if( rear==-1 && front==-1)
        return 1; // queue is empty
    else    
        return 0; // queue is not empty
}
int  is_full() // check queue is full or not
{
    if( (front==-1 && rear== MAX-1) || (rear==front && rear!=-1))
        return 1;//  queue is full
    else 
        return 0;//  queue is not full
}
void print_queue() // print contents of queue
{
    int index;
    printf("\n=========================================\n");
    printf("\n data \t");
    for( index=0; index<=MAX-1 ; index++)
    {
        printf("[ %3d ]", arr[index]);
    }
    printf("\n index \t");
    for( index=0; index<=MAX-1 ; index++)
    {
        printf("[ %3d ]",  index);
    }
    
    printf("\t rear=%d  front=%d", rear, front);
    printf("\n=========================================\n");
    return;
}

int menu_choice()
{
    int choice;
    printf("\n 1. Add Queue \n 2. Delete Queue \n 3. Peek \n 4. Print Queue\n 0 Exit :: ");
    printf("\n Enter Your choice::");
    scanf("%d", &choice);
    return choice;
}