#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int hh,mm;
		cin>>hh>>mm;
		mm+=hh*60;
		int tot = 24*60;
		cout<<max(0,tot-mm)<<'\n';
	}
}
