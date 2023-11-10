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
		vector<pair<int,int>> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i].first;
		for(int i=0;i<n;i++)
			cin>>a[i].second;
		vector<pair<int,int>> b(a.begin(),a.end());
		sort(a.begin(),a.end());
		bool isPossible = true;
		for(int i=1;i<n;i++) {
			if(a[i-1].second > a[i].second) {
				isPossible = false;
				break;
			}
		}
		if(!isPossible) {
			puts("-1");
			continue;
		}
		log(a);
		log(b);
		vector<pair<int,int>> result;
		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				if(a[i] >= b[j]) {
					result.push_back({i+1, j+1});
					swap(b[j],b[i]);
				}
			}
		}
		cout<<result.size()<<"\n";
		for(pair<int,int> p: result) {
			cout<<p.first<<" "<<p.second<<"\n";
		}
	}
}