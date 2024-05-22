#include<stdio.h>
#define SIZE 5
void accept_array(int a[], int size);
void display_array(const int * a, int size);
void sap(int *n1, int *n2);
void selection_sort(int a[], int size);
int main(void)
{
    int A[SIZE];

    printf("\n Enter the elements of array:");
    accept_array(A, SIZE);

    printf("\n Elements of array:");
    display_array(A, SIZE);    

    printf("\n Elements in ascending order after selection sort:");
    selection_sort(A, SIZE);
    display_array(A, SIZE);

    return 0;
}
void accept_array(int a[], int size)
{
    int index;
    for(index=0;index<size;++index)
    {
        printf("\n Enter a[%d] = ", index);
        scanf("%d", &a[index]);
    }
    return;
}
void display_array(const int *a,int size)
{
    int index;
    for(index=0;index<size;++index)
    {
        printf("\n a[%d] = %d \t [%u]", index, a[index], &a[index]);
    }
    return;
}
void selection_sort(int a[], int size)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            printf("\n a[%d] = %d \t [%u] \t a[%d] = %d [%u]", i, a[i], &a[i], j, a[j], &a[j]);
            if(a[i]>a[j])
            {
                sap(&a[i], &a[j]);
            }
        }
        if(i<(size-1))
        printf("\n iterarion = %d", i+1);
    }
    return;
}
void sap(int *n1, int *n2)
{
    int temp;
    temp=*n1;
    *n1=*n2;
    *n2=temp;
    return;
}