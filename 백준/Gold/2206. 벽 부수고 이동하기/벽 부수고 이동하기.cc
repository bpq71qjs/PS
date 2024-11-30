#include <stdio.h>
#include <queue>
using namespace std;

struct Data
{
  int x;
  int y;
  int wall;
};

int M,N;

//[N][M]
char string_input[1005][1005];
int arr[1001][1001];
int visited[2][1005][1005];

queue<Data> q;
int ans=1;

void push(int x, int y, int wall)
{
  if(x<=M && y<=N && y>=1 && x>=1 && !visited[wall][y][x])
  {
    if(arr[y][x] == 1 && wall==0)
    {
      visited[1][y][x]++;
      q.push({x,y,1});
    }
    else if(arr[y][x]==0)
    {
      visited[wall][y][x]++;
      q.push({x,y,wall});
    }
  }
}

int main()
{
 scanf("%d %d",&N,&M);
 for(int i = 1; i<=N; i++) scanf("%s", string_input[i]);
 
 for(int i = 1; i<=N; i++){
   for(int j = 0; string_input[i][j]!='\0';j++)
   {
     arr[i][j+1] = string_input[i][j] - '0';
   }
 }
 
 q.push({1,1,0});
 visited[0][1][1] = 1;
 while(!q.empty())
 {
   int s = q.size();
   for(int i = 0; i<s; i++)
   {
     int x = q.front().x;
     int y = q.front().y;
     int wall = q.front().wall;
     
     if(x == M && y == N)
     {
       printf("%d\n",ans);
       return 0;
     }
     push(x+1, y, wall);
     push(x-1, y,wall);
     push(x, y+1,wall);
     push(x, y-1,wall);
     
     q.pop();
     
   }
   ans++;
 }
 
 printf("-1\n");
  
  return 0;
}
