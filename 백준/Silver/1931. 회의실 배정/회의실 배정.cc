#include <stdio.h>
#include <algorithm>

using namespace std;

int ans = 1;
int N;

struct Meeting
{
	int s;
	int e;
}arr[100001];

bool compare(const Meeting& a, const Meeting& b){
	if(a.e == b.e) return a.s<b.s;
	return a.e<b.e;
}

int main()
{
	scanf("%d",&N);
	for(int i=1; i<=N;i++){
		scanf("%d %d",&arr[i].s, &arr[i].e);
	}

	sort(arr+1, arr+1+N, compare);

	int time = arr[1].e;
	for(int i = 2; i<=N;i++){
		if(time <= arr[i].s){
			ans++;	
			time = arr[i].e;
		}
	}

	printf("%d\n",ans);

	return 0;
}
