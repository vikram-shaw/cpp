#include<bits/stdc++.h>
using namespace std;

void recursive(char c, string& res, int i = 7)
{
	if(i == -1)
		return;
	if((c>>i)&1)
		res[7-i] = '1';
	recursive(c,res,i-1);
}

vector<string> toBinary(string& s)
{
	vector<string> result;
	string res = "00000000";
	for(char c: s)
	{
		for(int i=0;i<8;i++)
			res[i] = '0';
		recursive(c,res);
		result.push_back(res);
	}
	return result;
}

void print(vector<string>& result)
{
	int size = result.size();
	cout<<"[";
	for(int i=0;i<size-1;i++)
		cout<<result[i]<<", ";
	if(size != 0)
		cout<<result[size-1];
	cout<<"]\n";
}

int main()
{
	string str;
	getline(cin,str);
	vector<string> result = toBinary(str);
	print(result);
}
