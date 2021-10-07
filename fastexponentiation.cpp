#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    unsigned long long a, b, c = 1e9 + 7, s, two = 2, one = 1;
    while (t--)
    {
        s = 1;
        cin >> a >> b;
        a = a % c;
        while (b > 0)
        {
            if (b % 2 == 0)
            {
                a = (a * a) % c;
                b = b / two;
            }
            else
            {
                s = (s * a) % c;
                b = b - one;
            }
        }
        cout << s << endl;
    }
    return 0;
}
