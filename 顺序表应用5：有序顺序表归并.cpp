#include <iostream>
using namespace std;
#define InitSize 50
#define ElemType int
typedef struct{
	ElemType *data;
	int MaxSize,length;
	
}Sqlist;
Sqlist ListMerger(Sqlist &A,int m,Sqlist &B,int n)
{
	int i=0,j=0,k=0;
	Sqlist C;
	C.data=new int[m+n];;
	while(i<m&&j<n)
	{
		if(A.data[i]<=B.data[j])
			C.data[k++]=A.data[i++];
		else
			C.data[k++]=B.data[j++];
	}
	while(i<m)
		C.data[k++]=A.data[i++];
	while(j<n)
		C.data[k++]=B.data[j++];
	C.length=k;
	return C;
	
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
	int m,n;
	cin>>m>>n;
	Sqlist A,B,C;
	ListCreat(A,m);
	ListCreat(B,n);
	C=ListMerger(A,m,B,n);
		for(int j=0;j<C.length;j++)
		{
			if(C.length-1==j)
				cout<<C.data[j]<<endl;
			else
				cout<<C.data[j]<<" ";
		}
	
	return 0;
}