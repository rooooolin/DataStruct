#include <iostream>
using namespace std;
#define InitSize 50
#define ElemType int
typedef struct{
	ElemType *data;
	int MaxSize,length;
}Sqlist;
void ListDelete(Sqlist &L)
{
	int i,j;
	int k;
	for(i=0;i<L.length;i++)
	{
		for(j=i+1;j<L.length;j++)
		{
			if(L.data[i]==L.data[j])
			{
				for(k=j;k<L.length;k++)
					L.data[k]=L.data[k+1];
				L.length--;
				j--;
			}
		}
	}

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
		ListDelete(L);
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
