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

vector<long long> extract(long long n) {
	vector<long long> digits;
	while(n) {
		digits.push_back(n % 10LL);
		n /= 10LL;
	}
	return digits;
}

long long solve(long long n, long long x) {
	queue<pair<long long, long long>> q;
	q.push({x,0});
	set<long long> s;
	long long result = 0x3f3f3f3f;
	long long counter = 50000;
	s.insert(x);
	 bool found = false;
	while(!q.empty() && counter--) {
		pair<long long, long long> front = q.front();
		q.pop();
		vector<long long> digits = extract(front.first);
		// log(front);
		if(digits.size() > n)
			continue;
		if(digits.size() == n) {
			result = min(result, front.second);
			found = true;
		}
		for(long long curr: digits) {
			if(curr > 1 && !s.count(curr * front.first)) {
				q.push({curr * front.first, front.second + 1});
				s.insert(curr * front.first);
			}
		}
	}
	return found ? result : -1;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("error.txt","w",stderr);
	#endif
	long long n, x;
	cin>>n>>x;
	cout<<solve(n,x)<<"\n";
}
