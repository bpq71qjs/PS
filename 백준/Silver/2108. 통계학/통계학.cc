#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int arr[500001];
int cnt;
vector <pair<int, int>> vec;

bool compare(pair<int, int> a, pair<int, int>b)
{
	if(a.first != b.first) return a.first > b.first;
	else return a.second < b.second;
}

bool compare2(int a, int b)
{
	return vec[a].second < vec[b].second;
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i = 1; i<=N;i++){
		scanf("%d",&arr[i]);
	}

	sort(arr+1, arr+1+N);

	double N1 = 0;
	
	for(int i=1;i<=N;i++) N1 += arr[i];
	
	N1/=N;

	N1 = round(N1);
	printf("%d\n",(int)N1);
	
	printf("%d\n",arr[N/2+1]);	

	int maxx = 0;
	for(int i = 1;i<=N;i++){
		int temp = 0;
		for(int j=i; j<=N;j++){
			if(arr[i] == arr[j]) temp++;
			else break;
		}
		if(maxx <= temp){
			vec.push_back(make_pair(temp, arr[i]));
			i+=temp-1;
		}
	}
	
	sort(vec.begin(), vec.end(), compare);

	int N3 = 0;

	if(vec.size() == 1){
		N3 = vec[0].second;
	}

	else{
		int arr2[500001];
		maxx = vec[0].first;
		for(int i = 0; i<vec.size();i++){
			if(maxx < vec[i].first){
				maxx = vec[i].first;
				arr2[++cnt] = i;
			}else if(maxx == vec[i].first){
				arr2[++cnt] = i;
			}
		}

		sort(arr2+1, arr2+cnt+1, compare2);
		N3 = vec[arr2[2]].second;
	}

	printf("%d\n",N3);
	
	printf("%d\n",arr[N] - arr[1]);


	return 0;
}
