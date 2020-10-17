#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	
	cin>>n;
	
	int x=0,y=0;
	
	int c=1;
	
	int distance =10;
	
	while(n)
	{
		switch(c)
		{
			case 1:
				x=x+distance;
				distance=distance+10;
				c=2;
				break;
			
			case 2:
			  y=y+distance;
			  distance=distance+10;
			  c=3;
			  break;
			  
			case 3:
			  x=x-distance;
			  distance=distance+10;
			  c=4;
			  break;
			  
			case 4:
			  y=y-distance;
			  distance=distance+10;
			  c=5;
			  break;
			case 5:
			  x=x+distance;
			  distance=distance+10;
			  c=1;
			  break;
		   
		
		
		}
		
		n--;
		
	}
    cout<<x<<" "<<y<<endl;
	
	return 0;	
}
