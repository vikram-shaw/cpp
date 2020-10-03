#include<bits/stdc++.h>
using namespace std;
void solve(int t)
{
    //printf("Case #%d: ",t);
    int n,k,p;
    scanf("%d%d%d",&n,&k,&p);
    int v[n][k+1];
    int ptr[n];
    for(int i=0;i<n;i++)
        ptr[i] = 0,v[i][k]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            scanf("%d",&v[i][j]);
        }
    }
    int r = 0,sm = 0;
    for(int i=0;i<k;i++)
    {
        int mx = 0;
        int &ref = ptr[0];
        for(int j=0;j<n;j++)
        {
            if(ptr[j]<k-1 && mx < v[j][ptr[j]])
            {
                mx = v[j][ptr[j]];
                ref = ptr[j];
            }
        }
        ref++;
        sm += mx;
        p--;
        if(p==0)
            break;
    }
    cout<<sm<<'\n';
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        solve(i);
}