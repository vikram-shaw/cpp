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
		vector<int> v(10);
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			v[x%10]++;
			if(v[x%10] > 3) {
				v[x%10] = 3;
			}
		}
		bool found = false;
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				for(int k=0;k<10;k++) {
					if(i == j && j == k && v[i] < 3) {
						continue;
					}
					if((i == j && v[i] < 2) || (i == k && v[i] < 2) || (j == k && v[j] < 2)) {
						continue;
					}
					if(v[i] && v[j] && v[k]) {
						if((i + j + k) % 10 == 3) {
							found = true;
							break;
						}
					}
				}
				if(found)
					break;
			}
			if(found)
				break;
		}
		puts(found ? "YES" : "NO");
	}
}