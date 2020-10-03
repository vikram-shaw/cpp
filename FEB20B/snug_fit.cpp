#include<bits/stdc++.h>
using namespace std;
void read(vector<int>& array)
{
	for(int &x: array)
		scanf("%d",&x);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> A(n),B(n);
		read(A);
		read(B);
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		long result = 0L;
		for(int i=0;i<n;i++)
			result+=min(A[i],B[i]);
		printf("%ld\n",result);
	}
}
