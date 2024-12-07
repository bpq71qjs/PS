#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
	long long int a,b;
	scanf("%lld %lld",&a,&b);

	queue<long long int> q;
	q.push(a);
	long long int ans = 1;
	while(!q.empty())
	{
		long long int s = q.size();

		for(long long int i = 0; i<s;i++){
			long long int t = q.front();
			if(t*2==b || t*10+1==b){
				printf("%lld\n",ans+1);
				return 0;
			}
			if(t*2 < b) q.push(t*2);
			if(t*10+1 < b) q.push(t*10+1);
			q.pop();
		}
		ans++;
	}
	
	printf("-1\n");

	return 0;

}
