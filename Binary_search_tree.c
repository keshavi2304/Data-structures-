#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int info;
    struct node *left , *right;
};
struct node *create_node(int x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof (struct node));
    temp-> info = x;
    temp-> left=temp->right=NULL;
    return(temp);
}
void set_left(struct node *t, int x);
void set_right(struct node *t, int x);
void inorder(struct node *p);
void preorder(struct node *p);
void postorder(struct node *p);

int main()
{
    char ch;
    int n;
    struct node *root, *p , *q;
    printf("please enter root : ");
    scanf("%d",&n);
    root=create_node(n);

    while(1)
        {
            printf("do you want to continue ?");
            scanf(" %c",&ch);
              if(ch=='n'||ch=='N')
                break;
            printf("please enter element : ");
            scanf("%d",&n);
            p=q=root;
            while(p!=NULL)
                {
                    q=p;
                    if(p->info<n)
                        p=p->right;
                    else
                        p=p->left;
                }
        
    if(q->info<n)
        set_right(q,n);
    else
        set_left(q,n);
        }
     printf("\n\nInorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);
    return 0;
}


void set_left(struct node *t, int x)
{
     t->left=create_node(x);
}

void set_right(struct node *t, int x)
{
     t->right=create_node(x);
}

void inorder ( struct node *p)
{
    if(p==NULL)
        return;
    inorder(p->left);
    printf("%d ",p->info);
    inorder(p->right);
}
void preorder ( struct node *p)
{
    if(p==NULL)
        return;
    printf("%d ",p->info);
    inorder(p->left);
    inorder(p->right);
}
void postorder ( struct node *p)
{
    if(p==NULL)
        return;
    inorder(p->left);
    inorder(p->right);
     printf("%d ",p->info);
}
 
