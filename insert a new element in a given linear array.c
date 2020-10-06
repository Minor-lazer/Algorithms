// program in c to insert a new element in a given linear array

#include<stdio.h>

int main()
{
 int i,arr[15],size,value,loc;
 
 printf("Enter the size of the array(Max:15)\n");
 scanf("%d",&size);
 printf("Enter the elements of the array:\n");
 for(i=0;i<size;i++)
  {
   scanf("%d",&arr[i]);
  }
 printf("The Array is:\n");
 for(i=0;i<size;i++)
  {
   printf("%d\t",arr[i]);
  }
  printf("\nEnter the new element to be inserted in the array\n");
  scanf("%d",&value);
  printf("Enter the location in the array where new element is to be inserted \n");
  scanf("%d",&loc);

  for(i=size-1;i>=loc-1;i--)
  {
    arr[i+1]=arr[i];
  }
  arr[loc-1]=value;
  printf("New Array after insertion is:\n");
  for(i=0;i<=size;i++)
  {
    printf("%d\t",arr[i]);
  }
  return 0;
} 
