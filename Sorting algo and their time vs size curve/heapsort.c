#include <math.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
int temp;  
  
void heapify(int arr[], int size, int i)  
{  
int largest = i;    
int left = 2*i + 1;    
int right = 2*i + 2;    
  
if (left < size && arr[left] >arr[largest])  
largest = left;  
  
if (right < size && arr[right] > arr[largest])  
largest = right;  
  
if (largest != i)  
{  
temp = arr[i];  
    arr[i]= arr[largest];   
    arr[largest] = temp;  
heapify(arr, size, largest);  
}  
}  
  
void heapSort(int arr[], int size)  
{  
int i;  
for (i = size / 2 - 1; i >= 0; i--)  
heapify(arr, size, i);  
for (i=size-1; i>=0; i--)  
{  
temp = arr[0];  
    arr[0]= arr[i];   
    arr[i] = temp;  
heapify(arr, i, 0);  
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
    	int i,arr[n];
		for(i=0;i<n;i++)
			arr[i] = rand()%100;
			
		heapSort(arr,n); 
		
		
		end = clock();
	    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     	printf("time = %.5f \n", cpu_time_used);
	}
	

	return 0; 
} 

