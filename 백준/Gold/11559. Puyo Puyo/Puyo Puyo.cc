#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

#define NONE 0
#define R 1
#define G 2
#define B 3
#define P 4
#define Y 5

int ans;
int map[12][6];
char input[12][7];
int visited[12][6];
queue<pair<int, int>> temp_queue;
queue<pair<int, int>> q; //(x,y)

void gravity()
{
    for(int i = 0; i<12;i++){
        for(int j = 0; j<6;j++){
            if(visited[i][j]){
                visited[i][j] = 0;
                map[i][j] = 0;
            }
        }
    }
    
    for(int i = 10; i>=0;i--){
        for(int j = 0; j<6;j++){
            if(map[i][j] == 0) continue;
            int temp = map[i][j];
            for(int k = i; k<11; k++){
                if(map[k+1][j] == 0){
                    map[k+1][j] = temp;
                    map[k][j] = 0;
                }else break;
            }
        }
    }
}

int main()
{

    //input
    for (int i = 0; i < 12; i++) {
        scanf("%s", input[i]);
        for (int j = 0; j < 6; j++) {
            if (input[i][j] == '.') map[i][j] = NONE;
            else if (input[i][j] == 'R') map[i][j] = R;
            else if (input[i][j] == 'G') map[i][j] = G;
            else if (input[i][j] == 'B') map[i][j] = B;
            else if (input[i][j] == 'P') map[i][j] = P;
            else if (input[i][j] == 'Y') map[i][j] = Y;
        }
    }


    //progress
    while(true)
    {
        int flag = 0;
        for(int i = 0; i<12; i++){
            for(int j = 0; j<6;j++){
                int temp = 1;
                if(map[i][j] == NONE) continue;
                if(visited[i][j]) continue;
                
                q.push(make_pair(j, i));
                visited[i][j] = 1;
                temp_queue.push(make_pair(j,i));
                
                while(!q.empty())
                {
                    int s = q.size();
                    for(int k = 0; k<s;k++){
                        int x = q.front().first;
                        int y = q.front().second;
                        int color = map[y][x];
                        
                        if(map[y+1][x] == color && !visited[y+1][x] && y+1>=0 && y+1<12 && x>=0 && x<6)
                        {
                            q.push(make_pair(x,y+1));
                            visited[y+1][x] = 1;
                            temp_queue.push(make_pair(x,y+1));
                            temp++;
                        }
                        if(map[y-1][x] == color && !visited[y-1][x] && y-1>=0 && y-1<12 && x>=0 && x<6)
                        {
                            q.push(make_pair(x,y-1));
                            visited[y-1][x] = 1;
                            temp_queue.push(make_pair(x,y-1));
                            temp++;
                        }
                        if(map[y][x+1] == color && !visited[y][x+1] && y>=0 && y<12 && x+1>=0 && x+1<6)
                        {
                            q.push(make_pair(x+1,y));
                            visited[y][x+1] = 1;
                            temp_queue.push(make_pair(x+1,y));
                            temp++;
                        }
                        if(map[y][x-1] == color && !visited[y][x-1] && y>=0 && y<12 && x-1>=0 && x-1<6)
                        {
                            q.push(make_pair(x-1,y));
                            visited[y][x-1] = 1;
                            temp_queue.push(make_pair(x-1,y));
                            temp++;
                        }
                        q.pop();
                    }
                }
                
                if(temp >= 4) flag = 1;
                if(temp < 4){
                    while(!temp_queue.empty())
                    {
                        int x = temp_queue.front().first;
                        int y = temp_queue.front().second;
                        visited[y][x] = 0;
                        temp_queue.pop();
                    }
                }
                
                while(!temp_queue.empty()) temp_queue.pop();
            }
        }
        
        if(flag == 1) ans++;
        else if(flag == 0) break;
        
        gravity();
    }
    
    printf("%d\n", ans);

    return 0;
}
