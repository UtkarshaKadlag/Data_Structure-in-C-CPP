// global stack
#include<stdio.h>
#define MAX 5
int arr[ MAX ] ;
int top;
void init_stack();
void push(int value); // add element into stack from top end
void pop(); // remove top most element from stack
int peek(); // check top most element from stack and display
int is_empty(); // check stack is empty or not
int is_full(); // check stack is full or not
int menu_choice();
void print_stack(); // print contents of stack
int main()
{
    int choice, data;
    init_stack();
    print_stack();
    do 
    {
          choice= menu_choice();
          switch (choice)
          {
                default: printf("\n invalide choice :: ");
                        continue; // go to next itration
                case 1: // push add element into stack
                        {
                            if( !is_full())  // if(!1 )   false   if (!0)  true
                            {
                                printf("\n Enter data =");
                                scanf("%d", &data);
                                push(data);
                            }
                            else
                            {
                                printf("\n stack is full \n");
                            }
                        }
                        break;
                case 2: // pop add element from stack
                        {
                            if( !is_empty())
                            {
                                data= peek();
                                pop();
                                printf("\n pop value =%d \n ", data);

                            }
                            else 
                                printf("\n stack is empty \n");
                        }
                        break;
                case 3: // peek element  from stack
                        {
                            if( !is_empty())
                            {
                                data= peek();
                                printf("\n peek value =%d \n ", data);
                            }
                            else 
                                printf("\n stack is empty \n");
                        }
                        break;
                case 4: // print stack
                        print_stack();
                       break;  
                case 0: // exit
                        return 0; //    exit(0);  stdlib.h
          }   // end of switch case 
          print_stack();
          printf("\n Enter 1 to continue or 0 to exit :: ");
          scanf("%d", &choice);
    }while(choice!=0);
    return 0;
}
void init_stack()
{
    top=-1; // init postion of top element as -1
    int index;
    for( index=0; index<MAX; index++)
    {
        arr[index]=-1; // init every elements of stack as -1
    }
    return;
}
void push(int value) // add element into stack from top end
{
    top++; //top=top+1;  incrment value of top by 1
    arr[top]=value;  // add new element at top most position at array
    return;
}
void pop()// remove top most element from stack
{
    arr[top]=-1;  // over right top most eleement with -1
    top--; // top-top-1; decrememt value of top by 1
    return;
}
int peek() // check top most element from stack and display
{
    int value;
    value= arr[top];  // take top most element from and assign to value
    return value;    // return value
}
int is_empty() // check stack is empty or not
{
    /*
    if (top== -1)
        return 1;  // stack is empty
    else 
        return 0;  // stack is not empty
    */
    return (top== -1 ? 1  : 0 );
    //                true  false

}
int  is_full() // check stack is full or not
{
    /*if(  top== MAX-1) 
        return 1;   // stack full
    else 
        return 0; // stack is not full
    */
 //   top==MAX-1 ? return 1 : return 0;   // error return is not allowed in condition op
     return(  top==MAX-1 ? 1 :  0);
       //                true   false 
}
void print_stack() // print contents of stack
{
    int index;
    printf("\n=========================================\n");
    printf("\n data   index\n");
    for( index=MAX-1; index>=0 ; index--)
    {
        printf("[ %3d ] [ %d ]\n", arr[index], index);
    }
    printf("\t top=%d", top);
    printf("\n=========================================\n");
    return;
}

int menu_choice()
{
    int choice;
    printf("\n 1. Push \n 2. Pop \n 3. Peek \n 4. Print Stack \n 0 Exit :: ");
    printf("\n Enter Your choice::");
    scanf("%d", &choice);
    return choice;
}