#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MaxSize 1000

typedef struct{
	int data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack &s)
{
	s.top=-1;
}
void Push(SqStack &s,int x)
{
	s.data[++s.top]=x;
}


bool StackEmpty(SqStack s)
{
	if(s.top==-1)
		return true;
	else
		return false;
}
int main(int argv,char *argc[])
{
	char str=0;
	SqStack S;
	InitStack(S);
	while(cin>>str,str!='#')
	{
		if(str>='a'&&str<='z')
			cout<<char(str);
		else if(str=='(')
			Push(S,str);
		else if(str==')')
		{
			while (S.data[S.top]!='(')
			{
				cout<<char(S.data[S.top--]);
			}
			S.top--;
		}
		else if(str=='+'||str=='-')
		{
			while (!StackEmpty(S)&&S.data[S.top]!='(')
			{
				cout<<char(S.data[S.top--]);
			}
			Push(S,str);
		}
		else if(str=='*'||str=='/')
		{
			while (!StackEmpty(S)&&S.data[S.top]!='('&&(S.data[S.top]=='*'||S.data[S.top]=='/'))
			{
				cout<<char(S.data[S.top--]);
			}
			Push(S,str);
		}
	}
	while (!StackEmpty(S))
	{
		cout<<char(S.data[S.top--]);
	}
	cout<<endl;
	return 0;
}
