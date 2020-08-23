#include<bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
	return a + rand() %(b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	printf("1\n");
	int n = rand(1,10);
	int k = rand(1,10);
	printf("%d %d\n",n,k);
	for(int i=0;i<n;i++)
		printf("%d ",rand(1,5));
	puts("");
}
