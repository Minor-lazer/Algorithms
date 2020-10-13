#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node* next;
}list;
list* insert(list*hd,int n)
{
   list *temp=(list*)malloc(sizeof(list));
    temp->info=n;
    temp->next=hd;
    return(temp);
}
list* insertatfirst(list *hd,int n)
{
   list *temp=(list*)malloc(sizeof(list));
    temp->info=n;
    temp->next=hd;
    return(temp);
}
void print(list *hd)
{
    while(hd!=NULL)
    {
        printf("%d ",hd->info);
        hd=hd->next;
    }
}
int main()
{
    list *head=NULL;
    int i,n,num;
    char c;
    do
    {
        printf("Enter the element you want to insert: ");
        scanf("%d",&num);
        printf("Press 1.to insert at begin \n2.to at last and \n3.to at mid and \n4.to at any position\n")
        scanf("%d",&n);
        switch(n)
        {
        case 1:

        }
        head=insert(head,num);
        printf("Do you want to continue?Y/N: ");
        fflush(stdin);
        scanf("%c",&c);
    }while(c=='Y'||c=='y');
    print(head);
}
