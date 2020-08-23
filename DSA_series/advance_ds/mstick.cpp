#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 1000000;
int treemx[MAX], treemn[MAX], a[MAX], n;

int constructmn(int l,int r, int c)
{
	if(l > r)
		return INF;
	if(l == r)
		return treemn[c] = a[l];
	int m = (l + r) / 2;
	treemn[2*c+1] = constructmn(l,m,2*c+1);
	treemn[2*c+2] = constructmn(m+1,r,2*c+2);
	return treemn[c] = min(treemn[2*c+1],treemn[2*c+2]);
}

int constructmx(int l, int r, int c)
{
	if(l > r)
		return 0;
	if(l == r)
		return treemx[c] = a[l];
	int m = (l + r) / 2;
	treemx[2*c+1] = constructmx(l,m,2*c+1);
	treemx[2*c+2] = constructmx(m+1,r,2*c+2);
	return treemx[c] = max(treemx[2*c+1],treemx[2*c+2]);
}

int querymn(int lq, int rq, int c, int l, int r)
{
	if(lq > r || rq < l)
		return INF;
	if(l >= lq && r <= rq)
		return treemn[c];
	int m = (l + r) / 2;
	return min(querymn(lq, rq, 2*c+1, l, m),querymn(lq, rq, 2*c+2, m+1, r));
}

int querymx(int lq, int rq, int c, int l, int r)
{
	if(lq > r || rq < l)
		return 0;
	if(l >= lq && r <= rq)
		return treemx[c];
	int m = (l + r) / 2;
	return max(querymx(lq, rq, 2*c+1,l,m),querymx(lq, rq, 2*c+2,m+1,r));
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	constructmn(0,n-1,0);
	constructmx(0,n-1,0);
	int q;
	cin>>q;
	while(q--)
	{
		int l, r;
		cin>>l>>r;
		int first = querymn(l,r,0,0,n-1);
		int second = querymx(l,r,0,0,n-1);
		int third = querymx(0,l-1,0,0,n-1);
		int forth = querymx(r+1,n-1,0,0,n-1);
		double res = first + max((second - first)/2.0,(double)max(third,forth));
		printf("%.1f\n",res);
	}
}
