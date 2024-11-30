#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int L,C;

char password[16];
char keyword[16];
int visited[15];

void backtracking(int step, int state, int state2)
{
	if(step == L)
	{
		password[L] = '\0';
	
		if(!(state >= 1) || !(state2 >= 2)) return;

		printf("%s\n",password);

		return;
	}

	for(int i = 0; i<C;i++)
	{
		if(password[step-1] >= keyword[i]) continue;
		if(!visited[i])
		{
			char c = keyword[i];

			password[step] = c;
			visited[i] = 1;

			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			{
				backtracking(step+1, state+1, state2);
			}else backtracking(step+1, state, state2+1);
			visited[i] = 0;
			password[step] = 0;
		}
	}
	return;
}


int main()
{
	scanf("%d %d",&L,&C);

	for(int i = 0; i<C;i++){
		scanf(" %c",&keyword[i]);
	}
	keyword[C] = '\0';
	
	sort(keyword, keyword+C);

	backtracking(0, 0, 0);

	return 0;
}
