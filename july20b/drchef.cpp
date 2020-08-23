#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n, x;
	cin>>n>>x;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	int pos = upper_bound(v.begin(),v.end(),x)-v.begin();
	cout<<pos<<" "<<v[pos]<<endl;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
		//printf("Case #%d: ",i);
        solve();
	}
}
