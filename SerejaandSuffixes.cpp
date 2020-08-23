#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i;
    #define DEBUG 0
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
    #endif
    cin>>n>>m;
    int a[n+1],ans[n+1],read;
    map<int,int> mp;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    for(i=1;i<=n;i++)
    {
        ans[i]=mp.size();
        mp[a[i]]--;
        if(mp[a[i]]==0)
            mp.erase(a[i]);
    }
    while(m--){
        int p;
        cin>>p;
        cout<<ans[p]<<'\n';
    }
}