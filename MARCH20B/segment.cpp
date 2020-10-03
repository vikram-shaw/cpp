#include<bits/stdc++.h>
using namespace std;

void update(vector<int>& BITree,int n,int i,int x) 
{
	for(++i; i<n; i+=i&-i)
		BITree[i]+=x;
}

int getSum(vector<int>& BITree, int i) 
{
	int r = 0;
	for(; i; i-=i&-i)
		r+=BITree[i];
	return r;
}

int main()
{
	int t;
	scanf("%d\n",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		vector<int> arr(n),res(q),tree(n),lq(q),rq(q);
		for(int& x: arr)
			scanf("%d",&x);
		vector<tuple<int,int,int>> ev;
		for(int i=0;i<n-1;i++)
		{
			ev.push_back(make_tuple(min(arr[i],arr[i+1]),1,i));//add
			ev.push_back(make_tuple(max(arr[i],arr[i+1]),3,i));//remove
		}
		for(int i=0;i<q;i++)
		{
			int x1,x2,y;
			scanf("%d%d%d",&lq[i],&rq[i],&y);
			lq[i]--;
			rq[i]--;
			ev.push_back(make_tuple(y,2,i));//query
		}
		sort(ev.begin(),ev.end());
		for(tuple<int,int,int>& e: ev)
		{
			if(get<1>(e) == 1)
				update(tree,n,get<2>(e),1);
			else if(get<1>(e) == 3)
				update(tree,n,get<2>(e),-1);
			else
				res[get<2>(e)] = getSum(tree,rq[get<2>(e)]) - getSum(tree,lq[get<2>(e)]);
		}
		for(int x: res)
			printf("%d\n",x);
	}
}
