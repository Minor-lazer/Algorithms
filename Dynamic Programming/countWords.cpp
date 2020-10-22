#include<bits/stdc++.h>
using namespace std;

const int Nmax = (int)1e6+1;
int main()
{
	char s[Nmax];
	gets(s);

	int l = strlen(s);
	int check = 0;
	int count = 0;
	for (int i = 0; i<l ; i++) {
		if (s[i] == '.' || s[i] == ' ' || s[i] == '!' || s[i] == '?' || s[i] == ',')
			check = 0;
		else if (check == 0) {
			check = 1;
			count++;
		}

	}
	cout << count << endl;


	return 0;
}


