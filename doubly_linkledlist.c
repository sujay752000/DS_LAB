#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *temp, *newnode;

int length_of_linkedlist()
{
    int len = 0;
    temp = head;

    while (temp != NULL)
    {
        len = len + 1;
        temp = temp->next;
    }

    return len;
}

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

void insert_at_beginning()
{
    printf("Insertion at Beginning \n");
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : \n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        newnode->next = head;
        head = temp = newnode;
    }

    display_linkedlist();
}

void insert_at_end()
{
    printf("Insertion at End \n");
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : \n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
    }

    display_linkedlist();
}

void insert_after_position()
{
    printf("Insertion after specified position \n");
    int pos;
    printf("Enter a position to insert a node after : \n");
    scanf("%d", &pos);

    if (pos > length_of_linkedlist())
    {
        printf("Invalid position!\n\t the total length is %d\n", length_of_linkedlist());
    }

    else if (pos < 0)
    {
        printf("Invalid position - position starts from 1\n\tElement cannot be added to 0th posioion\n");
    }

    else if (pos == 0)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data : \n");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = head;
        head = temp = newnode;
    }

    else
    {
        temp = head;
        int i;

        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data : \n");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;

        for (i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp->next->prev = newnode;
    }

    display_linkedlist();
}

void delete_from_beginning()
{
    printf("Deletion at Beginning \n");
    if (head == NULL)
    {
        printf("Nothing to delete ! Linked list is empty. \n");
    }

    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }

    else
    {
        temp = head;

        head = temp->next;
        free(temp);
    }

    display_linkedlist();
}

void delete_from_end()
{
    printf("Deletion at End \n");
    if (length_of_linkedlist() == 0)
    {
        printf("Nothing to delete ! Linked list is empty. \n");
    }
    else if (length_of_linkedlist() == 1)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        free(temp);
    }

    display_linkedlist();

}

void delete_from_specified_position()
{
    printf("Deletion from Specified Position \n");
    if (head == NULL)
    {
        printf("Nothing to delete ! Linked list is empty. \n");
    }
    else
    {
        int pos;
        printf("Enter a position to delete specified node: \n");
        scanf("%d", &pos);

        if (pos > length_of_linkedlist())
        {
            printf("Invalid position!\n\t the total length is %d\n", length_of_linkedlist());
        }

        else
        {
            temp = head;
            struct node *prev_node;
            int i;

            for (i = 1; i < pos; i++)
            {
                prev_node = temp;
                temp = temp->next;
            }

            prev_node->next = temp->next;
            temp->next->prev = prev_node;
            free(temp);
        }
    }

    display_linkedlist();

}

int main()
{
head = NULL;
    while (1 > 0)
    {
        int ch;
        printf("\nEnter your choice : \n\t1.Create linked List\n\t\n\t2.Display Linked List\n\t\n\t3.Insert at Begining\n\t4.Insert at End\n\t5.Insert after a specified position\n\t\n\t6.Delete from Begining\n\t7.Delete from End\n\t8.Delete from specified position\n\t\n\t0.Exit \n\t\n\tYour Choice : ");

        scanf("%d", &ch);

        if (ch == 1)
        {
            create_linkedlist();
        }
        else if (ch == 2)
        {
            display_linkedlist();
        }
        else if (ch == 3)
        {
            insert_at_beginning();
        }
        else if (ch == 4)
        {
            insert_at_end();
        }
        else if (ch == 5)
        {
            insert_after_position();
        }
        else if (ch == 6)
        {
            delete_from_beginning();
        }
        else if (ch == 7)
        {
            delete_from_end();
        }
        else if (ch == 8)
        {
            delete_from_specified_position();
        }
        else if (ch == 0)
        {
            printf("You are Exited ! \n");
            break;
        }
        else
        {
            printf("Invalid choice! \n");
        }
    }
    return 0;
}