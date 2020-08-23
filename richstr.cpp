#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

class Node{
	public:
	unordered_map<char,int> m;
};

Node tree[4*MAX];

void build(string s, int l, int r, int c)
{
	if(l == r)
	{
		tree[c].m[s[l]] = 1;
		return;
	}
	int m = (l + r)/2;
	build(s,l,m,2*c);
	build(s,m+1,r,2*c+1);
	for(char ch='a';ch<='z';ch++)
		tree[c].m[ch] = tree[2*c].m[ch] + tree[2*c+1].m[ch];
}

unordered_map<char,int> query(int lr, int rr, int l, int r, int c)
{
	if(rr < l || lr > r)
	{
		unordered_map<char,int> mp;
		return mp;
	}
	if(lr >= l && rr <= r)
		return tree[c].m;
	int m = (lr + rr)/2;
	unordered_map<char,int> lm = query(lr,m,l,r,2*c);
	unordered_map<char,int> rm = query(m+1,rr,l,r,2*c+1);
	for(char ch='a';ch<='z';ch++)
		lm[ch] += rm[ch];
	return lm;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<4*MAX;i++)
			tree[i].m.clear();
		int n,q;
		cin>>n>>q;
		string s;
		cin>>s;
		build(s,0,n-1,1);
		
		cout<<("_________start_________\n");
		for(int i=0;i<2*n;i++)
			cout<<"tree["<<i<<"] = "<<tree[i].m.size()<<'\n';
		cout<<("__________end____________\n");
		
		while(q--)
		{
			int l, r;
			cin>>l>>r;
			l--;
			r--;
			int len = r - l + 1;
			if(len >= 3)
			{
				unordered_map<char,int> mp = query(0,n-1,l,r,1);
				int mx = 0;
				for(char ch='a';ch<='z';ch++)
					mx = max(mx,mp[ch]);
				if(mx >= 2)
					cout<<("YES")<<'\n';
				else
					cout<<("NO")<<'\n';
			}
			else
				cout("NO")<<'\n';
		}
	}
}
