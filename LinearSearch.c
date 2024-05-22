#include<stdio.h>
#define SIZE 5
void accept_array(int a[], int size);
void display_array(const int *a, int size);
int linear_search(int a[], int size, int key);
int main(void)
{
    int A[SIZE], ans, find;

    printf("\n Enter the elements of array :");
    accept_array(A, SIZE);

    printf("\n Elements of array : ");
    display_array(A, SIZE);

    printf("\n Enter the element to find in array :");
    scanf("%d", &find);

    ans= linear_search(A, SIZE, find);
    if(ans==-1)
    {
        printf("\n %d not found in give array", find);
    }
    else
    {
        printf("\n %d found in array at index %d", find, ans);
    }
    
    return 0;

}
void accept_array(int a[], int size)
{
    int index;
    for(index=0; index<size; ++index)
    {
        printf("\n Enter a[%d]", index);
        scanf("%d", &a[index]);
    }
    return;
}
void display_array(const int *a, int size)
{
    int index;
    for(index=0; index<size;++index)
    {
        printf("\n a[%d] \t %d \t [%u]", index, a[index], &a[index]);
    }
    return;
}
int linear_search(int a[], int size, int key)
{
    int index;
    for(index=0;index<size;index++)
    {
        if(key==a[index])
        return index;
    }
    return -1;
}
