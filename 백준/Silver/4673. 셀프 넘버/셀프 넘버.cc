#include <stdio.h>

int arr[10001];

int main()
{
    for(int i = 1; i<=10000;i++)
    {
        int x = i;
        int temp = i;
        while(temp)
        {
            x += (temp%10);
            temp/=10;
        }
        
        if(x<=10000) arr[x] = 1;
    }

    for(int i=1; i<=10000;i++){
        if(arr[i] != 1) printf("%d\n", i);
    }

    return 0;
}