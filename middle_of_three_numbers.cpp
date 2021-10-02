#include<iostream>
using namespace std;
int main(){
int A,B,C;
cin>>A>>B>>C;
//if((A-B)*(A-C)<0) return A;
//else if((B-A)*(B-C)<0) return B;
//else return C;
//time taken 5 seconds
//if(A>B) swap(A,B);
//if(B>C)swap(B,C);
//if(A>B) swap(A,B);
//return B;
//4 seconds

//if(A>B && B>C || C>B && B>A)
//return B;
//else if(B>A && A>C || A>B && C>B)
//return A;
//else if(A>B && C>B || B>A && B>C)
//return C;
//worst method 9 seconds

return (A>B && B>C)||(C>B && B>A) ? B : (B>A && A>C)||(C>A && A>B) ? A : C;
}
