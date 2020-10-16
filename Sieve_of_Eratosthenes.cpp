#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void Sieve_of_Eratosthenes(int a[], int n)
{

    for(int i=2; i<=sqrt(n); i++)
    {
        if(a[i] == 0)
        {
            // initializing the positions of those numbers that are not prime equal to 1.
            for(int j=i*i; j<=n; j+=i)
            {
                a[j] = 1;
            }
        }
    }

    for(int i=2; i<=n; i++)
    {
        // if a[i] == 0 it means i is a prime no
        if(a[i] == 0)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    //Initializing the array of size n with 0
    int a[n] = {0};
    Sieve_of_Eratosthenes(a, n);
    return 0;
}
