#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	set<int> present,zeroPosition;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		present.insert(arr[i]);
		if(arr[i]==0)
			zeroPosition.insert(i);
	}
	vector<int> notPresent;
	for(int i=1;i<=n;i++)
	{
		if(present.find(i)==present.end())
			notPresent.push_back(i);
	}
	int i,size = notPresent.size();
	i = 0;
	for(int p: zeroPosition){
		arr[p] = notPresent[i%size];
		i--;
	}
	for(int i=0;i<n;i++)
		cout<<arr[i]<<' ';
	cout<<'\n';
}
