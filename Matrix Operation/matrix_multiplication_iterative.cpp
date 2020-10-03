#include<cstdio>
using namespace std;
void printmat(int arr[20][20], int r, int c)
{
	printf("\n------Product of matrices------\n");
	for(int i=0; i<r; i++)
	{
	for(int j=0; j<c; j++)
	printf("%d ",arr[i][j]);
	printf("\n");
	}
	return;
}

int main()
{
	int r1,r2,c1,c2,m1[20][20],m2[20][20],arr[20][20],sum=0;
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
		for(int i=0; i<r1; i++)
		for(int j=0; j<c2; j++)
		{
			for(int k=0; k<r2; k++)
			sum = sum + m1[i][k]*m2[k][j];
			arr[i][j]=sum;
			sum=0;
		}
		printmat(arr,r1,c2);
	}
	else
	printf("Invalid input");

	return 0;
}
