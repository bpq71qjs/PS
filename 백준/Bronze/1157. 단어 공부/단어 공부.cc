#include <stdio.h>

int arr[26];
int main()
{
	arr[26] = -1;
	char string[1000001];
	scanf("%s",string);

	for(int i = 0; string[i]!='\0';i++){
		if('a' <= string[i])  arr[string[i]-'a']++;
		else if('A' <= string[i]) arr[string[i]-'A']++;
	}

	//find max
	int max = 26;
	int temp = -1;
	for(int i = 0; i<26;i++){
		if(arr[i] > arr[max]) max = i;
		else if(arr[i] == arr[max]) temp = arr[i];	
	}

	arr[max]==temp?printf("?"):printf("%c",max+'A');

	return 0;
}
