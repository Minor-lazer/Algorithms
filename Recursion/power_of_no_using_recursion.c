#include <stdio.h>
#include <stdlib.h>

int powShort(int m, int n){
	
	if(n==0){
		return 1;
	}
	if(n%2==0){
		return powShort(m*m, n/2);
	}
	else
	{
		return m*powShort(m*m, (n-1)/2);
	}
}

int main(){
	printf("%d", powShort(2, 9));
}
