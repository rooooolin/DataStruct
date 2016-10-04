#include <iostream>  
#include <stdio.h>
using namespace std; 
int countm,maxnum;  
struct LNode
{
	int data[50000];
	int n;
}Node;

int MaxSum(struct LNode &L,int l,int mid,int r)  
{  
	int i;  
	int sum1=0,sum2=0,s=0;  
	for(i=mid;i>=l;--i)  
	{  
		s+=L.data[i];  
		sum1=max(sum1,s);  
	}  
	s=0;  
	for(i=mid+1;i<=r;++i)  
	{  
		s+=L.data[i];  
		sum2=max(sum2,s);  
	}  
	return sum1+sum2;  
}  

int Merger(struct LNode &L,int left,int right)  
{  
	countm++;  
	if(left==right)
		return L.data[left];  
	int mid=(left+right)>>1;  
	int x1=Merger(L,left,mid);  
	int x2=Merger(L,mid+1,right);  
	int x3=MaxSum(L,left,mid,right);  
	return max(x3,max(x1,x2));  
}  
int main()  
{  
	LNode L;
	scanf("%d",&L.n);  
	for(int i=0;i<L.n;++i)
		scanf("%d",&L.data[i]);  

	countm=0;  
	maxnum=Merger(L,0,L.n-1);  
	printf("%d %d\n",maxnum,countm);  
	return 0;  
}  