#include <iostream>
using namespace std;
#include <string>
#include <string.h>
#include <malloc.h>
#define stack_init_size 10010
typedef struct 
{
	int data[stack_init_size];
	int top;
}SqStack;


int main(int argv,char *argc[])
{
	
	int t;
	cin>>t;
	while (t--)
	{
		SqStack S;
		S.top=-1;
		int m,n;
		cin>>m>>n;
		for (int i = 0; i < n; i++)
		{
			char act;
			cin>>act;
			if(act=='P')
			{
				int x;
				cin>>x;
				if (S.top==m-1)
					cout<<"F"<<endl;
				else
					S.data[++S.top]=x;
			}
			if(act=='A')
			{
				if (S.top==-1)
				{
					cout<<"E"<<endl;
				}
				else
					cout<<S.data[S.top]<<endl;
			}
			if(act=='O')
			{
				if(S.top==-1)
					cout<<"E"<<endl;
				else
				{
					cout<<S.data[S.top]<<endl;
					S.data[S.top]=NULL;
					S.top--;
				}
			}
				
		}
		if(t>0)
			cout<<endl;
	}
	return 0;
}