#include <iostream>
using namespace std;
void isEvenOrOdd(int n)
{

    if (n & 1 != 0)
        cout<<"The number "<<n<<" is Odd";
    else
        cout<<"The number "<<n<<" is Even";
}
 main()
{
    int n;
    cin>>n;
    isEvenOrOdd(n);
}
