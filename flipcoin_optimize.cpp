#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
int tree[4*MAX],v[MAX],lazy[4*MAX];

void update(int a, int b, int l, int r, int c = 1)
{
	if(lazy[c] != 0)
	{
		tree[c] = (r-l+1)-tree[c];
		if(l != r)
		{
			lazy[2*c] = lazy[c];
			lazy[2*c+1] = lazy[c];
		}
		lazy[c] = 0;
	}
	if(l>r || l>b || r<a)
		return;
	if(a<=l && r<=b)
	{
		tree[c] = (r-l+1)-tree[c];
		if(l != r)
		{
			lazy[c*2] = lazy[c];
			lazy[c*2+1] = lazy[c];
		}
		return;
	}
	int m = (l + r)>>1;
	update(a,b,l,m,c*2);
	update(a,b,m+1,r,c*2+1);
	tree[c] = tree[c*2] + tree[c*2+1];
}

int query(int a, int b, int l, int r, int c = 1)
{
	if(l > r || r < a || l > b)
		return 0;
	if(lazy[c] != 0)
	{
		tree[c] = (r-l+1) - tree[c];
		if(l != r)
		{
			lazy[c*2] = lazy[c];
			lazy[c*2+1] = lazy[c];
		}
		lazy[c] = 0;
	}
	if(a <= l && r <= b)
		return tree[c];
	int m = (l + r)>>1;
	return query(a,b,l,m,c*2)+query(a,b,m+1,r,c*2+1);
}

int main()
{
	int n,q;
	cin>>n>>q;
	while(q--)
	{
		int t,a,b;
		cin>>t>>a>>b;
		if(t)
			cout<<query(a,b,0,n-1)<<'\n';
		else
			update(a,b,0,n-1);
	}
}
