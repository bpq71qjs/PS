#include <stdio.h>
#include <queue>

using namespace std;

int matrix[1001][1001];
bool visited[1001];

int N,M;

void dfs(int x)
{
    visited[x] = true;
    printf("%d ",x);
    
    for(int i = 1; i<=N;i++){
        if(matrix[x][i] && !visited[i]){
            dfs(i);
        }
    }
    
    return;
}

int main()
{
    int v;
    scanf("%d %d %d",&N,&M,&v);
    
    for(int i=1; i<=M;i++){
        int a, b;
        scanf("%d %d",&a,&b);
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    
    //dfs
    dfs(v);
    printf("\n");
    
    //visited 초기화
    for(int i = 1; i<=N;i++){
        visited[i] = false;
    }
    
    //bfs
    queue<int> q;
    q.push(v);
    visited[v] = true;
    printf("%d ",v);
    while(!q.empty())
    {
        int t = q.front();
        for(int i=1; i<=N;i++){
            if(matrix[t][i] && !visited[i]){
                printf("%d ",i);
                visited[i] = true;
                q.push(i);
            }
        }
        q.pop();
    }
    
    return 0;
}