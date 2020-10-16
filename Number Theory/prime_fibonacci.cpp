#include<iostream>
#include<array>
using namespace std;
//to check primality
bool isPrime(int n){
if(n==2) return true;
if(n<=1 || n%2==0) return false;
for(int i=3;i<=sqrt(n);i=i+1)
if(n%i==0) return false;
return true;
}

//combines numbers
int conNumbers(int n, int m){
string s="";
while(m!=0){
s+= to_string(m%10);
m/=10;
}
double x = pow(10, s.length());
n *= x;

//concatenate m to n
for(int i=0; i<s.length(); i++)
n+= (s[i]-'0') * pow(10, i);
return n;
}

//return nth element in fibonacci series
long long int nthFib(int smallest,int largest,int length){
long long int fib[length];
fib[0]=smallest;
fib[1]=largest;
for(int i=2;i<length;i++){
fib[i]=fib[i-1]+fib[i-2];
}
return fib[length-1];
}
//returns answer
long long int solution(int n1,int n2){
vector list1;//to store list 1, ie primes between n1 and n2
//generates prime list
for(int i=n1;i<=n2;i++)
if(isPrime(i))
list1.push_back(i);
set primeCombi; //to store combinations which are prime
for(int i=0; i<list1.size(); i++)
for(int j=0; j>n1>>n2;
cout<<solution(n1,n2);
return 0;
}
