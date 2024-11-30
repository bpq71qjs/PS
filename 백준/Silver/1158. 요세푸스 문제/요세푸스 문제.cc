#include <stdio.h>
#include <queue>

using namespace std;


queue<int> q;

queue<int> ans;

int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	
	for(int i = 1; i<=N;i++)
		q.push(i);
	
	printf("<");
	while(!q.empty())
	{
		if(q.size()!=N) printf(", ");
		
		for(int i = 1; i<K;i++){
			int temp = q.front();

			q.pop();
			q.push(temp);
		}
		printf("%d",q.front());
		q.pop();
	}
	printf(">\n");

	return 0;
}
