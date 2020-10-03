#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> v(n,INF);
	vector<int> rd(n);
	v[0]=0;
	for(int &x: rd)
		scanf("%d",&x);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<=i+2;j++)
			if(j<n)
				v[j] = min(v[j],v[i]+abs(rd[j]-rd[i]));
	cout<<v[n-1]<<'\n';
}
