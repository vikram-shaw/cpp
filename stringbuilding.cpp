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
	set<int> st;
	for(int i=0;i<=25;i++) {
		for(int j=0;j<=17;j++) {
			st.insert(i * 2 + 3 * j);
		}
	}
	log(st);
	int t;
	cin>>t;
	while(t--) {
		string s;
		cin>>s;
		int count = 0;
		char prev = s[0];
		bool isPossible = true;
		int n = s.length();
		for(int i=0;i<n;i++) {
			if(prev == s[i]) {
				count++;
			}
			else {
				if(!st.count(count)) {
					isPossible = false;
					break;
				}
				count = 1;
			}
			prev = s[i];
		}
		if(!st.count(count)) {
			isPossible = false;
		}
		puts(isPossible ? "YES": "NO");
	}
}