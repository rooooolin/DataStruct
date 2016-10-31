#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

void get_next(string t,int *nextj)
{
	int i,j;  
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
int KMP(string s,string t)
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
		return i-t.size()+1;
	else
		return -1;
}

int main(int argv,char *argc[])
{
	string str1,str2;
	
	
	while (cin>>str1)
	{
		cin>>str2;
		
		int pos=KMP(str1,str2);
		cout<<pos<<endl;
	}
	return 0;
}
