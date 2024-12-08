#include <stdio.h>

int visited[26];
int arr[21][21];
int N,M;

int ans;

void f(int x, int y, int step)
{
    int value = arr[y][x];

    if(visited[value]) return;
    if(x<1 || x>M || y<1 || y>N) return;
    
    visited[value] = 1;
    f(x+1, y, step+1);
    f(x-1, y, step+1);
    f(x, y+1, step+1);
    f(x, y-1, step+1);
    
    if(ans < step) ans = step;
    visited[value] = 0;
    return;
}

int main()
{
    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            scanf("\n%c", &arr[i][j]);
            arr[i][j] = arr[i][j] - 'A' + 1;
        }
    }

    f(1,1,1);
    printf("%d\n", ans);

    return 0;
}