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
		int n, m, k;
        cin>>n>>m;
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        cin>>k;
        vector<int> b(k);
        for(int i=0;i<k;i++) {
            cin>>b[i];
        }
        vector<pair<int,long long>> a1{{0,0}}, b1{{0,0}};
        for(int x: a) {
            long long curr = 1LL;
            while(x % m == 0) {
                curr *= m;
                x /= m;
            }
            if(a1.back().first == x) {
                a1.back().second += curr;
            } else {
                a1.emplace_back(x,curr);
            }
        }
        
        for(int x: b) {
            int curr = 1LL;
            while(x % m == 0) {
                curr *= m;
                x /= m;
            }
            if(b1.back().first == x) {
                b1.back().second += curr;
            } else {
                b1.emplace_back(x,curr);
            }
        }
        puts(a1 == b1 ? "Yes": "No");
	}
}