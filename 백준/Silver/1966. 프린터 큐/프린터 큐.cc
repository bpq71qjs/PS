#include <stdio.h>
#include <queue>


using namespace std;

struct Dataa
{
    int index;
    int x;
};

queue<Dataa> q;
int arr[101];
int cnt;
int main()
{
    int N,M;
    int loop;
    scanf("%d",&loop);
    for(int i = 1; i<=loop; i++)
    {
        int temp;
        cnt=1;
        scanf("%d %d",&N,&M);
        for(int iii = 1; iii<=N; iii++)
        {
            
            scanf("%d",&temp);
            q.push({iii-1, temp});
        }
        
        while(!q.empty())
        {
            int current_importance = q.front().x;
            int current_index = q.front().index;
            int flag=0;
            q.pop();
            
            int ss = q.size();
            
            
            for(int j = 0; j<ss; j++)
            {
                int temp_imp = q.front().x;
                int temp_index = q.front().index;
                q.pop();
                
                if(temp_imp > current_importance) flag=1;
                q.push({temp_index, temp_imp});
            }
            
            if(flag==1)
                q.push({current_index, current_importance});
                
            else if(flag==0)
            {
                arr[current_index] = cnt++;
            }

        
        }
        printf("%d\n", arr[M]);
        
    }
    
    return 0;
}