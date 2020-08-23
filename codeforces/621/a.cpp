#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(a==b)
            puts("0");
        else if(a>b)
        {
            if((a-b)%2)
                puts("2");
            else
                puts("1");
        }
        else
        {
            if((b-a)%2)
                puts("1");
            else
                puts("2");
        }
    }
    return 0;
}