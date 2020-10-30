//Program to change of a character function
#include <iostream>
using namespace std;


char lowerToUpper(char c)
{
	return (c & '_');
}

char upperToLower(char c)
{
	return (c | ' ');
}
 main()
{
	char c;
	cout << "Enter a Character(Lower Case) :"<<endl;
	cin >> c;
	cout << "Result :  "  << lowerToUpper(c);
	cout << "Enter a Character (Upper case) :"<<endl;
	cin >> c;
	cout << "Result :  "  << upperToLower(c);
}