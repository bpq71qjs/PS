#include <stdio.h>

void f(int N)
{
	int sum;
	int temp;
	for(int i = 1; i<=N;i++){
		sum = 0;temp = i;
		while(temp)
		{
			sum += (temp%10);
			temp/=10;
		}
		sum += i;

		if(sum == N){
			printf("%d", i);
			return;
		}
	}
	printf("0");
}


int main()
{
	int N;
	scanf("%d",&N);

	f(N);

	return 0;
}
