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
void Pop(SqStack &s)
{
	if(s.top==-1)
		cout<<"error"<<endl;
	int x=s.data[s.top--];
}
void Top(SqStack &s)
{
	if(s.top==-1)
		cout<<"empty"<<endl;
	else
		cout<<s.data[s.top];
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
	int x,r;
	SqStack S;
	InitStack(S);
	cin>>x;
	cin>>r;
	if(0==x)
		cout<<"0"<<endl;
	else
	{
		while(x>0)
		{
			int t=x%r;
			Push(S,t);
			x/=r;
		}
	}
		while(!StackEmpty(S))
		{
			Top(S);
			S.top--;
		}
		cout<<endl;
	return 0;
}
