#include <stdio.h>
#include <stdlib.h>
#define S 20

int tos = -1;
int stk[S];

int empty()
{
    if (tos == -1)
        return 1;
    else
        return 0;
}

int full()
{
    if (tos == S - 1)
        return 1;
    else
        return 0;
}

void push(int x)
{
    if (!full())
    {
        tos++;
        stk[tos] = x;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

int pop()
{
    if (!empty())
    {
        x = stk[tos];
        tos--;
        return x;
    }
    else
    {
        printf("Stack Underflow\n");
        exit(0);
    }
}

int peep()
{
    if (!empty())
    {
        return stk[tos];
    }
    else
    {
        printf("Stack is Empty\n");
        exit(0);
    }
}

void display()
{
    int i;

    if (empty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack Elements are:\n");
        for (i = tos; i >= 0; i--)
        {
            printf("%d\n", stk[i]);
        }
    }
}
int main()
{
    int n, num, x;
    char ch;

    while (1)
    {
        printf("1. Push \n2. pop \n3. peep \n4. display \n ");
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter number: ");
            scanf("%d", &num);
            push(num);
            break;

        case 2:
            x = pop();
            printf("Popped Element = %d\n", x);
            break;

        case 3:
            x = peep();
            printf("Top Element = %d\n", x);
            break;

        case 4:
            display();
            break;

        default:
            printf("Invalid Choice\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);

        if (ch == 'n' || ch == 'N')
            break;
    }
    return 0;
}
