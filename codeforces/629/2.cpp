#include<bits/stdc++.h>
using namespace std;

void solve()
{
	long long n,k;
	cin>>n>>k;
	string s(n,'a');
	long long p = (sqrt(8LL*k+1)+1)/2;
	if(!(1LL*p*(p-1)/2 < k && 1LL*p*(p+1)/2 >= k))
		p--;
	s[n-p-1] = 'b';
	s[n - (k - 1LL*p*(p-1)/2)] = 'b';
	cout<<s<<endl;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        solve();
}
