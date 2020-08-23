#include<bits/stdc++.h>
using namespace std;

bool com(pair<int,int>& p1, pair<int,int>& p2)
{
	if(p1.first >= p2.first && p1.second >=p2.second)
		return true;
	return false;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<pair<int,int>> path(n);
		for(int i=0;i<n;i++)
			cin>>path[i].first>>path[i].second;
		sort(path.begin(),path.end());
		pair<int,int> s{0,0};
		bool f = false;
		int i;
		for(i=1;i<n;i++)
		{
			if(path[i].first < path[i-1].first || path[i].second < path[i-1].second)
				break;
		}
		if(i==n)
		{
			cout<<"YES\n";
			for(int i=0;i<n;i++)
			{
				while(s.first < path[i].first || s.second < path[i].second)
				{
					if(s.first < path[i].first){
						s.first++;
						cout<<"R";
					}
					else if(s.second < path[i].second){
						s.second++;
						cout<<"U";
					}
				}
			}
			cout<<"\n";
		}
		else
			cout<<"NO\n";
	}
}
