#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	double ans = 0.5;
	double H=0, G=0;

	char word[1681];
	scanf("%[^\t\n]s", word);
	
	for(int i = 0; word[i]!='\0';i++){
		char x = word[i];
		H+=((x == 'H') + (x == 'A') + (x == 'P') + (x == 'Y'));
		G+=((x=='S') + (x=='A') + (x=='D'));
	}
	if(H+G==0) {
		printf("50.00");
		return 0;
	}

	ans = H / (H+G);


	printf("%0.2lf", round(ans*10000)/100); 


	return 0;
}
