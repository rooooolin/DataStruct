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
void ListSum(Sqlist &L)
{
	int max=0;
	int sum=0;
	for(int i=0;i<L.length;i++)
	{
		sum+=L.data[i];
		if(sum<0)
			sum=0;
		if(sum>max)
			max=sum;
	}
	printf("%d\n",max);
}
void ListCreat(Sqlist &L,int len)
{
	L.data=new int[len];
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
	ListSum(L);
	return 0;
}
