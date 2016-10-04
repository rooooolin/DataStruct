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
	
	int input[10010],output[10010];
	
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>input[i];
	}
	int t;
	cin>>t;
	while (t--)
	{
		for (int i = 0; i < n; i++)
		{
			cin>>output[i];
		}
		SqStack S;
		S.top=-1;
		int i,j;
		i=j=0;
		while (j<n)
		{
			if(input[i]==output[j])
			{i++;j++;}
			else if(S.top!=-1&&S.data[S.top]==output[j])
			{
				j++;
				S.data[S.top]=NULL;
				S.top--;
			}
			else if(i<n)
			{
				S.data[++S.top]=input[i];
				i++;
			}
			else break;
		}
		if(S.top==-1)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}