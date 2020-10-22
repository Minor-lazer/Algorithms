#include <math.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
int largest(int a[])  
{     
    int larger=a[0], i;   
    for(i=1;i<10;i++)  
    {  
        if(a[i]>larger)  
        larger = a[i];  
    }  
    return larger;  
}  
void radix_sort(int a[])  
{  
    int bucket[10][10], bucket_count[10];  
    int i, j, k, remainder, NOP=0, divisor=1, larger, pass;  
    larger = largest(a);  
    while(larger>0)  
    {  
        NOP++;  
        larger/=10;  
    }  
    for(pass=0;pass<NOP;pass++) // Initialize the buckets  
    {  
        for(i=0;i<10;i++)  
        bucket_count[i]=0;  
        for(i=0;i<10;i++)  
        {  
            // sort the numbers according to the digit at passth place            
            remainder = (a[i]/divisor)%10;  
            bucket[remainder][bucket_count[remainder]] = a[i];  
            bucket_count[remainder] += 1;  
        }  
        // collect the numbers after PASS pass  
        i=0;  
        for(k=0;k<10;k++)  
        {  
            for(j=0;j<bucket_count[k];j++)  
            {  
                a[i] = bucket[k][j];  
                i++;  
            }  
        }  
        divisor *= 10;  
      
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
			
		radix_sort(arr); 
		
		
		end = clock();
	    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     	printf("time = %.5f \n", cpu_time_used);
	}
	

	return 0; 
} 

