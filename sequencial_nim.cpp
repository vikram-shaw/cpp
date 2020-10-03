#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	int even = 0, odd = 0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(x%2)
			odd++;
		else
			even++;
	}
	if(even%2==0 && odd%2==0)
		puts("Second");
	else if(even%2==0 && odd%2)
		puts("First");
	else if(even%2 && odd%2==0)
		puts("Second");
	else
		puts("First");
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
		//printf("Case #%d: ",i);
        solve();
	}
}
