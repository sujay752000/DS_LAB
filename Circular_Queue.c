#include <stdio.h>

int size, front = -1, rear = -1;

void enqueue(int queue[size])
{
    if ((rear + 1) % size == front) // rear == size - 1
    {
        printf("\nOverflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        int data;

        front++;
        rear++;

        printf("\nEnter data : ");
        scanf("%d", &data);
        queue[rear] = data;
    }
    else
    {
        int data;

        printf("\nEnter data : ");
        scanf("%d", &data);

        rear = (rear + 1) % size; // rear++;
        queue[rear] = data;
    }

    display(queue);
}

void dequeue(int queue[size])
{
    if (front == -1 && rear == -1)
    {
        printf("\nUnderflow\n");
    }
    else if (front == rear)
    {
        printf("\nDequeued Element is : %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("\nDequeued Element is : %d\n", queue[front]);
        front = (front + 1) % size;
    }

    display(queue);
}

void display(int queue[size])
{
    int i = front;

    if(front == -1 && rear == -1)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("\nQueue is : \n");
        for (int i = front; i != rear;)
        {
            printf("%d \t", queue[i]);
            i = (i + 1) % size;
        }
        printf("%d", queue[rear]);
    }
}

int main()
{
    printf("Enter the size of array : \n");
    scanf("%d", &size);

    int queue[size];

    int ch;
    while (5 > 0)
    {
        printf("\nEnter any operations to perform \n\t 1. Enqueue \n\t 2. Dequeue \n\t 3. display \n\t 4. exit \n");
        scanf("%d", &ch);
        if (ch == 1)
        {
            enqueue(queue);
        }
        else if (ch == 2)
        {
            dequeue(queue);
        }
        else if (ch == 3)
        {
            display(queue);
        }
        else if (ch == 4)
        {
            printf("You are exited \n");
            break;
        }
        else
        {
            printf("Invalid Operation");
        }
    }
    return 0;
}