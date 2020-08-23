#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int count = 0;
	for(int i=1;i<=10000;i++)
	{
		int x = i;
		int nm = 1;
		bool continuer = false;
		while(x != 0)
		{
			if(x%10 == 1)
				continuer = true;
			nm*=x%10;
			x/=10;
		}
		if(continuer)
			continue;
		if(nm == n)
			count++;
	}
	cout<<count<<'\n';
}
