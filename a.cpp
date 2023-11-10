/*******************
 ****VIKRAM SHAW****
********************/
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define log(x) cerr << #x << " "; _print(x); cerr << endl;
#endif
#ifdef ONLINE_JUDGE
	#define log(x)
#endif

template<typename T> void _print(T argument) { cerr << argument; }
template<typename K, typename V> void _print(pair<K,V> x) { cerr << "{ " << x.first << " -> " << x.second << " }"; }
template<class T> void _print(vector<T> v) { cerr << "[ "; for(T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(set<T> v) { cerr << "[ "; for(T i: v) { _print(i); cerr << " "; } cerr << "]"; }
template<class K, class V> void _print(map<K,V> v) { cerr << "[ "; for(pair<K,V> i: v) { _print(i); cerr << " "; } cerr << "]";}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("error.txt","w",stderr);
	#endif
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<vector<long long>> m(26,vector<long long>(26,0));
		for(int i=0;i<n;i++) {
			string s;
			cin>>s;
			m[s[0]-'a'][s[1]-'a']++;
		}
		long long count = 0LL;
		for(int i=0;i<26;i++) {
			for(int j=0;j<26;j++) {
				if(m[i][j] == 0)
					continue;
				for(int k=i+1;k<26;k++) {
					if(m[k][j] == 0)
						continue;
					count += (m[i][j] * m[k][j]);
				}
				for(int k=j+1;k<26;k++) {
					if(m[i][k] == 0)
						continue;
					count += (m[i][j] * m[i][k]);
				}
			}
		}
		cout<<count<<"\n";
	}
}