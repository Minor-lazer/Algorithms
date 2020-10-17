import numpy as np

a = np.array([])

a = list(map(int, input("Enter the elements of Array ").split()))

print(f"The inserted array is {a}")

n = len(a)

start = 0
end = n-1
while start<end:
    a[start], a[end] = a[end], a[start]
    
    start+=1
    end-=1

print(f"The reversed array is {a}")



    

