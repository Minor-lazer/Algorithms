#include <math.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) 
{ 
	int i, key, j; 
	for (i = 1; i < n; i++) { 
		key = arr[i]; 
		j = i - 1; 

		while (j >= 0 && arr[j] > key) { 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 
		arr[j + 1] = key; 
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
			
		insertionSort(arr, n); 
		
		
		end = clock();
	    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     	printf("time = %.5f \n", cpu_time_used);
	}
	

	return 0; 
} 

