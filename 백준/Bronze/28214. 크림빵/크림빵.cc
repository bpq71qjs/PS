#include <stdio.h>

long long int N,K,P;
int arr[2501];

int main()
{
    scanf("%lld %lld %lld",&N,&K,&P);
    for(int i = 1; i<=N*K;i++){
        scanf("%d",&arr[i]);
    }
    
    long long int C = 0;
    long long int ans = 0;
    
    
    for(long long int i=1; i<=N*K;i++){
        if (arr[i]==0) C++;
        
        if(i%K==0){
            if(C < P) ans++;
            C=0;
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}