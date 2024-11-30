#include <stdio.h>

int arr[1001][1001];

int main()
{
    int N;
    scanf("%d", &N);
    int ans;
    scanf("%d", &ans);
    
    int x = N/2 +1;
    int y = N/2 +1;
    int t = 1;
    int i = 1;
    arr[y][x] = 1;
    
    while(1)
    {
        if(t == N+1)
        {
            break;
        }
        
        if(t%2==1)
        {
            for(int j = 1; j<=t; j++)
            {
                arr[--y][x] = ++i;
            }
            for(int j = 1; j<=t; j++)
            {
                arr[y][++x] = ++i;
            }
        }
        else if(t%2==0)
        {
            for(int j = 1; j<=t; j++)
            {
                arr[++y][x] = ++i;
            }
            for(int j = 1; j<=t; j++)
            {
                arr[y][--x] = ++i;
            }
        }
        t++;
    }
    for(int j = 1; j<=N; j++)
    {
        for(int k = 1; k<=N; k++){
            printf("%d ", arr[j][k]);
        }
        printf("\n");
    }
    
    for(int j = 1; j<=N; j++)
    {
        for(int k = 1; k<=N; k++){
            if(ans == arr[j][k]){
                printf("%d %d", j, k);
                return 0;
            }
        }
    }
    
    return 0;
}