#include<stdio.h>
int main()
{
    int arr[100]={11,22,33,44,55};
    int n=5 , i,pos,value, key;
    //traversal
    printf("Array element are : \n");
    for(i=0 ; i<n;i++)
    {
        printf("%d", arr[i]);
    }
    //insertion
    printf("\n enter position to insert :", n+1);
    scanf("%d",&value);
    for(i=n ; i>=pos ; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos-1]=value;
    n++;
    prinf("Array after insertion : \n");
    for(i=0; i<n; i++)
    {
        printf("%d", arr[i]);
    }
    //Deletion
    printf("\n enter position to delet :",n);
    scanf("%d",&pos);
    for(i=pos-1; i<n-1; i++)
    {
        a[i]=a[i+1];
    }
    n--;
    printf("Array after deletion : \n");
    for(i=0;i<n;i++)
    {
        printf("%d",&a[i]);
    }
    //search
    printf("\n enter element to search :\n");
    scanf("%d",&key);
    for (i=0;i<n;i++);
    {
        if(arr[i]==key){
            printf("element found at position %d \n ", i+1);
            break;
        }
    }
    if(i==n){
        printf("element not found \n");
    }
    return 0;
}