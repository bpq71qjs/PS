#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct Pictures
{
	int id;
	int votes;
	int time;
};

bool compare(const Pictures &a, const Pictures &b)
{
	if(a.votes == b.votes)
	{
		return a.time < b.time;
	}
	return a.votes < b.votes;
}


int main()
{
	int N;
	int totalvotes;
	scanf("%d",&N);
	scanf("%d",&totalvotes);

	vector<int> temp(totalvotes+1);
	vector<Pictures> arr;

	for(int i = 1; i<=totalvotes; i++)
	{
		scanf("%d",&temp[i]);
	}

	for(int t = 1; t<=totalvotes; t++)
	{
		int id = temp[t];
		int flag = 0;
		for(int i = 0; i<arr.size();i++)
		{
			if(arr[i].id == id){
				flag = 1;
				arr[i].votes++;
				break;
			}
		}
		if(!flag)
		{
			if(arr.size() < N)
			{
				arr.push_back({id, 1, t});
			}
			else{
				sort(arr.begin(), arr.end(), compare);
				arr[0] = {id, 1, t};
			}
		}
	}


	vector<int> ans;
	for(int i = 0; i<arr.size(); i++) ans.push_back(arr[i].id);

	sort(ans.begin(), ans.end());
	for(int i = 0; i<ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}

	return 0;
}
