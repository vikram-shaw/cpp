#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second

bool inbetween(int y1, int y2, int yy)
{
	if((y1 <= yy && y2 >= yy) || (y1 >= yy && y2 <= yy))
		return true;
	return false;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		vector<pair<int,int>> p(n);
		for(int i=0;i<n;i++)
		{
			int r;
			scanf("%d",&r);
			p[i] = {i+1,r};
		}
		vector<tuple<int,int,int>> lines(q),linesx1, linesx2;
		vector<int> lx1(q),lx2(q);
		map<tuple<int,int,int>,int> result;
		for(int i=0;i<q;i++)
		{
			int x1,x2,yy;
			scanf("%d%d%d",&x1,&x2,&yy);
			lines[i] = make_tuple(x1,x2,yy);
			result[lines[i]] = 0;
		}
		linesx2 = linesx1 = lines;
		sort(linesx1.begin(),linesx1.end(),[](const tuple<int,int,int>& p1, const tuple<int,int,int>& p2){
			return get<0>(p1) < get<0>(p2);
		});
		for(int i=0;i<q;i++)
			lx1[i] = get<0>(linesx1[i]);
		sort(linesx2.begin(),linesx2.end(),[](const tuple<int,int,int>& p1, const tuple<int,int,int>& p2){
			return get<1>(p1) < get<1>(p2);
		});
		for(int i=0;i<q;i++)
			lx2[i] = get<1>(linesx2[i]);
		set<tuple<int,int,int>> curr;
		int ll = 0, lr = 0;
		for(int x=1;x<=n;x++)
		{
			while(lx1[ll] == x)
			{
				curr.insert(linesx1[ll]);
				ll++;
			}
			while(lx2[lr] == x)
			{
				curr.erase(linesx2[lr]);
				lr++;
			}
			for(tuple<int,int,int> c: curr)
			{
				if(inbetween(p[x-1].y,p[x].y,get<2>(c)))
					result[c]++;
			}
		}
		for(tuple<int,int,int> c: lines)
			cout<<result[c]<<'\n';
	}
}
