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

void dfs(int v, int p, vector<bool>& visited, vector<int>& tin, vector<int>& low, vector<pair<int,int>>& result, vector<vector<int>>& adj, int& timer) {
	visited[v] = true;
	tin[v] = low[v] = timer++;
	for(int c: adj[v]) {
		if(c == p) {
			continue;
		}
		if(visited[c]) {
			low[v] = min(low[v], tin[c]);
		} else {
			dfs(c, v, visited, tin, low, result, adj, timer);
			low[v] = min(low[v], low[c]);
			if(tin[v] < low[c]) {
				result.emplace_back(c,v);
			}
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("log.txt","w",stderr);
	#endif
	int t;
	cin>>t;
	for(int test=1;test<=t;test++) {
		printf("Caso #%d\n",test);
		int n, m;
		scanf("%d%d",&n,&m);
		vector<vector<int>> adj(n);
		for(int i=0;i<m;i++) {
			int x, y;
			scanf("%d%d",&x,&y);
			adj[x-1].push_back(y-1);
			adj[y-1].push_back(x-1);
		}
		vector<bool> visited(n);
		vector<int> tin(n), low(n);
		vector<pair<int,int>> result;
		int timer = 0;
		for(int i=0;i<n;i++) {
			if(!visited[i]) {
				dfs(i,-1,visited,tin,low,result,adj,timer);
			}
		}
		if(result.size()) {
			sort(result.begin(),result.end());
			printf("%d\n",result.size());
			for(int i=0;i<result.size();i++) {
				if(result[i].first < result[i].second)
					cout<<result[i].first + 1<<" "<<result[i].second + 1<<"\n";
				else
					cout<<result[i].second + 1<<" "<<result[i].first + 1<<"\n";
			}
		} else {
			puts("Sin bloqueos");
		}
	}
}