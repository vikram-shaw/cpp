#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,b1,b2;
        cin>>n>>b1>>b2;
        long long p1 = abs(b1 - b2) - 1;
        long long p2 = n - p1 - 2;
        long long res = 0LL;
        if(p2 > 0)
            res += p1 * (p2 - 1);
        if(p1 > 0)
            res += p2 * (p1 - 1);
        if(p1 >= 3)
            res += p1 - 2 + (p1 - 3) * (p1 - 2);
        if(p2 >= 3)
            res += p2 - 2 + (p2 - 3) * (p2 - 2);
        cout<<res<<'\n';
    }
    return 0;
}
