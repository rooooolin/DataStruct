#include <iostream>
#include <queue>
#include <string>
#include <memory.h>
#include <iomanip>
#include<functional>
using namespace std;
int main(int argv,char *argc[])
{
	string str;
	int la,lh;
	int a[1000];
	while (cin>>str)
	{
		memset(a,0,sizeof(a));
		la=8*str.size();
		priority_queue<int,vector<int>,greater<int> > Q;
		for (int i = 0; i < str.length(); i++)
		{
			a[str[i]]++;
		}
		for (int i = 0; i < 150; i++)
		{
			if(a[i]!=0)
				Q.push(a[i]);
		}
		lh=0;
		while (!Q.empty())
		{
			int n=Q.top();
			Q.pop();
			if(!Q.empty())
			{
				int m=Q.top();
				Q.pop();
				int s=n+m;
				Q.push(s);
				lh+=s;
			}
		}
		cout<<la<<" "<<lh<<" ";
		cout<<setiosflags(ios::fixed)<<setprecision(1)<<la*1.0/lh<<endl;
	}
	
	return 0;
}