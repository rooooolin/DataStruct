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
void ListReverse(Sqlist &L,int start,int end)
{
	int temp;
	int i,j=end;
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
	int len;
	scanf("%d",&len);
	if(len<1||len>1000000)
		scanf("%d",&len);
	Sqlist L;
	ListCreat(L,len);
	int t;
	scanf("%d",&t);
	if(t<1||t>30)
		scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int m;
		scanf("%d",&m);
		if(m<1||m>len)
			scanf("%d",&m);
		ListReverse(L,0,len-1);
		ListReverse(L,0,len-m-1);
		ListReverse(L,len-m,len-1);
		for(int j=0;j<L.length;j++)
		{
			if(L.length-1==j)
				
			printf("%d\n",L.data[j]);
			else
				printf("%d ",L.data[j]);
		}
	}
		
	
	
	return 0;
}
