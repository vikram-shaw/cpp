#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int

string dToB(int N)
{
string s="";
for (int i = 31; i >= 0; i--) {
int k = N >> i;
if (k & 1)
s+='1';
else
s+='0';
}
return s;
}
int main() {
int t;
cin>>t;
while(t--){
int n,b;
cin>>n>>b;
map<long long ,long long> mp;
int a[n];
long long int res=0;
for(int i=0;i<n;i++)cin>>a[i];
sort(a,a+n);
ull x=a[0];
for(int i=1;i<n;i++)x|=a[i];
int max_a=a[n-1];
string s=dToB(max_a);
//cout<<s<<endl;
// string s=to_string(temp);
// //cout<<max_a<<" "<<s<<endl;
reverse(s.begin(),s.end());
int pos=0;
for(int i=0;i<(int)s.size();i++)
{
if(s[i]=='1')
{
pos=i+1;
// break;
}
}
if(b>__builtin_popcount(x) || n==1){
cout<<"-1"<<endl;
continue;
}
long long int m=0;
ull index=0;
// cout<<pos<<endl;
for(int i=0;i<=pos;i++)
{
index+=pow(2,i);
// cout<<index<<" ";
}
//cout<<endl;
for(int i=index;i>1;i--)
{
if(__builtin_popcount(i) ==b)
for(int j=0;j<n;j++){
res+=a[j]&i;
}
mp[res]++;
m=max(m,res);
res=0;
}
cout<<mp[m]<<endl;
}
}
