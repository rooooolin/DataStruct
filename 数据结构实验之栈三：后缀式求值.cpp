#include <iostream>
using namespace std;
#include <string>
#include <string.h>

#define MaxSize 100
typedef struct
{
	int data[MaxSize];
	int top;
}SqStack;

int main(int argv,char *argc[])
{
	char str=0;
	SqStack S;
	S.top=-1;
	while (cin>>str,str!='#')
	{
		if(str<='9'&&str>='0')
			S.data[++S.top]=(int)(str-'0');
		else
		{
			int temp1,temp2;
			temp1=S.data[S.top];
			S.data[S.top]=NULL;
			temp2=S.data[--S.top];
			int result;
			switch (str)
			{
			case '+':result=temp1+temp2;break;
			case '-':result=temp2-temp1;break;
			case '*':result=temp1*temp2;break;
			case '/':result=temp2/temp1;break;
			default:
				break;
			}
			S.data[S.top]=result;
		}
	}
	cout<<S.data[S.top]<<endl;
	return 0;
}