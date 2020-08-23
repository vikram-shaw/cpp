#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        int arr[n];
        set<int> s;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<m;i++)
        {
            int r;
            cin>>r;
            r--;
            s.insert(r);
        }
        bool yes = false;
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1] && s.find(j)!=s.end())
                    swap(arr[j],arr[j+1]);
            }
        }
        if(is_sorted(arr,arr+n))
            puts("YES");
        else
            puts("NO");
    }
    
    return 0;
}