#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n!=-1)
	{
		int b = n % 257;
		int c = n % 193;
		int d = b*b - 4*c;
		if(d >= 0 && sqrt(d)>=b)
			puts("Regular");
		else if(b==0 && c==0)
			puts("Bom");
		else
			puts("So o ouro");
		cin>>n;
	}
}
