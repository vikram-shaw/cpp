#include<bits/stdc++.h>
using namespace std;

bool board[100][100];
int mx, n, ans = 0;

int column(int p)
{
	int c = 0;
	while(p)
	{
		p >>= 1;
		c++;
	}
	return c-1;
}

void print()
{	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<(board[i][j]?"Q":"_")<<' ';
		puts("");
	}
	puts("");
}

void rec(int mask=0, int ld=0, int rd=0, int row=0)
{
	if(mask == mx)
	{
		print();
		ans++;
		return;
	}
	
	int x = mx&(~mask)&(~ld)&(~rd);
	
	while(x)
	{
		int p = x & (-x);
		x -= p;
		int col = column(p);
		board[row][col] = true;
		rec(mask|p,(ld|p)<<1,(rd|p)>>1,row+1);
		board[row][col] = false;
	}
}

int main()
{
	cin>>n;
	mx = (1<<n)-1;
	rec();
	cout<<"Total no.of solutions: "<<ans<<'\n';
}
