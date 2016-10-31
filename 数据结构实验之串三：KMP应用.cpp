#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

void get_next(string t,int *nextj)
{int i,j;  
       nextj[0]=-1;  
       nextj[1]=0;  
	   
       for(i=2;i<t.size();i++)  
       {  
           j=nextj[i-1];  
           while(j!=-1 && t[i-1]!=t[j])  
           {  
               j=nextj[j];  
           }  
           nextj[i]=j+1;  
       }  
	
}
void KMP(string s,string t)
{
	int i=0,j=0;
	int *nextj;
	nextj=(int *)malloc(sizeof(int)*1000*1000);
    get_next(t,nextj); 
	int tlen=t.size();
	while (i<s.size()&&j<tlen)
	{
		if((j==-1)||(s[i]==t[j]))
		{
			++i;++j;
		}
		else
			j=nextj[j];
	}
	if(j>t.size()-1)
		cout<<i-tlen+1<<" "<<i-1<<endl;
	else
		cout<<"-1"<<endl;
}

int main(int argv,char *argc[])
{
	string str1,str2;
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