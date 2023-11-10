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
		long long n, m;
		cin>>n>>m;
		vector<long long> v(m), g;
		for(long long i=0;i<m;i++) {
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		
		for(long long i=0;i<m-1;i++) {
			if(v[i+1] - v[i] - 1){
				g.push_back(v[i+1] - v[i] - 1);
			}
		}

		if(n - v[m-1] + v[0] - 1){
			g.push_back(n - v[m-1] + v[0] - 1);
		}
		sort(g.begin(),g.end(), greater<long long>());
		log(g);
		long long count = 0;
		for(long long i=0;i<g.size();i++) {
			if(g[i] > (4L * (i + 1) - 3)) {
				count += (g[i] - (4L * (i + 1) - 3));
			} else if(g[i] == (4L * (i + 1) - 3)) {
				count += 1;
			}
			else{
				break;
			}
		}
		cout<<(n - count)<<"\n";
	}
}