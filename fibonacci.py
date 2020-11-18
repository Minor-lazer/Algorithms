

nterms = int(input("How many terms? "))

n1, n2 = 0, 1
count = 0


if nterms <= 0:
   print("Please enter a positive integer")
elif nterms == 1:
   print("Fibonacci sequence upto",nterms,":")
   print(n1)
else:
   print("Fibonacci sequence:")
   while count < nterms:
       print(n1)
       nth = n1 + n2
       n1 = n2
       n2 = nth
       count += 1
         
         
         
         
n=int(input("enter the value of 'n' :"))
a=0
b=1
sum=0
count=1
print("Fibonacci series:",end=" ")
while(count <= n):
    print(sum,end= " ")
    count += 1
    a=b
    b=sum
    sum=a+b
