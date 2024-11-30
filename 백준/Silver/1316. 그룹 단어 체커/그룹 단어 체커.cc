#include <stdio.h>

bool arr[26];
char string[100][101];

int main()
{
	int N;
	scanf("%d",&N);
	//input
	for(int i = 1; i<=N;i++) scanf("%s",string[i]);	

	int ans = 0;

	for(int i = 1; i<=N; i++){
		int temp = 0;
		int flag = 1;
		for(int j = 0; string[i][j]!='\0';j++){
			if(97<=temp && temp != string[i][j]) arr[temp-'a'+1] = true;
			if(!arr[string[i][j]-'a'+1]) temp = string[i][j];
			else if(arr[string[i][j]-'a'+1]){
				flag = 0;
				break;
			}
		}
		if(flag == 1) ans++;
		
		//reset
		for(int j = 0; j<=26;j++) arr[j] = false; 
	}

	printf("%d\n",ans);

	return 0;
}
