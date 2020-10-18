#include <math.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
  
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
     
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
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
			
		bubbleSort(arr, n); 
		
		
		end = clock();
	    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     	printf("time = %.5f \n", cpu_time_used);
	}
	

	return 0; 
} 

