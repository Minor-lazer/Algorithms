#include<cstdio>
using namespace std;

void multiply(int r1, int c1, int r2, int c2, int m1[20][20], int m2[20][20], int arr[20][20])
{
	static int i = 0, j = 0, k = 0;
    if (i>=r1)
        return;
    else if(i<r1)
    {
        if (j<c2)
        {
            if(k<c1)
            {
                arr[i][j]+=m1[i][k]*m2[k][j];
                k++;
                multiply(r1, c1, r2, c2, m1, m2, arr);
            }
            k = 0;
            j++;
            multiply(r1, c1, r2, c2, m1, m2, arr);
        }
        j = 0;
        i++;
        multiply(r1, c1, r2, c2, m1, m2, arr);
    }
}

void display(int r, int c, int arr[20][20])
{
	printf("\n------Product of matrices------\n");
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		printf("%d ",arr[i][j]);
		printf("\n");
	}
}
int main()
{
	int r1,r2,c1,c2,m1[20][20],m2[20][20],arr[20][20]={0};
	printf("Enter the number of rows of first matrix: ");
	scanf("%d",&r1);
	printf("Enter the number of columns of first matrix: ");
	scanf("%d",&c1);
	printf("Enter matrix elements: ");
	for(int i=0; i<r1; i++)
	for(int j=0; j<c1; j++)
	scanf("%d",&m1[i][j]);
	printf("Enter the number of rows of second matrix: ");
	scanf("%d",&r2);
	printf("Enter the number of columns of second matrix: ");
	scanf("%d",&c2);
	printf("Enter matrix elements: ");
	for(int i=0; i<r2; i++)
	for(int j=0; j<c2; j++)
	scanf("%d",&m2[i][j]);
	if(c1==r2)
	{
		multiply(r1, c1, r2, c2, m1, m2, arr);
		display(r1, c2, arr);
	}
	else printf("Invalid input");
	return 0;
}
