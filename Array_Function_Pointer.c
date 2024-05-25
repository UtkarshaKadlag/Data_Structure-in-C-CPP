//array_function_pointer//
#include<stdio.h>
int sum(int n1, int n2);
int minus(int n1, int n2);
int multiply(int n1, int n2);
int main(void)
{
    int no1=10, no2=20, ans=0, index;
    int(*funptr[3])(int num1, int num2);

    funptr[0]=sum;
    funptr[1]=minus;
    funptr[2]=multiply;

    for(index=0;index<3;index++)
    {
        printf("\n %d", funptr[index](10,20));
    }
    return 0;
}
int sum(int n1, int n2)
{
    printf("\n sum function is called");
    return n1+n2;
}
int minus(int n1, int n2)
{
    printf("\n Minus function is called");
    return n1-n2;
}
int multiply(int n1, int n2)
{
    printf("\n Multiply function is called");
    return n1*n2;
}