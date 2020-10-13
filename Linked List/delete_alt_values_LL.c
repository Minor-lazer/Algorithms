#include<stdio.h>
#include<stdlib.h>
int *inp(int n)
{
    int i, *k;
    k=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",(k+i));
    return(k);
}
int del_altt(int *p,int N)
{
    int i,j;
    for(i=0; i<N; i++)
    {
        if(i!=0)
        {
            for(j=i; j<N; j++)
                *(p+j)=*(p+j+1);
            N--;
        }}
    return(N);
}
void disp(int *p, int N)
{
    int i;
    p=(int*)realloc(p,N*sizeof(int));
    for(i=0;i<N;i++)
        printf("%d ",*(p+i));
}
int main()
{
    int N,i,j;
    int *p;
    printf("Enter the limit of array: ");
    scanf("%d",&N);
    p=inp(N);
    N=del_altt(p,N);
    disp(p,N);
}


