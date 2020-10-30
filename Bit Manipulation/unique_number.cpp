//Program to find unique number in an array
//Program to find unique number.
#include <iostream>
using namespace std;
//Function to find unique number.
int unique(int *arr,int n)
{
	int count[64]={0};

	for(int k=0;k<n;k++)
	{
		int i=0;
		int num=arr[k];
		while(num>0)
		{
			count[i]+=(num&1);
			i++;
			num=num>>1;
		}
	}
	int power=1;
	int result=0;
	for(int j=0;j<64;j++)
	{
		count[j] %=3;
		result+=count[j]*power;
		power=power<<1;
	}
	return result;
}

int main()
{
	int arr[50];
	int n;
	cout<<"Enter length of the array: ";
	cin>>n;

	cout<<"Enter array elements: "<<endl;
	for(int c=0;c<n;c++)
	{
		cin>>arr[c];
	}
	cout<<unique(arr,n)<<" is the unique number in array.";

	return 0;
}
