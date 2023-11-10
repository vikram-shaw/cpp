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

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int leftdistance(char c) {
	int count = 0;
	while(c >= 'a') {
		if(isVowel(c))
			return count;
		count++;
		c--;
	}
	return 0x3f3f3f3f;
}

int rightdistance(char c) {
	int count = 0;
	while(c <= 'u') {
		if(isVowel(c))
			return count;
		count++;
		c++;
	}
	return 0x3f3f3f3f;	
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("error.txt","w",stderr);
	#endif
	int t;
	cin>>t;
	while(t--) {
		int n;
		string s;
		cin>>n>>s;
		long long count = 1;
		for(char c: s) {
			int left = leftdistance(c);
			int right = rightdistance(c);
			log(c);
			log(left);
			log(right);
			if(left == right && left != 0)
				count <<= 1LL;
			count %= 1000000007;
		}
		cout<<count<<"\n";
	}
}