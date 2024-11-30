#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char arr[51][51];
char ans[51][51];
char str[51];
int cnt = 0;

int main()
{

	scanf("%s",str);
	
	int temp = 0;

	for(int i = 0; str[i]!='\0';i++){
		temp = i;
		for (int j = i; str[j] != '-' && str[j] != '+' &&str[j]!='\0'; j++) {
			arr[cnt][j-i] = str[j];
			temp = j;
		}

		arr[cnt++][temp - i + 1] = '\0';
		
		if(str[temp+1] == '-' || str[temp+1] == '+') {
			arr[cnt][0] = str[temp+1];
			arr[cnt++][1] = '\0';

		}
		if (str[i + 1] == '\0') {
			arr[cnt++][temp - i + 1] = '\0';
		}
		i = temp+1;
	}
	int a = atoi(arr[0]);
	int max = 0;
	
	for(int i = 1; i<cnt+1;i++){
		if (arr[i][0] == '+') continue;


		if (max == 3) {
			int tt = atoi(ans[0]) - atoi(ans[2]);
			sprintf(ans[0], "%d", tt);
			ans[1][0] = ans[3][0];
			ans[1][1] = '\0';
			max = 2;
			a = 0;
		}

		else if (arr[i][0] == '-') {
			sprintf(ans[max++], "%d", a);
			ans[max][0] = '-';
			ans[max++][1] = '\0';
			a = 0;
		}

		if (i == cnt) {
			a += (atoi(arr[i]));
			sprintf(ans[max++], "%d", a);
			break;
		}

		else a += (atoi(arr[i]));
	}

	int sum = atoi(ans[0]);

	for (int i = 1; i < max; i++) {
		if (ans[i][0] == '-') {
			sum -= (atoi(ans[i + 1]));
		}
		if (ans[i][0] == '+') {
			sum += (atoi(ans[i + 1]));
		}
	}

	printf("%d\n", sum);
	
	return 0;
}
//dfasafsdsdf