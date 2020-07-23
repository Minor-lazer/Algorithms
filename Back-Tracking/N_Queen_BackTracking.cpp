#include<iostream>
using namespace std;
bool canPlace(char board[][100],int row,int col,int n)
{
    //checking column wise;
    
    for(int i=0;i<n;i++)
    {
        if(board[row][i]=='Q')
        {
            return false;
        }
    }
    
    
    //kahi row me to nhi
    
    
        for(int i=0;i<n;i++)
        {
            if(board[i][col]=='Q')
            {
                return false;
            }
        }
    
    
     int x=row;
     int y=col;
     
   //top left diagonal     
    while(x>=0 && y>=0)
    {
        if(board[x][y]=='Q')
        {
            return false;
        }
        
        x--;
        y--;
    }
    
    //top right diagonal
    x=row;
    
    y=col;
    while(x>=0 && y<n)
    {
        if(board[x][y]=='Q')
        {
            return false;
        }
        
        x--;
        y++;
    }
    
    return true;
    
    
    
}


bool solveNQueen(char board[][100],int n, int row)
 {
     if(row==n)
     {
         //print the board
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++)
             {
                 cout<<board[i][j]<<" ";
             }
             cout<<endl;
         }
         
        cout<<endl;
      }
      
      for(int pos=0;pos<n;pos++)
      {
          if(canPlace(board,row,pos,n))
          {
              board[row][pos]='Q';
              
              bool agliQueenRakhPayeKya = solveNQueen(board,n,row+1);
         if(agliQueenRakhPayeKya==true)
         {
             return true;
         }
         
         board[row][pos]='.';
         }
      }
      
      return false; //backtrack
}

int main()
{
    int n;
    cin>>n;
    
 char board[100][100];
 
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<n;j++)
     {
         board[i][j]='.';
     }
 }
 
 solveNQueen(board,n,0);
 
 return 0;
}
