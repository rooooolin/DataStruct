#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

void get_next(char T[],int nextj[],int len)
{
	int i=1,j=0;
	
	nextj[1]=0;
	while (i<len)
	{
		if((j==0)||(T[i]==T[j]))
		{
			++i;++j;
			nextj[i]=j;
		}
		else
			j=nextj[j];
	}
	
}
int KMP(char s[],char t[])
{
	int i=1,j=1;
	int nextj[1000000];
	int slen=strlen(s);
	int tlen=strlen(t);
    memset(nextj,0,sizeof(nextj));  
    get_next(t,nextj,tlen); 
	
	while (i<slen&&j<tlen)
	{
		if(j==0||s[i]==t[j])
		{
			++i;++j;
		}
		else
			j=nextj[j];
	}
	if(j>tlen-1)
		return i-tlen+1;
	else
		return -1;
}

int main(int argv,char *argc[])
{
	string temp1,temp2;
	char str1[1000000],str2[1000000],s;
	while (cin>>temp1)
	{
		cin>>temp2;
		int j=1;
		for (int i = 0; i < temp1.size(); i++)
		{
			str1[j++]=temp1.at(i);
		}
		str1[j]='\0';
		int k=1;
		for (int i = 0; i < temp2.size(); i++)
		{
			str2[k++]=temp2.at(i);
		}
		str2[k]='\0';
		int pos=KMP(str1,str2);
		cout<<pos<<endl;
	}
	return 0;
}