#include<bits/stdc++.h>
#define UP 1
#define DOWN -1
#define INF 0x3f3f3f3f
using namespace std;
set<pair<int,int>> result;

int dist(pair<int,int>& p1,pair<int,int>& p2, pair<int,int>& p)
{
	return (p.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (p.first - p1.first);
}

void quickhull(vector<pair<int,int>>& points, pair<int,int>& p1, pair<int,int>& p2)
{
	bool atleastonepoint = false;
	int mx = -0x3f3f3f3f, mn = 0x3f3f3f3f;
	pair<int,int> lp, rp;
	vector<pair<int,int>> left,right;
	for(pair<int,int> point: points)
	{
		int d = dist(p1,p2,point);
		if(d > 0)
		{
			left.push_back(point);
			if(mx < d)
			{
				mn = d;
				lp = point;
			}
		}
		else if(d < 0)
		{
			right.push_back(point);
			if(mx > d)
			{
				mx = d;
				rp = point;
			}
		}
	}
	cout<<"\n("<<p1.first<<","<<p1.second<<")"<<"("<<p2.first<<","<<p2.second<<")\nleft: ";
	for(pair<int,int> p: left)
	{
		cout<<"("<<p.first<<","<<p.second<<")";
	}
	cout<<"\nright: ";
	for(pair<int,int> p: right)
	{
		cout<<"("<<p.first<<","<<p.second<<")";
	}
	if(left.size()==0)
	{
		result.insert(p1);
		result.insert(p2);
		return;
	}
	else
		quickhull(left,p1,lp);
	if(right.size()==0)
	{
		result.insert(rp);
		return;
	}
	else
		quickhull(right,p2,rp);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n,r;
		cin>>n;
		vector<pair<int,int>> points(n), left,right;
		pair<int,int> p1 = {INF,INF},p2 = {-1,-1};
		for(int i=0;i<n;i++)
		{
			cin>>points[i].first>>points[i].second;
			if(p1.first >= points[i].first && p1.second >= points[i].second)
				p1 = points[i];
			if(p2.first <= points[i].first && p2.second <= points[i].second)
				p2 = points[i];
		}
		quickhull(points,p1,p2);
		for(pair<int,int> r : result)
			cout<<"("<<r.first<<","<<r.second<<")\n";
		//puts(result.size()<=r?"YES\n":"NO\n");
	}
}
