#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *temp, *newnode;

void create_linkedlist()
{
    int ch;
    while (1 > 0)
    {
        printf("\nEnter \t 1 to create linked list \n\t 0 to exit : \n");
        scanf("%d", &ch);

        if (ch == 1)
        {

            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter the data : \n");
            scanf("%d", &newnode->data);
            newnode->prev = NULL;
            newnode->next = NULL;

            if (head == NULL)
            {
                head = temp = newnode;
            }
            else
            {

                temp->next = newnode;
                newnode->prev = temp;
                temp = newnode;
            }
        }

        else if (ch == 0)
        {
            printf("You are exited !\n");
            break;
        }
        else
        {
            printf("Invalid choice! \n");
        }
    }
}

void display_linkedlist()
{
    printf("Your Doubly linked list is : \n");
    temp = head;

    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    create_linkedlist();
    display_linkedlist();
    return 0;
}