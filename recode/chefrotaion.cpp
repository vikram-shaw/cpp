#include<bits/stdc++.h>
using namespace std;

int is_insearsing(vector<int>& v)
{
	int mx = 0;
	int pre = 0;
	bool y = false;
	for(int i=1;i<v.size();i++)
	{
		if(v[i-1] >= v[i])
		{
			mx = max(mx,i + 1 - pre);
			pre = i;
			y = true;
		}
	}
	if(y)
		return mx;
	return -1;
}

void solve()
{
	int n;
	cin>>n;
	vector<int> v(n);
	
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
		//printf("Case #%d: ",t);
        solve();
	}
}
