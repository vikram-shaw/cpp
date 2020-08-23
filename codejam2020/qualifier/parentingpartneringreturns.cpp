#include<bits/stdc++.h>
using namespace std;

void solve(int t)
{
    printf("Case #%d: ",t);
	int n;
	scanf("%d",&n);
	vector<tuple<int,int,int>> swipline;
	string result(n,'N');
	for(int i=0;i<n;i++)
	{
		int st,ed;
		scanf("%d%d",&st,&ed);
		swipline.push_back({st,1,i});
		swipline.push_back({ed,-1,i});
	}
	sort(swipline.begin(),swipline.end());
	int c = 0;
	bool impossible = false;
	for(tuple<int,int,int> p: swipline)
	{
		if(get<1>(p) == 1)
		{
			c++;
			if(c==3)
			{
				impossible = true;
				break;
			}
		}
		else
			c--;
	}
	if(impossible)
		puts("IMPOSSIBLE");
	else
	{
		set<pair<int,char>> set;
		bool j = true, c = true;
		for(tuple<int,int,int>& p: swipline)
		{
			if(get<1>(p) == 1)
			{
				if(j)
				{
					result[get<2>(p)] = 'J';
					j = false;
					set.insert({get<2>(p),'j'});
				}
				else
				{
					result[get<2>(p)] = 'C';
					c = false;
					set.insert({get<2>(p),'c'});
				}
			}
			else
			{
				if(set.find({get<2>(p),'j'}) != set.end())
				{
					j = true;
					set.erase({get<2>(p),'j'});
				}
				else
				{
					c = true;
					set.erase({get<2>(p),'c'});
				}
			}
		}
		cout<<result<<endl;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        solve(i);
}
