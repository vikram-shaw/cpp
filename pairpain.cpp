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
		long long n, result = 0LL, count = 0;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++) {
			cin>>a[i];
		}
		// for(int i=0;i<n;i++) {
		// 	for(int j=i+1;j<n;j++) {
		// 		if(a[i]+a[j] >= a[i]*a[j]){
		// 			count++;
		// 			log(a[i]);
		// 			log(a[j]);
		// 		}
		// 	}
		// }
		// cout<<count<<"\n";
		vector<int> m(n+1);
		long long count2 = 0;
		for(int i=n-1;i>=0;i--) {
			if(a[i] == 1) {
				m[i] = m[i+1] + 1;
			}else {
				if(a[i] == 2)
					count2++;
				m[i] = m[i+1];
			}
		}

		for(int i=0;i<n;i++) {
			if(a[i] == 1) {
				result += (n - i -1);
			}else {
				result += m[i];
			}
		}
		cout<<result + ((count2-1) * count2)/2<<"\n";
	}
}
