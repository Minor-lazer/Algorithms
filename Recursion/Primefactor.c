#include<stdio.h>
void PFactors( int num);
void IPFactors( int n);
 
int main( )
{
        int num;
        printf("Enter a number : ");
        scanf("%d", &num);
        printf("\nUsing Recursion :: \n");
        PFactors(num);
        printf("\n");
        printf("\nUsing Iteration :: \n");
        IPFactors(num);
        printf("\n");
 
        return 0;
 
}
 
void PFactors( int num)
{
        int i = 2;
        if( num == 1 )
                return;
        while( num%i != 0 )
                i++;
        printf("%d ", i);
        PFactors(num/i);
}
void IPFactors( int num)
{
        int i;
        for( i = 2; num!=1; i++)
                while( num%i == 0 )
                {
                        printf("%d ", i);
                        num = num/i;
                }
}