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

bool isPalin(string s) {
	return s[0] == s[3] && s[1] == s[2];
}

string toStr(int hr, int mm) {
	if(hr < 10 && mm < 10) {
		return "0" + to_string(hr) + "0" + to_string(mm);
	}
	if(hr < 10) {
		return "0" + to_string(hr) + to_string(mm);
	}
	if(mm < 10) {
		return to_string(hr) + "0" + to_string(mm);
	}
	return to_string(hr) + to_string(mm);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("log.txt","w",stderr);
	#endif
	int t;
	cin>>t;
	while(t--) {
		string s;
		int n;
		cin>>s>>n;
		int hr = stoi(s.substr(0,2));
		int mm = stoi(s.substr(3,2));
		set<string> st;
		int ctime = 0, count = 0;
		do {
			string curr = toStr(hr,mm);
			if(st.count(curr)) {
				break;
			}
			if(isPalin(curr) && !st.count(curr)) {
				count++;
			}
			st.insert(curr);
			ctime += n;
			mm += n;
			if(mm >= 60) {
				hr += (mm / 60);
				mm -= (mm / 60) * 60;
			}
			if(hr >= 24) {
				hr = hr - 24;
			}
		} while(ctime < 210240000);
		cout<<count<<"\n";
	}
}