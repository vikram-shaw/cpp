#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	long total = 0;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		vector<char> row = {'A','B','C','D'};
		vector<int> col = {3,6,9,12};
		map<pair<char,int>,int> mp;
		for(int i=0;i<n;i++)
		{
			char m;
			int t;
			cin>>m>>t;
			mp[{m,t}]++;
		}
		int res = -0x3f3f3f3f;
		do{
			vector<int> money = {25,50,75,100};
			do{
				int tem = mp[{row[0],col[0]}]*money[0]+mp[{row[1],col[1]}]*money[1]+mp[{row[2],col[2]}]*money[2]+mp[{row[3],col[3]}]*money[3];
				if(mp[{row[0],col[0]}]==0)
					tem-=100;
				if(mp[{row[1],col[1]}]==0)
					tem-=100;
				if(mp[{row[2],col[2]}]==0)
					tem-=100;
				if(mp[{row[3],col[3]}]==0)
					tem-=100;
				res = max(res,tem);
			}while(next_permutation(money.begin(),money.end()));
		}while(next_permutation(row.begin(),row.end()));
		printf("%d\n",res);
		total+=res;
	}
	printf("%ld\n",total);
}
