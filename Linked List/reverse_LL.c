#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node* next;
}list;
list *insert(list *hd,int a)
{
    list* temp=(list*)malloc(sizeof(list));
    temp->info=a;
    temp->next=hd;
    return(temp);
}
list *reverse(list *hd)
{
    list *temp,*t;
    temp=hd->next;
    t=temp->next;
    temp->next=hd;
    hd->next=NULL;
    hd=t;
    while(hd->next!=NULL)
    {
        t=hd->next;
        hd->next=temp;
        temp=hd;
        hd=t;
    }
    hd->next=temp;
    return(hd);
}
void display(list *hd)
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
    int no,total,i=1;
    char ch;
    do
    {
        printf("Enter the element you want to insert :");
        scanf("%d",&no);
        head=insert(head,no);
        fflush(stdin);
        printf("Do you want to insert more Y/N");
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    display(head);
    printf("\n");
    head=reverse(head);
    display(head);
}

