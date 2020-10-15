#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
         int data;
         struct node *next;
}node;
void push(node **top)
{
         node *temp;
         temp=(node *)malloc(sizeof(node));
         printf("\nEnter a value: ");
         scanf("%d",&(temp->data));
         temp->next=*top;
          *top=temp;
           //printf("%d %d %d %d\n",temp->data,temp->next,(*top)->data,(*top)->next);
          //free(temp);
}
node * pop(node *top){
         struct node *p;
         printf("\nThe popped element is %d",top->data);
         top=top->next;
         return top;
}
void  display(node *top)
{
         node *temp;
         temp=top;
         while(temp!=NULL)
         {
                  printf("%d ",temp->data);
                  temp=temp->next;
         }
         free(temp);
}

void main()
{
         struct node *top=NULL;
         int choice;
         do
         {
         printf("\n\n\t\t**Linked List**\n");
         printf("\n1.Insert Element\n2.Pop Element\n3.Display\n4.exit");
         printf("\nEnter your Choice :");
         scanf("%d",&choice);
         switch(choice)
         {
         case 1:
                  push(&top);
                  break;
         case 2:
                  if(top==NULL)
                           printf("\n\tStack is Empty\n");
                  else
                           top=pop(&top);
                   break;
         case 3:
                  if(top==NULL)
                           printf("\n\tStack is Empty\n");
                  else
                           display(top);
                    break;
         case 4:
                  exit(0);
         default:
                  printf("\n\tInvalid Choice.\n");
         }
         }
         while(1);
}



#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node* next;
}link;
void insert(link **temp,int data,int pos)
{
    int i=1;link *t1=*temp;
    link *t=(link *)malloc(sizeof(link));
    if(pos==1)
    {
        t->info=data;
        t->next=*temp;
        *temp=t;
    }
    else
    {
        while(i<pos)
        {
            t1=t1->next;
            i++;
        }
        t->info=data;
        t->next=t1->next;
        t1->next=t;
    }

}
void display(link *temp)
{
    while(temp!=NULL)
    {
        printf("%d\t",temp->info);
        temp=temp->next;
    }
}
void del(link **temp,int pos)
{
    link *t=*temp;
    if(pos==1)
    {
        *temp=(*temp)->next;
        free(t);
    }
    else
    {
    }
}
int main()
{
    int n,i;
    link *A,*temp;
    A=NULL;
    printf("Enter the number of user: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        if(i==0)
        {
            temp=(link*)malloc(sizeof(link));
            scanf("%d",&(temp->info));
            A=temp;
            A->next=NULL;
        }
        else
        {
            temp->next=(link *)malloc(sizeof(link)) ;
            temp=temp->next;
            scanf("%d",&(temp->info));
            if(i==n-1)
            {
                temp->next=NULL;
            }
        }
    }
    temp=A;
    display(A);
    printf("\nEnter element you wants to input and its position:");
    scanf("%d%d",&n,&i);
    insert(&A,n,i);
    display(A);
    printf("\n Enter position you want to delete :");
    scanf("%d%d",n,i);
    del(n,i);
}
