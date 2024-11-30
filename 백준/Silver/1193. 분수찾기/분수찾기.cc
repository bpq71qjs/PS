#include <stdio.h>

void f(int N);

int main()
{
	int N;
	scanf("%d", &N);

	f(N);
	
	return 0;
}

void f(int N)
{
	int a=1,b=1;
	int ii=1,jj=1;
	int cnt = 0;
	while(1)
	{
		if(jj>ii){
			ii++;
			jj = 1;
		}
		if(ii%2!=0){
			b = jj;
			a=ii-jj+1;
		}
		else if(ii%2==0){
			b=ii-jj+1;
			a=jj;
		}
		cnt++;

		if(cnt==N){
			printf("%d/%d\n",a,b);
			break;
		}
		jj++;

	}
}
