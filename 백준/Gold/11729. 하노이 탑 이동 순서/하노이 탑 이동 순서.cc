#include <stdio.h>
int cnt = 1;

void hanoi(int a, int b, int n)
{
	if (n == 1)
		printf("%d %d\n", a, b);
	else
	{
		hanoi(a, 6 - a - b, n - 1);
		printf("%d %d\n", a, b);
		hanoi(6 - a - b, b, n - 1);
	}
}

int main()
{
	int n;
	int t;
	scanf("%d", &n);
	for(int i = 1; i<=n; i++)
	{
	    cnt *= 2;
	}
	printf("%d\n", cnt-1);
	hanoi(1, 3, n);
    return 0;
}