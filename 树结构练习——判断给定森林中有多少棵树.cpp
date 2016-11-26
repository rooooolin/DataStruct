#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main(int argv,char *argc[])
{ 
	bool st[500];
	int n,m,a,b;
	while (cin>>n>>m)
	{
		int cnt=n;
		memset(st,0,sizeof(st));
		while (m--)
		{
			cin>>a>>b;
			if(!st[b])
			{
				st[b]=true;
				cnt--;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
