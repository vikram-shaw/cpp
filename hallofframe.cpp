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
		int x;
		string s;
		cin>>x>>s;
		bool found = false;
		int lCount = 0, rCount = 0;
		int lrPosition = -1;
		for(int i=0;i<s.length()-1;i++) {
			if(s[i] == 'R' && s[i+1] == 'L') {
				found = true;
				break;
			}
			if(s[i] == 'L' && s[i+1] == 'R') {
				lrPosition = i;
				break;
			}
			if(s[i] == 'L')
				lCount++;
			if(s[i] == 'R')
				rCount++;
		}
		s[s.length()-1] == 'L' ? lCount++: rCount++;
		if(lCount == s.length() || rCount == s.length()) {
			puts("-1");
			continue;
		}
		if(found) {
			puts("0");
			continue;
		}
		assert(lrPosition != -1);
		cout<<lrPosition + 1<<"\n";
	}
}