#include<bits/stdc++.h>
using namespace std;

bool inbetween(int y1, int y2, int y)
{
	return (y1 <= y && y <= y2) || (y2 <= y && y <= y1);
}

void buildmax(vector<int>& tree,vector<int>& p, int l, int r,int n)
{
	if(l == r)
	{
		tree[n] = p[l];
		return;
	}
	int m = (l + r)/2;
	buildmax(tree,p,l,m,2*n+1);
	buildmax(tree,p,m+1,r,2*n+2);
	tree[n] = max(tree[2*n+1],tree[2*n+2]);
}

void buildmin(vector<int>& tree,vector<int>& p, int l, int r,int n)
{
	if(l == r)
	{
		tree[n] = p[l];
		return;
	}
	int m = (l + r)/2;
	buildmin(tree,p,l,m,2*n+1);
	buildmin(tree,p,m+1,r,2*n+2);
	tree[n] = min(tree[2*n+1],tree[2*n+2]);
}

int querymax(vector<int>& tree,int l, int r,int lq, int rq, int n = 0)
{
	if(lq > r || rq < l)
		return INT_MIN;
	if(l >= lq && r <= rq)
		return tree[n];
	int m = (l + r)/2;
	return max(querymax(tree,l,m,lq,rq,2*n+1),querymax(tree,m+1,r,lq,rq,2*n+2));
}

int querymin(vector<int>& tree,int l, int r,int lq, int rq, int n = 0)
{
	if(lq > r || rq < l)
		return INT_MAX;
	if(l >= lq && r <= rq)
		return tree[n];
	int m = (l + r)/2;
	return min(querymin(tree,l,m,lq,rq,2*n+1),querymin(tree,m+1,r,lq,rq,2*n+2));
}

int getresult(vector<int>& treemin,vector<int>& treemax,vector<int>& p, int r,int lq, int rq,int y)
{
	if(lq > rq)
		return 0;
	int mn = querymin(treemin,0,r,lq,rq);
	int mx = querymax(treemax,0,r,lq,rq);
	if((mn < y && mx < y) || (mn > y && mx > y))
		return 0;
	if(lq + 1 == rq)
		return 1;
	int md = (lq + rq )/2;
	return getresult(treemin,treemax,p,r,lq,md,y) + getresult(treemin,treemax,p,r,md,rq,y);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		vector<int> p(n), treemax(4*n+1), treemin(4*n+1);
		for(int& y: p)
			scanf("%d",&y);
		buildmax(treemax,p,0,n-1,0);
		buildmin(treemin,p,0,n-1,0);
		while(q--)
		{
			int x1, x2, y, count = 0;
			scanf("%d%d%d",&x1,&x2,&y);
			cout<<getresult(treemin,treemax,p,n-1,x1-1,x2-1,y)<<'\n';
		}
	}
}
