#include <stdio.h>

int top = -1;

void push(int arr[], int n)
{

    if(top >= n - 1 )
    {
        printf("Overflow!\n");
    }
    else
    {
        int data;
        printf("Enter the element to be pushed : \n");
        scanf("%d", &data);
        top++;
        arr[top] = data;
    }
}

void pop(int arr[], int n)
{
    if (top < 0)
    {
        printf("Underflow! \n");
    }
    else
    {
        printf("Popped element is %d \n", arr[top]);
        top--;
    }
}

void display(int arr[], int n)
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n, ch;
    printf("Enter the size of array : \n");
    scanf("%d", &n);
    int arr[n];

    while (1 > 0)
    {
        printf("\nEnter your choice : \n\t1. Push\n\t2. Pop\n\t3. Display\n\t4. exit \n");
        scanf("%d", &ch);
        if(ch == 1)
        {
            push(arr, n);
        }
        else if(ch == 2)
        {
            pop(arr, n);
        }
        else if(ch == 3)
        {
            display(arr, n);
        }
        else if(ch == 4)
        {
            printf('You are exited !');
            break;
        }
        else
        {
            printf("Invalid Choice");
        }
    }
    
    return 0;
}