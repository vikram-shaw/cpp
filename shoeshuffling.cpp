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

void change(vector<int>& v, int i, int j) {
	for(int c=i;c<j-1;c++) {
		v[c] = c + 2;
	}
	v[j-1] = i + 1;
}

void solve(vector<long long>& v) {
	int i = 0, j = 0, l = v.size();
	vector<int> r(l);
	while(i < l && j < l) {
		j = i + 1;
		while(j < l && v[i] == v[j]) {
			j++;
		}
		if(i + 1 == j) {
			log(i);
			log(j);
			cout<<"-1\n";
			return;
		}
		change(r,i,j);
		i = j;
	}
	for(int x: r) {
		cout<<x<<" ";
	}
	cout<<"\n";
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("error.txt","w",stderr);
	#endif
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<long long> v(n);
		for(int i=0;i<n;i++) {
			cin>>v[i];
		}
		solve(v);
	}
}