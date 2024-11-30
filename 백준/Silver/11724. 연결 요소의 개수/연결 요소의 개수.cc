#include <iostream>
#include <vector>
using namespace std;

vector<int> vect[1005]; 
int visited[1005];      
int N, M;


void dfs(int i)
{
    visited[i] = 1;
    for (int ii = 0; ii < vect[i].size(); ii++) 
    {
        int idx = vect[i][ii];
        if (visited[idx] == 0)
        {
            dfs(idx);
        }
    }
}

int main()
{
    int u, v;
    int cnt = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        vect[u].push_back(v);
        vect[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) 
    {
        if (visited[i] == 0)
        {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << "\n";
}