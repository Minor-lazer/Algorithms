#include<bits/stdc++.h>
using namespace std;
void occurence(string str, int idx,char element){
        int first,last=-1;
    if(idx == str.length()){
        cout<<first;
        cout<<last;
        return;
    }
    char currChar = str.at(idx);
    if(currChar == element){
        if(first == -1){
            first=idx;
        }
        else{
            last=idx;
    }
    }
    occurence(str,idx+1,element);
}

int main(){
string str;
cin>>str;
char element;
cin>>element;
occurence(str,0,element);
}
