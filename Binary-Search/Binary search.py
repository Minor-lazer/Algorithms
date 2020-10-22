# -*- coding: utf-8 -*-
"""
Created on Mon Mar  2 19:42:02 2020

@author: Mohit Mehta
"""


def binary_search(a,x):
    first_pos=0
    last_pos=len(a)-1
    flag=0   #flag=0 means that element is not been found yet
    count=0
    
    while(first_pos<last_pos and flag==0):
        count+=1
        mid=(first_pos+last_pos)//2
        if(x==a[mid]):
            flag=1
            print("The element is present at pos: "+str(mid))
            print("The number of iteration are: ",str(count))
            return
        else:
            if(x<a[mid]):
                last_pos=mid-1
            else:
                first_pos=mid+1
    print("The number is not present")
    
a=[]
for i in range(1,1000):
    a.append(i)
    
binary_search(a,500)
                