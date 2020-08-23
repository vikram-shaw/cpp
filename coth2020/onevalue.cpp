#include<bits/stdc++.h>
using namespace std;

int b[205];

int rec(int n, int m)
{
	if(n == m)
		return 0;

}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>b[i];
	cout<<rec(0,n-1)<<'\n';
}
