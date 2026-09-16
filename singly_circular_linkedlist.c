#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *first = NULL;

/* Create a new node */
struct node* create_node(int x)
{
    struct node *temp;

    temp = (struct node*)malloc(sizeof(struct node));

    temp->info = x;
    temp->next = NULL;

    return temp;
}

/* Insert at beginning */
void insert_first()
{
    int x;
    struct node *temp, *last;

    printf("Enter value: ");
    scanf("%d", &x);

    temp = create_node(x);

    if (first == NULL)
    {
        first = temp;
        temp->next = first;
    }
    else
    {
        last = first;

        while (last->next != first)
        {
            last = last->next;
        }

        temp->next = first;
        last->next = temp;
        first = temp;
    }

    printf("Node inserted at beginning.\n");
}

/* Insert at end */
void insert_last()
{
    int x;
    struct node *temp, *last;

    printf("Enter value: ");
    scanf("%d", &x);

    temp = create_node(x);

    if (first == NULL)
    {
        first = temp;
        temp->next = first;
    }
    else
    {
        last = first;

        while (last->next != first)
        {
            last = last->next;
        }

        last->next = temp;
        temp->next = first;
    }

    printf("Node inserted at end.\n");
}

/* Insert at position */
void insert_position()
{
    int x, pos, i;
    struct node *temp, *p;

    printf("Enter value: ");
    scanf("%d", &x);

    printf("Enter position: ");
    scanf("%d", &pos);

    temp = create_node(x);

    if (first == NULL)
    {
        if (pos == 1)
        {
            first = temp;
            temp->next = first;
            printf("Node inserted.\n");
        }
        else
        {
            printf("Invalid position.\n");
            free(temp);
        }
        return;
    }

    if (pos == 1)
    {
        struct node *last = first;

        while (last->next != first)
        {
            last = last->next;
        }

        temp->next = first;
        last->next = temp;
        first = temp;

        printf("Node inserted.\n");
        return;
    }

    p = first;

    for (i = 1; i < pos - 1 && p->next != first; i++)
    {
        p = p->next;
    }

    if (i != pos - 1)
    {
        printf("Invalid position.\n");
        free(temp);
        return;
    }

    temp->next = p->next;
    p->next = temp;

    printf("Node inserted.\n");
}

/* Delete from beginning */
void delete_first()
{
    struct node *temp, *last;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (first->next == first)
    {
        temp = first;
        first = NULL;
        free(temp);
    }
    else
    {
        temp = first;
        last = first;

        while (last->next != first)
        {
            last = last->next;
        }

        first = first->next;
        last->next = first;

        free(temp);
    }

    printf("First node deleted.\n");
}

/* Delete from end */
void delete_last()
{
    struct node *temp, *p;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (first->next == first)
    {
        free(first);
        first = NULL;
    }
    else
    {
        p = first;

        while (p->next->next != first)
        {
            p = p->next;
        }

        temp = p->next;
        p->next = first;

        free(temp);
    }

    printf("Last node deleted.\n");
}

/* Delete from position */
void delete_position()
{
    int pos, i;
    struct node *p, *temp, *last;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        delete_first();
        return;
    }

    p = first;

    for (i = 1; i < pos - 1 && p->next != first; i++)
    {
        p = p->next;
    }

    if (p->next == first)
    {
        printf("Invalid position.\n");
        return;
    }

    temp = p->next;
    p->next = temp->next;

    free(temp);

    printf("Node deleted.\n");
}

/* Display */
void display()
{
    struct node *p;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    p = first;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", p->info);
        p = p->next;
    }
    while (p != first);

    printf("(back to first)\n");
}

/* Main function */
int main()
{
    int choice;

    do
    {
        printf("\n----- SINGLY CIRCULAR LINKED LIST -----\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert Position\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert_first();
                break;

            case 2:
                insert_last();
                break;

            case 3:
                insert_position();
                break;

            case 4:
                delete_first();
                break;

            case 5:
                delete_last();
                break;

            case 6:
                delete_position();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 8);

    return 0;
}
