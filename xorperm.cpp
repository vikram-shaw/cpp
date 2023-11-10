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
		int n;
		cin>>n;
		if(n == 3) {
			puts("-1");
			continue;
		}
		set<int> s;
		vector<int> v(n);
		v[0] = 1;
		v[1] = 3;
		v[2] = 4;
		v[3] = 2;
		for(int i=5;i<=n;i++) {
			s.insert(i);
		}
		bool isPossible = true;
		for(int i=4;i<n;i++) {
			int xr = v[i-1] ^ v[i-2];
			int c = i + 1;
			int count = 0;
			while((xr == c || !s.count(c)) && count < n) {
				c++;
				c %= (n + 1);
				if(c == 0)
					c = 3;
				count++;
			}
			if(count == n) {
				isPossible = false;
				break;
			}
			s.erase(c);
			v[i] = c;
		}
		if(isPossible) {
			for(int x: v)
				cout<<x<<" ";
			puts("");
		} else {
			puts("-1");
		}
	}
}