#include <stdio.h>

int N;

int f(int i, int step)
{
	int x = (i%10*10)+((i/10+i%10)%10);
	if(x==N) return step;
	return f(x , step+1);
}

int main()
{
	scanf("%d",&N);

	printf("%d\n",f(N,1));

	return 0;
}
