#include <stdio.h>

void f(int a, int b)
{
	(a == b)? printf("==\n"):(a<b)?printf("<\n"):printf(">\n");
}

int main()
{
	int a, b;
	scanf("%d %d",&a,&b);
	
	f(a, b);
	
	return 0;
}
