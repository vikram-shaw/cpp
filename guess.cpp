#include<bits/stdc++.h>
using namespace std;
int main()
{
	int l = 1 , r = 1000000;
	while(l<r){
		int m = (l + r + 1)/2;
		cout<<m<<endl;
		string s;
		cin>>s;
		if(s == "<")
			r = m - 1;
		else
			l = m;
	}
	cout<<"! "<<l<<endl;
}
