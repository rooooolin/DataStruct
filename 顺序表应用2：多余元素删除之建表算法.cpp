#include <iostream>
using namespace std;
#define InitSize 50
#define ElemType int
typedef struct{
	ElemType *data;
	int MaxSize,length;
	
}Sqlist;
int ListDelete(Sqlist &L)
{
	int k=0;
	for(int i=0;i<L.length;i++)
	{
		int flag=0;
		for(int j=0;j<k;j++)
		{
			if(L.data[j]==L.data[i])
			{
				flag=1;
				break;
			}
				
		}
		if(!flag)
		{
			L.data[k++]=L.data[i];
			
		}
	}
	return k;
}
void ListCreat(Sqlist &L,int m)
{
	L.data=new int[10001];
	L.length=0;
	for(int i=0;i<m;i++)
	{
		cin>>L.data[i];
		L.length++;
	}
	L.MaxSize=10001;
}
int main(int argv,char *argc[])
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int m;
		cin>>m;
		Sqlist L;
		ListCreat(L,m);
		int k=ListDelete(L);
		for(int j=0;j<k;j++)
		{
			if(k-1==j)
				cout<<L.data[j]<<endl;
			else
				cout<<L.data[j]<<" ";
		}
	}
	return 0;
}