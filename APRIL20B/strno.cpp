/*#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

vector<int> prime;

void generate()
{
	vector<bool> isprime(MAX+1,true);
	for(int i=2;i*i<=MAX;i++)
	{
		if(isprime[i])
		for(int j=i*i;j<MAX;j+=i)
		{
			isprime[j] = false;
		}
	}
}

void solve()
{
	
}

int main()
{
	generate();
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        solve();
}
*/
#include <bits/stdc++.h> 
using namespace std;
void kF(int n, int k) 
{ 
	vector<int>p; 
	while (n%2 == 0) 
	{ 
		p.push_back(2); 
		n /= 2; 
	} 
	for (int i=3; i*i<=n; i=i+2){ 
		while (n%i == 0){ 
			n = n/i; 
			p.push_back(i); 
		} 
	}
	if (n > 2) 
		p.push_back(n); 
	if (p.size() < k) 
	{ 
		cout <<"0"<< endl; 
		return; 
	}  
 	 else
  	{
   		 cout <<"1"<< endl; 
			return; 
 	 }
}  
int main() 
{ 
  int t;
  cin>>t;
  while(t--){
  	int n,k;
  	cin>>n>>k;
	kF(n, k);
  }
	return 0; 
}
