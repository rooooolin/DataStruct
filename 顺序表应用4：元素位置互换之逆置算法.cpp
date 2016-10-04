#include <iostream>
using namespace std;
#define InitSize 50
#define ElemType int
typedef struct{
	ElemType *data;
	int MaxSize,length;
	
}Sqlist;
void ListReverse(Sqlist &L,int start,int end)
{
	int i,j,temp;
	j=end;
	for(i=start;i<=(start+end)/2;i++)
	{
		temp=L.data[i];
		L.data[i]=L.data[j];
		L.data[j]=temp;
		j--;
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
		ListReverse(L,0,len-1);
		ListReverse(L,0,len-m-1);
		ListReverse(L,len-m,len-1);
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
