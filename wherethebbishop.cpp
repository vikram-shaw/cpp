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
		vector<string> v(8);
		for(int i=0;i<8;i++) {
			cin>>v[i];
		}
		for(int i=0;i<8;i++) {
			for(int j=0;j<8;j++) {
				if(v[i][j] == '#' && i > 0 && i < 7 && j > 0 && j < 7) {
					if(v[i-1][j-1] == '#' && v[i+1][j-1] == '#' && v[i-1][j+1] == '#' && v[i+1][j+1] == '#') {
						cout<<(i + 1)<<" "<<(j + 1)<<"\n";
					}
				}
			}
		}
	}
}