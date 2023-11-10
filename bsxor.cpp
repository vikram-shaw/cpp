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
		int n, k;
		string s;
		cin>>n>>k>>s;
		bool isActive = true;
		vector<int> zero, one;
		for(int i=0;i<n;i++) {
			if(s[i] == '1') {
				isActive = !isActive;
				if(isActive) {
					zero.push_back(1);
				}
			}
			if(isActive) {
				int count = 0;
				while(i < n && s[i] == '0') {
					count++;
					i++;
				}
				if(count){
					zero.push_back(count);
					i--;
				}
			}
		}
		int sum = accumulate(zero.begin(),zero.end(),0);
		if(sum % 2 == 0 && zero.size() <= k &&  sum) {
			cout<<"YES\n";
			continue;
		}

		isActive = false;
		char pre = '-';
		for(int i=0;i<n;i++) {
			if(s[i] == '1') {
				isActive = !isActive;
			}
			if(pre == '0' && s[i] == '1') {
				one.push_back(1);
			}
			if(isActive && s[i] == '0') {
				pre = '0';
				continue;
			}
			if(isActive) {
				int count = 0;
				while(i < n && s[i] == '1') {
					i++;
					count++;
				}
				if(count > 1) {
					one.push_back((count + 1) / 2);
				}
				isActive = count % 2 == 0;
			}
			pre = s[i];
		}
		log(one);
		sum = accumulate(one.begin(),one.end(),0);
		if(isActive && one.size() <= k && k <= sum) {
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}
}