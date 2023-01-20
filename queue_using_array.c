#include <stdio.h>

int front = -1, rear = -1;

void enqueue(int arr[], int n)
{
    if (rear >= n - 1)
    {
        printf("Overflow! \n");
    }
    else if (front == -1 && rear == -1)
    {
        int data;
        front++;
        rear++;
        printf("Enter the data to be enqued : \n");
        scanf("%d", &data);
        arr[rear] = data;
    }
    else
    {
        int data;
        rear++;
        printf("Enter the data to be enqued : \n");
        scanf("%d", &data);
        arr[rear] = data;
    }
}

void dequeue(int arr[], int n)
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow \n");
    }
    else if (front == rear)
    {
        printf("Dequed element is %d \n", arr[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Dequed element is %d \n", arr[front]);
        front++;
    }
}

void display(int arr[], int n)
{
    for (int i = front; i < rear + 1; i++)
    {
        printf("%d\t", arr[i]);
    }
    
}

int main()
{
    int n, ch;
    printf("Enter the size of array : \n");
    scanf("%d", &n);
    int arr[n];

    while (1 > 0)
    {
        printf("\nEnter your choice : \n\t1. Enqueue\n\t2. Dequeue\n\t3. Display\n\t4. exit \n");
        scanf("%d", &ch);
        if (ch == 1)
        {
            enqueue(arr, n);
        }
        else if (ch == 2)
        {
            dequeue(arr, n);
        }
        else if (ch == 3)
        {
            display(arr, n);
        }
        else if (ch == 4)
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