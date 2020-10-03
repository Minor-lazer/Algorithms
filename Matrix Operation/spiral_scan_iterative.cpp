#include<cstdio>
using namespace std;

void sScan(int arr[50][50], int m, int n)
{
	int srow=0, scol=0, erow=m-1, ecol=n-1;
	while(srow<=erow && scol<=ecol)
	{
		for(int i=scol; i<=ecol; i++)
		printf("%d ", arr[srow][i]);
		srow++;
		for(int i=srow; i<=erow; i++)
		printf("%d ", arr[i][ecol]);
		ecol--;
		if(erow>srow)
		{
			for(int i=ecol; i>=scol; i--)
			printf("%d ", arr[erow][i]);
			erow--;
		}
		if(ecol>scol)
		{
			for(int i=erow; i>=srow; i--)
			printf("%d ", arr[i][scol]);
			scol++;
		}
	}
}

int main()
{
	int r,c,arr[50][50];
	printf("Enter the number of rows: ");
	scanf("%d", &r);
	printf("Enter the number of columns: ");
	scanf("%d", &c);
	printf("Enter matrix elements: ");
	for(int i=0; i<r; i++)
	for(int j=0; j<c; j++)
	scanf("%d", &arr[i][j]);
	printf("\n------Scanning Spirally------\n");
	sScan(arr, r, c);
	return 0;
}
