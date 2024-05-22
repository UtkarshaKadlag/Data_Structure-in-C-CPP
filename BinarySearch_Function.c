// binary search function
// 
#include<stdio.h>
#define SIZE 10
//void accept_array(int a[SIZE], int size);
void accept_array(int a[], int size);
void print_array(const int *a, int size);

int binarysearch(const int *a, int key, int size);

int main(void)
{
    int arr[ SIZE ]={10,20,30,40,50,60, 70, 80,90,100}, find, ans=0;


    //printf("\n Enter elements of array =");
    //accept_array(arr, SIZE);

    printf("\n Elements of array =");
    print_array(arr, SIZE);

    printf("\n Enter element of find 2_1 = ");
    scanf("%d", &find);

    ans= binarysearch(arr, find, SIZE);
    if(ans==-1)
        printf("\n %d is not found in array\n", find);
    else
        printf("\n %d is found in array at %d position\n", find, ans);
    
    return 0;
}
int binarysearch(const int *a, int key, int size)
{

    int left=0, mid, right=size-1;
    while( left<=right)
    {         
        mid=(left+right)/2;
        printf("\n a[%d] %d a[%d]%d a[%d]%d  arr[%d]=%d\n ", left, a[left], mid, a[mid], right, a[right], mid, a[mid]);
        if(key==a[mid])
                return mid;
        else if (key>a[mid])
               left=mid+1;          
        else if (key<a[mid])
                 right=mid-1;
        printf("\n a[%d] %d a[%d]%d a[%d]%d  arr[%d]=%d\n ", left, a[left], mid, a[mid], right, a[right], mid, a[mid]);
        printf("\n==========================================================================\n");
    }
    return  -1;
}         
void accept_array(int a[], int size)
{
    int index;
    for( index=0; index<size; index++)
    {
        printf("\n arr[%d] =", index);
        scanf("%d", &a[index]);
    }    
    return;
}
//void print_array(int const  *a, int size)
void print_array(const int *a, int size)
{
    int index;
    for( index=0; index<size; ++index)
    {
        printf("\n arr[%d]  %5d   [%u]", index, a[index], &a[index]);
    }
    return;
}