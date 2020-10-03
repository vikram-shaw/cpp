#include<bits/stdc++.h>
const int MOD = (int)1e9+7;
using namespace std;

void solve()
{
	int n;
	scanf("%d",&n);
	vector<long> v(n);
	for(long& x: v)
		scanf("%ld",&x);
	sort(v.begin(),v.end(),[](const long& a1,const long& a2)->bool{
		return a1 > a2;
	});
	long result = 0;
	for(int i=0;i<n;i++){
		if(v[i] - i > 0){
			result += v[i] - i;
			result = result % MOD;
		}
		else
			break;
	}
	printf("%ld\n",result);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        solve();
}
