#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *first = NULL;
struct node* create_node(int x)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->info = x;
    temp->next = NULL;
    return temp;
}
void insert_first()
{
    int x;
    struct node *temp;
    printf("Enter value: ");
    scanf("%d", &x);
    temp = create_node(x);
    if (first==NULL)
        first = temp;
    else{
         temp->next = first;
        first=temp;
    }   
    printf("Node inserted at beginning.\n");
}
void insert_last()
{
    int x;
    struct node *temp, *p;

    printf("Enter value: ");
    scanf("%d", &x);

    temp = create_node(x);

    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        p = first;

        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = temp;
    }

    printf("Node inserted at end.\n");
}
void insert_position()
{
    int x, pos, i;
    struct node *temp, *p;

    printf("Enter value: ");
    scanf("%d", &x);

    printf("Enter position: ");
    scanf("%d", &pos);

    temp = create_node(x);

    if (first==NULL)
    {
        first = temp;

        printf("Node inserted.\n");
        return;
    }
    p = first;
while(i!=pos-1)
    {
    p=p->next;
    }
    temp->next = p->next;
    p-> next=temp;
}
void delete_first()
{
    struct node *temp;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    temp = first;
    first = first->next;

    free(temp);

    printf("First node deleted.\n");
}
void delete_last()
{
    struct node *p, *temp;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (first->next == NULL)
    {
        free(first);
        first = NULL;
    }
    else
    {
        p = first;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        temp = p->next;
        p->next = NULL;
        free(temp);
    }
    printf("Last node deleted.\n");
}
void delete_position()
{
    int pos, i;
    struct node *p, *temp;
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
    for (i = 1; i < pos - 1 && p->next != NULL; i++)
    {
        p = p->next;
    }
    if (p->next == NULL)
    {
        printf("Invalid position.\n");
        return;
    }
    temp = p->next;
    p->next = temp->next;
    free(temp);
    printf("Node deleted.\n");
}
void display()
{
    struct node *p;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    p = first;
    printf("Singly Linked List: ");
    while (p != NULL)
    {
        printf("%d -> ", p->info);
        p = p->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice;
    do
    {
        printf("1. Insert First\n 2. Insert Last\n 3. Insert Position\n 4. Delete First\n 5. Delete Last\n 6. Delete Position\n 7. Display\n 8. Exit\n" );
        
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
