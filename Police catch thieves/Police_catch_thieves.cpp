#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//returning maximum number of thieves that can be caught
int policeThief(char arr[], int n, int k){
   int caught = 0;
   vector<int> thieves;
   vector<int> policemen;
   for (int i = 0; i < n; i++) {  // here we are stroing indices in the vectors
      if (arr[i] == 'P')
         policemen.push_back(i);
      else if (arr[i] == 'T')
         thieves.push_back(i);
   }
   int thief = 0, police = 0; // tracking the lower indices
   while (thief < thieves.size() && police < policemen.size()) {
      if (abs(thieves[thief] - policemen[police]) <= k) { // thieves that can be caught 
         caught++; 
         thief++;
         police++;
      }
      else if (thieves[thief] < policemen[police])
         thief++;
      else
         police++;
   }
   return caught;
}
int main(){
   int k, n;
   char arr2[] = {'P', 'T', 'T', 'P', 'P', 'T', 'T', 'T', 'T', 'P' };
   k = 2;
   n = sizeof(arr2) / sizeof(arr2[0]);
   cout << "Maximum number of thieves that can be caught by police is :"<<policeThief(arr2, n, k);
   return 0;
}
