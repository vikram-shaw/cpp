#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>& v, int l1, int r1, int l2, int r2)
{
	int c = 0,i=l1,j=l2,k=l1;
	vector<int> mer(r2+1);
	while(i<=r1 && j<=r2)
	{
		if(v[i] <= v[j])
		{
			mer[k++] = v[i++];
		}
		else
		{
			c += (r1 - i + 1);
			mer[k++] = v[j++];
		}
	}
	while(i<=r1)
		mer[k++] = v[i++];
	while(j<=r2)
		mer[k++] = v[j++];
	for(i=l1;i<=r2;i++)
		v[i] = mer[i];
	return c;
}

int merge_sort(vector<int>& v, int l ,int r)
{
	if(l >= r)
		return 0;
	int m = (l + r)/2;
	int ll = merge_sort(v,l,m);
	int rr = merge_sort(v,m+1,r);
	int c = merge(v,l,m,m+1,r);
	return ll + rr + c;
}

int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &x: v)
		scanf("%d",&x);
	cout<<merge_sort(v,0,n-1)<<endl;
}
