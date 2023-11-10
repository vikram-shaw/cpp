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
		string s;
		cin>>n>>s;
		s = 'W' + s;
		s.push_back('W');

		int countR = 0, countB = 0;
		bool isPossible = true;
		log(s);
		for(int i=0;i<=n+1;i++) {
			if(s[i] == 'W') {
				int tr = countR;
				int tb = countB;
				countB = 0, countR = 0;
				if(tr == 0 && tb == 0)
					continue;
				if(tb > 0 && tr > 0)
					continue;
				isPossible = false;
				break;
			}
			else {
				if(s[i] == 'R')
					countR++;
				else
					countB++;
			}
		}
		puts(isPossible ? "YES" : "NO");
	}
}