

#include <stdio.h>
int ackerman(int m, int n)
{
	if (m == 0){
		return n+1;
	}
	else if((m > 0) && (n == 0)){
     return ackerman(m-1, 1);
	}
	else if((m > 0) && (n > 0)){
		return ackerman(m-1, ackerman(m, n-1));
	}
}

int main(){
	int A;
	A = ackerman(2, 1);
	printf("%d", A);
	return 0;
}


