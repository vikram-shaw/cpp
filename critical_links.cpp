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

void dfs(int c, int p, vector<int>& tin, vector<int>& low, vector<bool>& visited, vector<vector<int>>& adj, int& timer, vector<pair<int,int>>& result) {
	visited[c] = true;
	tin[c] = low[c] = timer++;
	for(int ch: adj[c]) {
		if(ch == p) {
			continue;
		}
		if(visited[ch]) {
			low[c] = min(low[c], tin[ch]);
		} else {
			dfs(ch, c, tin, low, visited, adj, timer, result);
			low[c] = min(low[c], low[ch]);
			if(tin[c] < low[ch]) {
				result.push_back({c,ch});
			}
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("log.txt","w",stderr);
	#endif
	int n;
	while(scanf("%d",&n) == 1) {
		int t = n;
		vector<vector<int>> adj(n);
		while(t--) {
			int curr, next;
			string nxt;
			cin>>curr>>nxt;
			next = stoi(nxt.substr(1,nxt.length()-2));
			for(int i=0;i<next;i++) {
				int to;
				cin>>to;
				adj[curr].push_back(to);
			}
		}
		log(adj);
		vector<bool> visited(n);
		vector<int> tin(n), low(n);
		vector<pair<int,int>> result;
		int timer = 0;
		for(int i=0;i<n;i++) {
			if(!visited[i]) {
				dfs(i,-1, tin, low, visited, adj, timer, result);
			}
		}
		cout<<result.size()<<" cirtical links\n";
		for(pair<int,int> p: result) {
			cout<<p.first<<" - "<<p.second<<"\n";
		}
		cout<<"\n";
	}
}