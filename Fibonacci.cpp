//C++program
//Output of below program is the Nth number of a fibonacci sequence
//Recursion
//Fibonacci sequence will be 0 1 1 2 3 5 8 13....

#include <bits/stdc++.h>
using namespace std;

long long fibonacci(int n)
{
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}





int main() {
	int n;
	cin>>n;
	cout<<fibonacci(n);
	return 0;
}  

