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

class Trie {
    public: 
    Trie *zero, *one;
};

void create(Trie *root, int num) {
	for(int i=31;i>=0;i--) {
		if((num>>i)&1) {
			if(root->one == NULL) {
				root->one = new Trie();
			}
			root = root->one;
		} else {
			if(root->zero == NULL) {
				root->zero = new Trie();
			}
			root = root->zero;
		}
	}
}

int form(Trie* left, Trie* right, int i) {
	if(left && right) {
		int first = 0, second = 0, third = 0, forth = 0;
		if(right->zero && right->one) {
			first = (1<<i) + form(left->zero, left->one, i - 1);
		}
		if(left->zero && left->one) {
			second = form(left->zero, left->one, i - 1);
		}
		if(left->zero && right->one) {
			third = (1<<i) + form(left->zero,right->one, i - 1);
		}
		if(left->one && right->zero) {
			forth = (1<<i) + form(left->one,right->zero, i - 1);
		}
		return max({first,second,third,forth});
	}

	if(left) {
		return form(left->zero, left->one, i - 1);
	}

	if(right) {
		return (1<<i) + form(right->zero, right->one, i - 1);
	}

	return 0;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("error.txt","w",stderr);
	#endif
	Trie *root = new Trie();
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		create(root,x);
	}
	int i=31;
	while(root->one == NULL) {
		root = root->zero;
		i--;
	}

	cout<<((1<<i) + form(root->zero, root->one, i - 1))<<"\n";
}