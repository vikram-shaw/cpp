#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<long> rgb(3);
		cin>>rgb[0]>>rgb[1]>>rgb[2];
		sort(rgb.begin(),rgb.end());
		if(rgb[2]-1>rgb[1]+rgb[0])
			cout<<"No\n";
		else
			cout<<"Yes\n";
	}
}
