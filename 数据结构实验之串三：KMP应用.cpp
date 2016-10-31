#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;
int str1[100000100],str2[100000100];
int nextj[100000100];
void get_next(int m)
{
	int i,j;  
	nextj[0]=-1;  
	nextj[1]=0;  
	for(i=2;i<m;i++)  
	{  
		j=nextj[i-1];  
		while(j!=-1 && str2[i-1]!=str2[j])  
		{  
			j=nextj[j];  
		}  
		nextj[i]=j+1;  
	}  

}
void KMP(int n,int m)
{
	int i=0,j=0,flag=0,l,r;
	
	get_next(m); 
	while (i<n)
	{
		if((j==-1)||(str1[i]==str2[j]))
		{
			++i;++j;
		}
		else
			j=nextj[j];
		if(j==m)
		{
			flag++;
			if(flag>2)
			{
				cout<<"-1"<<endl;
				return;
			}
			l=i-m+1;
			r=i;
		}
	}
	if(flag==1)
		cout<<l<<" "<<r<<endl;
	else
		cout<<"-1"<<endl;
}

int main(int argv,char *argc[])
{

	int n,m;
	cin>>n;
	
		for (int i = 0; i < n; i++)
		{
			cin>>str1[i];
		}
		cin>>m;
		for (int j = 0; j < m; j++)
		{
			cin>>str2[j];
		}

		KMP(n,m);
	

	return 0;
}