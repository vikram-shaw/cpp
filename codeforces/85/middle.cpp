#include<bits/stdc++.h>
using namespace std;

void solve()
{
	long n, x;
	cin>>n>>x;
	vector<int> data(n);
	for(int i=0;i<n;i++)
		cin>>data[i];
	sort(data.begin(),data.end(),[](const int& a,const int& b){
		return a>b;
	});
	int res = 0;
	double sm = 0.0;
	for(int i=0;i<n;i++)
	{
		sm += data[i];
		if(sm/(i+1) >= x)
			res++;
		else
			break;
	}
	cout<<res<<endl;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
		//printf("Case #%d: ",t);
        solve();
	}
}
