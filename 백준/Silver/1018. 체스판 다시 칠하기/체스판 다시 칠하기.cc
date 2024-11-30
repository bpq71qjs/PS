#include <stdio.h>
#include <algorithm>

using namespace std;


char board[51][52];
int N, M;


int bruteforce(int a, int b)
{
	int cnt = 0;
	//(1,1) WHITE
	for(int i = a; i<=a+7;i++){
		for(int j = b; j<=b+7;j++){
			if((i+j)%2 == 0 && board[i][j] != 'W') cnt++;
			else if((i+j)%2 != 0 && board[i][j] != 'B') cnt++;
		}
	}
	int temp = cnt;
	
	cnt = 0;
	//(1,1) BLACK
	for(int i = a; i<=a+7;i++){
		for(int j = b; j<=b+7;j++){
			if((i+j)%2 == 0 && board[i][j] != 'B') cnt++;
			else if((i+j)%2 != 0 && board[i][j] != 'W') cnt++;
		}
	}
	
	if(temp > cnt) return cnt;
    else return temp;
}


int main()
{
	scanf("%d %d", &N, &M);

	for(int i=1;i<=N;i++)
		for(int j=1; j<=M;j++)
			scanf(" %c",&board[i][j]);
	int ans = 2501;
    int temp = 0;
	//bruteforce
	for(int i=1; i<=N-7;i++){
		for(int j=1; j<=M-7;j++){
            temp = bruteforce(i, j);
			if(ans > temp) ans = temp;
		}
	}

	printf("%d\n", ans);

	return 0;
}
