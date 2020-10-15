#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node node;
void insert(node **l,int num)
{
    node *p=(node*)malloc(sizeof(node));
    p->info=num;
    p->next=NULL;
    if(*l==NULL)
        *l=p;
    else{
        (*l)->next=p;
        *l=p;
    }
}
void del_last(node *f,node **l)
{
    node *t=*l,*k=f;
    while(f->next!=*l)
    {
        f=f->next;
    }
    *l=f;
    (*l)->next=k;
    free(t);
}
void display(node *f)
{
    node *t=f;
    do
    {
        printf("%d",t->info);
        t=t->next;
    }while(t!=f);
}
int main()
{
    node *fe,*le;
    fe=NULL;le=NULL;
    char ch;int n;
    do
    {
        printf("Enter element:");
        scanf("%d",&n);
        insert(&le,n);
        if(fe==NULL)fe=le;
        printf("DO YOU WANT TO CONTINUE:");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='Y'||ch=='y');
    le->next=fe;
    del_last(fe,&le);
    display(fe);
}

