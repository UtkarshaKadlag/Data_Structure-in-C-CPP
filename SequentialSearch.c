// accept and print array
#include<stdio.h>
#define SIZE 6
void accept_array(int a[], int size);
void display_array(const int *a, int size);
int* seq_search(const int a[], int size, int key);
/// strchr in string.h
int main(void)
{
    int arr[SIZE], find, *ptr=NULL;
    printf("\n enter array elements :\n");
    accept_array(arr,SIZE);

    printf("\n  array elements :\n");
    display_array(arr,SIZE);
    
    printf("\n Enter element to find 2_1=");
    scanf("%d", &find);
    
    ptr=seq_search(arr,SIZE, find);
    if( ptr == NULL)
        printf("\n %d is not found in array ", find);
    else 
        printf("\n %d is found in array at %d position ", find, ptr-arr);
        /// (address1- address)/scale factor


    return 0;
}

void accept_array(int a[], int size)
{
    int index;
    for(index=0; index<size; ++index)
    {
        printf("\n a[%d]", index);
        scanf("%d", &a[index]);
    }
    return;
}
void display_array(const int *a, int size)
{
    int index;
    for(index=0; index<size; index++)
    {
        printf("\n a[%d]  %5d   [%u] ", index, a[index], &a[index]);
    }
    return;
} // a[index] == *(a+index)
  // index[a] == *(index+a)
int* seq_search(const int a[], int size, int key)
{
    int index;
    for( index=0; index<size; index++)
    {
        if( key== a[index])
            return &a[index];  // if key found retun address

    }
    return NULL; // if key not found return NULL

}