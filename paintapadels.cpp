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
		if(n % 3 == 0) {
			cout<<(n / 3) <<" "<<(n / 3 + 1)<<" "<<(n / 3 - 1)<<"\n";
		} else if(n % 3 == 1) {
			cout<<(n / 3) <<" "<<(n / 3 + 2)<<" "<<(n / 3 - 1)<<"\n";
		} else {
			cout<<(n / 3 + 1) <<" "<<(n / 3 + 2)<<" "<<(n / 3 - 1)<<"\n";
		}
	}
}
