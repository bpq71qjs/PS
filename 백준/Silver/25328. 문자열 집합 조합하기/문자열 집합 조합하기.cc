#include <map>
#include <string>
#include <iostream>

using namespace std;

string strings[4];
string temp;
int cnt;
map<string, int> m;
void f(int step, int k, int index, int start)
{
    if(step == k){
        m[temp]++;
        return;
    }

    for(int i=start+1;strings[index][i]!='\0';i++){
        temp += strings[index][i];
        f(step+1, k, index, i);
        temp.pop_back();
    }
    return;
}
int main()
{
    int k;
    cin>>strings[1];
    cin>>strings[2];
    cin>>strings[3];
    cin>>k;

    f(0, k, 1,-1);
    f(0,k,2,-1);
    f(0,k,3,-1);

    int flag = 0;

    for(auto &p : m){
        if(p.second >= 2) cout<<p.first<<'\n',flag=1;
    }
    if(flag==0) printf("-1");
    return 0;
}