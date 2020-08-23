#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long n,s;
		cin>>n>>s;
		long arr[n],total = 0;
		for(int i=0;i<n;i++)
			cin>>arr[i],total+=arr[i];
		if(total<=s){
			cout<<"0\n";
			continue;
		}
		sort(arr,arr+n);
		int count = 0,i=n-1;
		while(total>s){
			total-=arr[i--];
			count++;
		}
		cout<<count<<'\n';
	}
}
