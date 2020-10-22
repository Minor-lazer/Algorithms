#include<iostream>
#include<bits/stdc++.h>
int getMax(int a[], int n);
int getSum(int a[], int n);
int requirednumberofPainters(int a[], int n, int mid);       /*......................... BEST APPROACH..........................*/
                                                            /*.......................... BINARY SEARCH .........................*/
int minimumtime(int a[], int n, int k);
using namespace std;
int main()
{
    // taking input for the length of the array//
    int n;
    cin>>n;
    // Initialization of Array
    int a[n];
    // Taking input of elements of array//
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];  
    }
    // Time taken to paint one Unit of Block
    int time;
    //Scanning the time
    cin>>time;
    //sort(a,a+n); // no need
    int k;
    // K is the number of painters.
    // Taking input of number of painters
    cin>>k;
    // Calling function minimumtime which will calculate the minimum time required to paint the blocks
    int ans = minimumtime(a,n,k);
    // Printing the Minimum number of time  in which the painting will be complated
    cout<<"The minimum time "<<ans * time;

    return 0;
}
int minimumtime(int a[], int n, int k)
{
   int lo = getMax(a,n);// Finding the length of block which will take the max time
    int hi = getSum(a,n);// Finding the time that is taken by a single painter to paint all the blocks
    while(lo<hi)
    {
        int mid = (lo + hi) / 2;// Finding mid element 
        int numberofPainters = requirednumberofPainters(a,n,mid);
        // logic of binary search //
        // hope you know it//
        if(numberofPainters  <=  k) 
        {
            hi = mid - 1;
        }
        else
        {
            lo = lo + 1;
        }
    }
    // returning the lowest element i.e. the element which indicates the lowest time taken
    return lo;

}
int getMax(int a[],int n)
{
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        if(max < a[i])
        {
            max = a[i];
        }
    }   
    return max;//Returns the largest element of the array
}
int getSum(int a[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    return sum;// Returns the sum of all elements of the array
}
int requirednumberofPainters(int a[], int n,int mid)
{
    int total = 0;//initializing it to take count of the total time taken for painting
     int numberofPainters = 1;// if total overflows the minimum time then we have to add a new painter
    for(int i = 0; i < n; i++)
    {
       
         total = total + a[i];
        if(total>mid)
        {
            total = a[i];
            numberofPainters++;
        }
    }
    return numberofPainters;
}
