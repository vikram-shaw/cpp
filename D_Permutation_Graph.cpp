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
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++) {
            int mx = a[i], mn = a[i];
            for(int j=i+1;j<n;j++) {
                mx = max(mx, a[j]);
                mn = min(mn, a[j]);
            }
            adj[mx-1].push_back(mn-1);
            adj[mn-1].push_back(mx-1);
        }

        int s = 0;

        queue<int> q;
        vector<bool> used(n);
        vector<int> d(n), p(n);
        q.push(s);
        used[s] = true;
        p[s] = -1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : adj[v]) {
                if (!used[u]) {
                    used[u] = true;
                    q.push(u);
                    d[u] = d[v] + 1;
                    p[u] = v;
                }
            }
        }

        int count = 0, c = n - 1;
        while(p[c] != -1) {
            count++;
            c = p[c];
        }
        cout<<count<<"\n";
	}
}