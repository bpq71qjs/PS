#include <stdio.h>
#include <queue>

using namespace std;

int visited[1000001];

int main()
{
	int N;
	scanf("%d",&N);
	
	queue<int> arr;
	arr.push(N);
	visited[N] = 1;
	int ans = 0;


	while(!arr.empty())
	{
		int s = arr.size();
		for(int i = 0; i<s;i++){
			int x = arr.front();
			
			if(x==1){
				printf("%d\n", ans);
				return 0;
			}

			if(x%3==0 && !visited[x/3]){
				arr.push(x/3);
				visited[x/3] = 1;
			}
			if(x%2==0 && !visited[x/2]){
				arr.push(x/2);
				visited[x/2] = 1;
			}
			if(x-1>=1 && !visited[x-1]){
				arr.push(x-1);
				visited[x-1] = 1;
			}
			
			arr.pop();
		}
		ans++;
	}

	printf("%d\n", ans);

	return 0;
}
