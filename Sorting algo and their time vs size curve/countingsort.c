#include <math.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int k=0; 	// for storing the maximum element of input array

/* Method to sort the array */
void counting_sort(int A[],int B[],int n)    
{
	int i,count[k+1],t;
	for(i=0;i<=k;i++)
	{
		//Initialize array count
		count[i] = 0;
	}
	for(i=0;i<n;i++)
	{
	    // count the occurrence of elements u of A 
	    // & increment count[u] where u=A[i]
		t = A[i];
		count[t]++;			
	}
	for(i=1;i<=k;i++)
	{
	    // Updating elements of count array 
		count[i] = count[i]+count[i-1];            
	}
	for(i=0;i<n;i++)
	{
		// Add elements of array A to array B
		t = A[i];
		B[count[t]] = t;          
	    // Decrement the count value by 1
		count[t]=count[t]-1;		
	}
}

int main() 
{ 
	
    int n,t;
    printf("Enter No of testcases : ");
    scanf("%d", &t);
    while(t--){
    	clock_t start, end;
	    double cpu_time_used;
	     
	    start = clock();
	    
	    printf("n = ");
	    scanf("%d", &n);
    	int i,arr[n],b[n];
		for(i=0;i<n;i++){
			arr[i] = rand()%100;
			if(arr[i]>k)
				k = arr[i];
		}
		counting_sort(arr,b,n); 
		
		
		end = clock();
	    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     	printf("time = %.5f \n", cpu_time_used);
	}
	

	return 0; 
} 

