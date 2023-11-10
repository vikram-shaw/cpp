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
		freopen("log.txt","w",stderr);
	#endif
	int t;
	cin>>t;
	while(t--) {
		int n, m;
		string s1, s2;
		cin>>n>>m>>s1>>s2;
		map<char,int> m1, m2;
		for(char c: s1){
			m1[c]++;
		}
		for(char c: s2){
			m2[c]++;
		}
		if(m1['0'] < m2['0'] || m1['1'] < m2['1']) {
			puts("NO");
			continue;
		}
		int i = n - 1, j = m - 1;
		while(i >= 0 && j >= 0) {
			if(s1[i] == s2[j]) {
				i--;
				j--;
			} else {
				break;
			}
		}
		puts(j < 1 ? "YES" : "NO");
	}
}