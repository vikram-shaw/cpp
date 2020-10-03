#include<bits/stdc++.h>
using namespace std;

int dp[30];

int cal(int n)
{
    if(n==1)
        return 1;
    if(dp[n]!=0)
        return dp[n];
    int res = 0;
    for(int i=1;i<=n/2;i++)
    {
        res+=cal(i)*cal(n-i);
    }
    return dp[n] = res;
}

int main()
{
    int n;
    cin>>n;
    cout<<cal(n)<<'\n';
}