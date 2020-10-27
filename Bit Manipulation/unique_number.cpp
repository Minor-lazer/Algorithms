// C program to get toggle case of a string 
#include <iostream> 
void *changeLetterCase(char *a) 
{ 
    for (int i=0; a[i]!='\0'; i++) { 
  
        a[i] ^= 32; 
    } 
  
    cout<<"The Altered Letter Case String: "<<a<<endl;
} 
  
// Driver Code 
int main() 
{ 
    char str[100];
    cin>>str;
   cout<<"The Original String: "<<str<<endl;
   changeLetterCase(str);
} 