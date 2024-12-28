/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int N, i, j, lim, s;
    int arr[50005] = {0,};
    int sum[50005] = {0,};
    int dp[50005][4];

    cin >> N;

    for(i = 1; i<=N; i++){
        sum[0] = 0;
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }
    
    for(i=1; i<=N; i++){
        dp[i][0] = 0;
    }

    cin >> lim;

    
    for(j=1; j<=3; j++){
        for(i=(j-1) * lim + 1; i<=N; i++){
            //cout << i << " " << j << "\n";
            s = sum[i] - sum[i-min(lim,i)];
            dp[i][j] = s;
            dp[i][j] = max(dp[i][j], dp[i-min(lim,i)][j-1] + s);
            if(i>=lim) dp[i][j] = max(dp[i][j], dp[i-1][j]);
            
        }

    }

    cout << max(max(dp[N][1], dp[N][2]),dp[N][3]);

}

