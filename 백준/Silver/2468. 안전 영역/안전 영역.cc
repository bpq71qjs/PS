#include <stdio.h>
#include <queue>

using namespace std;

int N;
int arr[100][100];
int ans = 0;
int visited[100][100];


queue<pair<int,int>> q;

int main()
{
    scanf("%d",&N);
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++) scanf("%d",&arr[i][j]);
    
    for(int h = 0; h<=100; h++){
        int temp = 0;
        for(int i = 0; i<N;i++){
            for(int j = 0; j<N;j++){
                if(arr[i][j] <= h || visited[i][j] == 1)continue; 
                q.push(make_pair(j,i));
                visited[i][j] = 1;
                while(!q.empty())
                {
                    int s = q.size();
                    for(int k = 0; k<s;k++){
                        int x = q.front().first;
                        int y = q.front().second;

                        if(arr[y+1][x] > h && y+1>= 0 && y+1<N && x>=0 && x<N && !visited[y+1][x]){
                            q.push(make_pair(x,y+1));
                            visited[y+1][x] = 1;
                        }
                        if(arr[y-1][x] > h && y-1>= 0 && y-1<N && x>=0 && x<N && !visited[y-1][x]){
                            q.push(make_pair(x,y-1));
                            visited[y-1][x] = 1;
                        }
                        if(arr[y][x-1] > h && y>= 0 && y<N && x-1>=0 && x-1<N && !visited[y][x-1]){
                            q.push(make_pair(x-1,y));
                            visited[y][x-1] = 1;
                        }
                        if(arr[y][x+1] > h && y>= 0 && y<N && x+1>=0 && x+1<N && !visited[y][x+1]){
                            q.push(make_pair(x+1,y));
                            visited[y][x+1] = 1;
                        }
                        q.pop();
                    }
                }
                temp++;
            }
            
        }
        for(int k = 0; k<N;k++) for(int kk = 0; kk<N; kk++) visited[k][kk] = 0;
        if(temp > ans) ans = temp;
    }
   
    printf("%d",ans);
    
    return 0;
}