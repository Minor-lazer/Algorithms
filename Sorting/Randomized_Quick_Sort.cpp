#include<bits/stdc++.h>
using namespace std;


//Partition algorithm that swaps A[i] with A[pindex]
//such that A[i]<=PIVOT ELEMENT
int partition(int A[],int s,int e){
	int pivot=A[e];
	int pindx=s;
	for(int i=s;i<=e-1;i++){
		if(A[i]<=pivot){
			swap(A[i],A[pindx]);
			pindx++;
		}
	}
	swap(A[pindx],A[e]);
	return pindx;
}

//It choses random element from array and swaps it with last element
int randompartition(int A[],int s,int e){
	int pindx = (rand() %(e - s + 1)) + s;
	swap(A[pindx],A[e]);
	return partition(A,s,e);
}

//QuickSort function that recursively calls itself
void quickSort(int *A,int s,int e){
	if(s>=e)
		return;
	int pindx=randompartition(A,s,e);
	quickSort(A,s,pindx-1);
	quickSort(A,pindx+1,e);
}

int main(){
	int A[]={5,2,7,11,-3,4,66,12};
	int n=sizeof(A)/sizeof(A[0]);
	//Array after sorting: -3,2,4,5,7,11,66
	quickSort(A,0,n-1);
  
  //Printing Array
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
}
