#include <iostream>
#include <cstdio> 
#include <cstdlib> 

using namespace std;
#define InitSize 50
#define ElemType int
typedef struct{
	ElemType *data;
	int MaxSize,length;
	
}Sqlist;
int DataPostion(Sqlist &L,int m)
{
	int i,flag=0;
	int start=0,end=L.length-1,mid;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(L.data[mid]<m)
			start=mid+1;
		else if(L.data[mid]>m)
			end=mid-1;
		else
			return mid;
	}
	return -1;
}
void ListCreat(Sqlist &L,int len)
{
	L.data=new int[20000];
	L.length=0;
	for(int i=0;i<len;i++)
	{
		scanf("%d",&L.data[i]);
		
		L.length++;
	}

}
int main(int argv,char *argc[])
{
	int n;
	scanf("%d",&n);
	Sqlist L;
	ListCreat(L,n);
	int t;
	scanf("%d",&t);
	int flag;
	while(t--)
	{
		int m;
		scanf("%d",&m);
		flag=DataPostion(L,m);
		if(-1==flag)
			printf("No Found!\n");
		else
			printf("%d\n",flag+1);

	}
		
	return 0;
}
