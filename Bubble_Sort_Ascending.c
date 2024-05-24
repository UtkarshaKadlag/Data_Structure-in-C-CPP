//print and accept array//
//sort the elements of array in ascending order by BUBBLE SORT//
#include<stdio.h>
#define SIZE 6
void accept_array(int a[],int size);
void display_array(const int *a, int size);
void bubble_sort_asc(int a[], int size);
int main(void)
{
    int A[SIZE];

    printf("\n Elements of Array : ");
    accept_array(A, SIZE);

    printf("\n Elements of Array :");
    display_array(A, SIZE);

    bubble_sort_asc(A, SIZE);
    printf("\n Sorted elements in ascending order by BUBBLE SORT :");
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
void display_array(const int *a, int size)
{
    int index;
    for(index=0;index<size;++index)
    {
        printf("\n a[%d] = %d [%u]", index, a[index], &a[index]);
    }
    return;
}
void bubble_sort(int a[], int size)
{
    int i, j, temp, flag=0;
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size-i-1;j++)
        {
            printf("\n a[%d] = \t %d \t [%u] \t a[%d] = \t %d \t [%u]");
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }
        if(i<(size-1))
            printf("\n Iteration =%d", i+1);
        if(flag==0)
            break;
    }
    return;
}
//