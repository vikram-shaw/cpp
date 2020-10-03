#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        string s;
        int mp[150]={0};
        int smp[200005] = {0};
        cin>>n>>m>>s;
        smp[0]=m+1;
        smp[n]--;
        for(int i=0;i<m;i++)
        {
            int r;
            cin>>r;
            smp[r]--;
        }
        for(int i=1;i<=n;i++)
            smp[i]+=smp[i-1];
        for(int i=0;i<n;i++)
            mp[s[i]]+=smp[i];
        for(int c='a';c<='z';c++)
            cout<<mp[c]<<' ';
        cout<<'\n';
    }
    return 0;
}