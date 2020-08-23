#include<bits/stdc++.h>
using namespace std;
void solve(int t)
{
    int n, b;
    scanf("%d%d",&n,&b);
    vector<int> a(n);
    for(int& r: a)
        scanf("%d",&r);
    sort(a.begin(),a.end());
    int r = 0,c = 0;
    for(int i=0;i<n;i++)
    {
        r += a[i];
        if(r > b)
            break;
        c++;
    }
    printf("Case #%d: %d\n",t,c);
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