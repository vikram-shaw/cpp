#include<bits/stdc++.h>
using namespace std;

void solve(int t)
{
    printf("Case #%d: ",t);
    string s;
    cin>>s;
    stack<char> stack;
    for(char c: s)
    {
		int n = c - 48;
		if(stack.size() < n)
		{
			for(int i=stack.size();i<n;i++){
				stack.push('(');
				printf("(");
			}
		}
		else
		{
			while(stack.size()!=n)
			{
				printf(")");
				stack.pop();
			}
		}
		printf("%c",c);
	}
	while(!stack.empty())
	{
		printf(")");
		stack.pop();
	}
	puts("");
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        solve(i);
}
