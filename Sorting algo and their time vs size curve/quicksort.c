#include <math.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>


int partition(int a[], int beg, int end)  
{  
      
    int left, right, temp, loc, flag;     
    loc = left = beg;  
    right = end;  
    flag = 0;  
    while(flag != 1)  
    {  
        while((a[loc] <= a[right]) && (loc!=right))  
        right--;  
        if(loc==right)  
        flag =1;  
        else if(a[loc]>a[right])  
        {  
            temp = a[loc];  
            a[loc] = a[right];  
            a[right] = temp;  
            loc = right;  
        }  
        if(flag!=1)  
        {  
            while((a[loc] >= a[left]) && (loc!=left))  
            left++;  
            if(loc==left)  
            flag =1;  
            else if(a[loc] <a[left])  
            {  
                temp = a[loc];  
                a[loc] = a[left];  
                a[left] = temp;  
                loc = left;  
            }  
        }  
    }  
    return loc;  
}  
void quickSort(int a[], int beg, int end)  
{  
      
    int loc;  
    if(beg<end)  
    {  
        loc = partition(a, beg, end);  
        quickSort(a, beg, loc-1);  
        quickSort(a, loc+1, end);  
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
			
		quickSort(arr,0,n-1); 
		
		
		end = clock();
	    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     	printf("time = %.5f \n", cpu_time_used);
	}
	

	return 0; 
} 

