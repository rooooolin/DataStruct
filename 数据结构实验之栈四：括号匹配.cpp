#include <iostream>
using namespace std;
#include <string>
#include <string.h>

#define MaxSize 100
typedef struct
{
	char data[MaxSize];
	int top;
}SqStack;

int main(int argv,char *argc[])
{
	string str;
	
	while (getline(cin,str))
	{
		
		SqStack S;
		S.top=-1;
		int flag=0;
		for (int i = 0; i < str.size(); i++)
		{
			if(str.at(i)=='('||str.at(i)=='['||str.at(i)=='{')
				S.data[++S.top]=str.at(i);
			if(str.at(i)==')')
			{
				if(S.data[S.top]=='(')
				{
					S.data[S.top]=NULL;flag=1;
					S.top--;
				}
				else if(S.top==-1)
					flag=0;
				else
				{
				
					break;
				}
			}
			if(str.at(i)==']')
			{
				if(S.data[S.top]=='[')
				{
					S.data[S.top]=NULL;flag=1;
					S.top--;
				}
				else if(S.top==-1)
					flag=0;
				else
				{
				
					break;
				}
			}
			if(str.at(i)=='}')
			{
				if(S.data[S.top]=='{')
				{
					S.data[S.top]=NULL;flag=1;
					S.top--;
				}
				else if(S.top==-1)
					flag=0;
				else
				{
					
					break;
				}
			}
		}
		if(flag&&S.top==-1)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}