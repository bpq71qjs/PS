#include <stdio.h>

int main()
{
	int x,y,w,h;
	scanf("%d %d %d %d",&x,&y,&w,&h);

	int ans[4];

	ans[0] = x;
	ans[1] = w-x;
	ans[2] = y;
	ans[3] = h-y;
	
	int min = 1001;

	for(int i = 0; i<4;i++) if(ans[i] < min) min = ans[i]; 

	printf("%d", min);

	return 0;
}
