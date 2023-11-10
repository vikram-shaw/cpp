#include<bits/stdc++.h>
using namespace std;

int goodString (int N, int Q, string S, vector<int> arr, vector<vector<int> > ranges) {
   // Write your code here
   vector<pair<int,int>> merged;
   sort(ranges.begin(),ranges.end(),[&](vector<int>&a, vector<int>&b){
       if(a[0] == b[0])
        return a[1] < b[1];
       return a[0] < b[0];
   });
   merged.push_back({ranges[0][0],ranges[0][1]});
   for(int i=1;i<Q;i++) {
       if(merged.back().second >= ranges[i][0]) {
           merged.back().second = max(merged.back().second, ranges[i][1]);
       }
   }
//    for(int i=0;i<merged.size();i++) {
//        cout<<merged[i].first<<" "<<merged[i].second<<"\n";
//    }
    vector<int> index(N + 1);
    for(int i=0;i<N;i++) {
        index[arr[i]-1] = i;
    }
    int mx = 0;
    for(int i=0;i<merged.size();i++) {
        map<char,vector<int>> m;
        for(int j=merged[i].first; j<=merged[i].second;j++) {
            m[S[j-1]].push_back(j - 1);
        }
        for(auto p: m) {
            if(p.second.size() > 1) {
                // cout<<p.second.size()<<"::";
                vector<pair<int,int>> v(p.second.size());
                for(int u=0;u<p.second.size();u++) {
                    // cout<<index[p.second[u]]<<" ";
                    v[u] = {index[p.second[u]],p.second[u]};
                }
                // cout<<"\n";
                sort(v.rbegin(),v.rend());
                mx = max(mx, v[1].first + 1);
            }
        }
    }
    return mx;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int Q;
        cin >> Q;
        string S;
        cin >> S;
        vector<int> arr(N);
        for(int i_arr = 0; i_arr < N; i_arr++)
        {
        	cin >> arr[i_arr];
        }
        vector<vector<int> > ranges(Q, vector<int>(2));
        for (int i_ranges = 0; i_ranges < Q; i_ranges++)
        {
        	for(int j_ranges = 0; j_ranges < 2; j_ranges++)
        	{
        		cin >> ranges[i_ranges][j_ranges];
        	}
        }

        int out_;
        out_ = goodString(N, Q, S, arr, ranges);
        cout << out_;
        cout << "\n";
    }
}