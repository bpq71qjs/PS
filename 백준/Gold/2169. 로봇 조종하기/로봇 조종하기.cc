#include <iostream>
#include <algorithm>

using namespace std;

int INF = -1000000000;

int arr[1001][1001]; 
int dp[1001][1001][2]; // dp[i][j][0] : 왼쪽에서 왔을 때 dp[i][j][1] : 오른쪽에서 왔을 때
int MAX(int a, int b, int c){
    return max(a, max(b, c));
}

int main() {
    int N, M, i, j;

    cin >> N >> M;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++) cin >> arr[i][j];
    }
    
    
    for(i=0; i<=N; i++){
        for(j=0; j<=M; j++){
            dp[i][j][0] = INF;
            dp[i][j][1] = INF;
        } 
    }

    for(j = 0; j <= M; j++) 
    {
        if(j == 0) 
        {
            dp[0][j][0] = arr[0][j];
            dp[0][j][1] = INF;
        } else 
        {
            dp[0][j][0] = dp[0][j-1][0] + arr[0][j];
            dp[0][j][1] = INF;
        }
    }

    for(i = 0; i < N; i++) 
    {
        for(j = 0; j < M; j++) 
        {
            // dp[i][j][0] : 왼쪽에서 오는 값
            if(i==0)
            {
                if(j==0) dp[i][j][0] = arr[i][j];
                else dp[i][j][0] = dp[i][j-1][0] + arr[i][j];
            }
            
            else
            {
                if(j==0) dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]) + arr[i][j];
                else dp[i][j][0] = MAX(dp[i-1][j][0], dp[i-1][j][1], dp[i][j-1][0]) + arr[i][j];
            }
            
            
            // dp[i][M-j-1][1] : 오른쪽에서 오는 값 
            if (M-j-1 >= 0) 
            {  
                if(i == 0) dp[i][M-j-1][1] = INF;
                else dp[i][M-j-1][1] = MAX(dp[i-1][M-j-1][0], dp[i-1][M-j-1][1], dp[i][M-j][1]) + arr[i][M-j-1];
            }
        }
    }



    cout << dp[N-1][M-1][0] << "\n";
}
