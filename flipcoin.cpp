#include<bits/stdc++.h>
using namespace std;
#define MAX 100001

int tree[4*MAX],v[MAX];

void update(int i, int l, int r, int c = 1)
{
	if(l == r)
	{
		tree[c] = !tree[c];
		v[c] = !v[c];
		return;
	}
	int m = (l + r)>>1;
	if(i>=l && i<=m)
		update(i,l,m,c*2);
	else
		update(i,m+1,r,c*2+1);
	tree[c] = tree[c*2] + tree[c*2+1];
}

int query(int a, int b, int l, int r, int c = 1)
{
	if(r < a || l > b)
		return 0;
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
		{
			for(int i=a;i<=b;i++)
				update(i,0,n-1);
		}
	}
}
