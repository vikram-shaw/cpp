#include<bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9+7;
int fact[100001];
int inv[100001];

int modPow(int n,int a)
{
    if(a==1)
        return n;
    if(a%2)
        return (n*modPow(n,a-1))%MOD;
    int res = modPow(n,a/2);
    return (res%MOD*res%MOD)%MOD;
}

void calculate_fact()
{
    fact[0] = inv[0] = 1;
    for(int i=1;i<100001;i++)
    {
        fact[i] = (fact[i-1]%MOD*i)%MOD;
        inv[i] = modPow(fact[i],MOD-2);
    }
}

int main()
{
    calculate_fact();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        int countA0 = 0,countB0 = 0,countA1 = 0, countB1 = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i]=='0')
                countA0++;
            else
                countA1++;
            if(b[i]=='0')
                countB0++;
            else
                countB1++;
        }
        cout<<fact[n]*fact[n]/fact[countA0]/fact[countA1]/fact[countB0]/fact[countB1]<<'\n';
    }
}