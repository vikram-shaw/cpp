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

set<long long> divisor(long long n) {
	set<long long> all;
	all.insert(1);
	if(n % 2LL == 0) {
		all.insert(2LL);
	}
	for(long long i=3;i<=sqrt(n);i++) {
		if(n % i == 0) {
			all.insert(n / i);
			all.insert(i);
		}
	}
	return all;
}
int main() {
	#ifndef ONLINE_JUDGE
		freopen("log.txt","w",stderr);
	#endif
	int t;
	cin>>t;
	while(t--) {
		long long x, y;
		cin>>x>>y;
		bool found = false;
		if(x == 1 && y == 1) {
			puts("-1");
			continue;
		}
		for(long long curr: divisor(y)) {
			long long x1 = (y / curr);
			long long y1 = curr;
			long x2 = x / 2;
			long y2 = (x + 1) / 2;
			if(x1 > y1)
				swap(x1, y1);
			if(x2 > y1 || x1 > y2) {
				cout<<x1<<" "<<y1<<"\n"<<x2<<" "<<y2<<"\n";
				found = true;
				break;
			}
		}
		if(!found) {
			puts("-1");
		}
	}
}