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
void separ(list *hd)
{
    list *i=hd,*j;int t;
    while(i!=NULL)
    {
        j=i->next;
        if((i->info)%2!=0)
        {
        while(j!=NULL){
        if(((j->info)%2==0)&&((i->info)%2!=0))
        {
            t=i->info;
            i->info=j->info;
            j->info=t;
            break;
        }j=j->next;}}i=i->next;
    }
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
    separ(head);
    display(head);
}

