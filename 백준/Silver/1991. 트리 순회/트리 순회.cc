#include <stdio.h>
int root = 'A';
int lt[10001];
int rt[10001];

void f1(int x)
{
    if(x == '.') return;
    printf("%c",x);
    f1(lt[x]);
    f1(rt[x]);
}
void f2(int x)
{
    if(x == '.')
    {
        return;
    }
    f2(lt[x]);
    printf("%c",x);
    f2(rt[x]);
}
void f3(int x)
{
    if(x == '.')
    {
        return;
    }
    f3(lt[x]);
    f3(rt[x]);
    printf("%c",x);
    
}

int main()
{
    int N;
    scanf("%d\n",&N);
    for(int i = 1; i<=N; i++)
    {
        
        char a,b,c;
        scanf("%c %c %c\n",&a,&b,&c);
        lt[a] = b;
        rt[a] = c;
    }
    f1(65);
    printf("\n");
    f2(65);
    printf("\n");
    f3(65);

    return 0;
}