#include<bits/stdc++.h>
#define N 101
using namespace std;
int ar[N][N],I[N][N];
void mul(int A[][N],int b[N][N],int dim){
    int res[dim][dim];
    int i,j,k;
    for(i = 0; i < dim; ++i)
        for(j = 0; j < dim; ++j)
            res[i][j]=0;
            for( k = 0; k < dim; ++k)
            {
                res[i][j]+= A[i][k] * b[k][j]; 
            }
    for(i=0;i<dim;i++)
        for(j=0;j<dim;j++)
            A[i][j]=res[i][j];
}
void power(int A[][N],int dim,int n){
    // Setting up identity Matrix
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            if(i==j)
                I[i][j]=1;
            else
                I[i][j]=0;
        }
    }
    mul(I,A,dim);
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
            A[i][j]=I[i][j];
}
int main(){
    int n,dim;
    cout<<"Enter dimension and power\n";
    cin>>dim>>n;
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
            cin>>ar[i][j];
    power(ar,dim,n);
    for(int i=0;i<n;i++){for(int j=0;j<n;j++)
        cout<<ar[i][j]<<" ";}
}