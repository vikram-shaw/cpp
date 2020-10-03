#include<bits/stdc++.h>
using namespace std;
/*
1
2 2020
1 2420
101
*/
bool isleap(int n)
{
	return n%400==0 || n%4==0 && n%100!=0;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<string> day = {"sun","mon","tue","wed","thru","fri","sat"};
		int m1,y1,m2,y2;
		scanf("%d%d%d%d",&m1,&y1,&m2,&y2);
		if(m1>2)
			y1++;
		if(m2<2)
			y2--;
		int res = 101*((y2-y1)/400);
		int rem = (y2-y1)%400;
		y1%=400;
		y2 = y1 + rem;
		int curr = 2;
		int count = 0;
		for(int i=0;i<=y2;i++)
		{
			bool leap = isleap(i);
			if(i>=y1 && i<=y2)
			{
				if(curr==6)
				{
					count++;
					cout<<day[curr]<<'\n';
				}
				else if(curr==0 && !leap)
				{
					count++;
					cout<<day[curr]<<'\n';
				}
			}
			if(leap)
				curr++;
			curr++;
			curr = curr % 7;
		}
		printf("%d\n",count+res);
	}
	/*vector<string> day = {"sun","mon","tue","wed","thru","fri","sat"};
	int curr = 1;
	int count = 0;
	for(int i=0;i<400;i++)
	{
		if(isleap(i))
			curr++;
		curr++;
		curr = curr % 7;
		if(curr==6)
			count++;
		else if(curr==0 && !isleap(i))
			count++;
	}
	cout<<count<<'\n';*/
}
