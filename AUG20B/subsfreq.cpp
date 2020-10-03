#include<bits/stdc++.h>
using namespace std;

int a[500001];
const int MOD = (int)1e9+7;
map<int,int> result;
vector<int> v;

void rec(int n)
{
	if(n == -1)
	{
		map<int,int> mx;
		for(int r: v)
			mx[r]++;
		int r = 0, s = 0;
		for(pair<int,int> p: mx)
		{
			if(r < p.second)
			{
				r = p.second;
				s = p.first;
			}
		}
		result[s] = (result[s] + 1)%MOD;
		return;
	}
	rec(n-1);
	v.push_back(a[n]);
	rec(n-1);
	v.pop_back();
}

void brute()
{
	result.clear();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	rec(n-1);
	for(int i=1;i<=n;i++)
		cout<<result[i]<<' ';
	cout<<endl;
}



int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
		//printf("Case #%d: ",i);
        //solve();
        brute();
	}
}
