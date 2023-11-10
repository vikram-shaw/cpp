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
		vector<int> v(n + 1);
		for(int i=0;i<n-1;i++) {
			int x;
			cin>>x;
			v[x]++;
		}
		sort(v.rbegin(),v.rend());
		while(!v.back())
			v.pop_back();
		v.push_back(1);
		int result = n = v.size();
		priority_queue<int> q;
		for(int i=0;i<=n;i++) {
			v[i] -= (n - i);
			if(v[i] > 0)
				q.push(v[i]);
		}
		int sec = 0;
		while(!q.empty() && sec < q.top()) {
			int top = q.top();
			q.pop();
			sec++;
			q.push(top - 1);
		}
		cout<<result + sec<<"\n";
	}
}