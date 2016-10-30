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
void KMP(char s[],char t[])
{
	int i=1,j=1;
	int nextj[1000];
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
		cout<<i-tlen+1<<" "<<i-1<<endl;
	else
		cout<<"-1"<<endl;
}

int main(int argv,char *argc[])
{
	char str1[1000],str2[1000],s;
	int n,m;
	cin>>n;

		int i;
		for (i=1; i <= n; i++)
		{
			cin>>str1[i];
		}
		str1[i]='\0';
		int j;
		cin>>m;
		for (j=1; j <= m; j++)
		{
			cin>>str2[j];
		}
		str2[j]='\0';
		KMP(str1,str2);
		
	
	return 0;
}