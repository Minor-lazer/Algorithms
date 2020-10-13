
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}node;
void insert(node**l,int num)
{
    node *p=(node*)malloc(sizeof(node));
    if(p!=NULL){
    p->info=num;
    p->next=NULL;
    if((*l)==NULL)*l=p;
    else{(*l)->next=p;*l=p;}
    }
    else
        printf("MEMORY ERROR!");
}
void display(node *f)
{
    while(f!=NULL)
    {
        printf("%d ",f->info);
        f=f->next;
    }
}
void small(node *f)
{
    int min=f->info;
    while(f->next!=NULL)
    {
        if(min<f->info)
            min=f->info;
        f=f->next;
    }
    printf("\nSmallest element : %d",min);
}
int main()
{
    node *first=NULL,*last=NULL;
    char ch;int n;
    do
    {
        printf("Enter the element you want to enter :");
        scanf("%d",&n);
        insert(&last,n);
        if(first==NULL)first=last;
        printf("Do you want to continue..Y/N");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    display(first);
    small(first);
}
