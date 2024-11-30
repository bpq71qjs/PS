#include <stdio.h>
#include <queue>

using namespace std;

int visited[100001];

int main()
{
	int N,K;
	int ans = 0;
	scanf("%d %d",&N,&K);

	queue<int> q;
	q.push(N);
	visited[N] = 1;

	while(!q.empty())
	{
		int s = q.size();
		for(int i = 0; i<s;i++){
			int x = q.front();
			
			if(x == K) {
				printf("%d\n",ans);
				return 0;
			}

			if(x*2<=100000 && !visited[x*2]){
				visited[x*2] = 1;
				q.push(x*2);
			}
			if(x+1<=100000 && !visited[x+1])
			{
				visited[x+1] = 1;
				q.push(x+1);
			}
			if(x-1>=0 && !visited[x-1])
			{
				visited[x-1] = 1;
				q.push(x-1);
			}

			q.pop();
		}
		ans++;
	}

	return 0;
}
