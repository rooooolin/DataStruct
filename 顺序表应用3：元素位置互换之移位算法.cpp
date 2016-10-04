#include <iostream>
using namespace std;
#define InitSize 50
#define ElemType int
typedef struct{
	ElemType *data;
	int MaxSize,length;
	
}Sqlist;
void ListExchange(Sqlist &L,int len,int m)
{
	int k;
	for(;m>0;m--)
	{
		k=L.data[0];
		for(int i=0;i<L.length;i++)
		{
			L.data[i]=L.data[i+1];
		}
		L.data[len-1]=k;
	}
	
}
void ListCreat(Sqlist &L,int len)
{
	L.data=new int[1000001];
	L.length=0;
	for(int i=0;i<len;i++)
	{
		cin>>L.data[i];
		L.length++;
	}
	L.MaxSize=1000001;
}
int main(int argv,char *argc[])
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int len,m;
		cin>>len>>m;
		Sqlist L;
		ListCreat(L,len);
		ListExchange(L,len,m);
		for(int j=0;j<L.length;j++)
		{
			if(L.length-1==j)
				cout<<L.data[j]<<endl;
			else
				cout<<L.data[j]<<" ";
		}
	}
	return 0;
}
