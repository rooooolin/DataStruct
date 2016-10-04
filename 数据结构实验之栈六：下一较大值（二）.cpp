#include <iostream>
using namespace std;
#include <string>
#include <string.h>
#include <malloc.h>
#define stack_init_size 100100
typedef struct node       
{
    int data,pos,next;
}Node;
struct Stack                    
{
    Node *base,*top;      
    void clear()                  
    {
        top = base;
    }
    void InitStack()            
    {
        base=(Node *)malloc(stack_init_size*sizeof(Node));
        top=base;
    }
    Node GetTop()            
    {
        Node e;
        e=*(top-1);                
        return e;
    }

    bool isempty()              
    {
        return top == base;
    }
    void Push(Node e)       
    {
        *top++=e;
    }
    void Pop()                     
    {
        top--;
    }
}SqStack;
Node a[100100];
int main(int argv,char *argc[])
{
	int t;
	cin>>t;
	SqStack.InitStack();
	while (t--)
	{
		if (!SqStack.isempty())
		{
			SqStack.clear();
		}
		int n;
		cin>>n;
		for (int i = 1; i <= n; i++)
		{
			cin>>a[i].data;
			a[i].pos=i;
			a[i].next=-1;
			if(SqStack.isempty())
				SqStack.Push(a[i]);
			else
			{
				while (!SqStack.isempty())
				{
					Node b;
					b=SqStack.GetTop();
					if(b.data<a[i].data)
					{
						a[b.pos].next=a[i].data;
						SqStack.Pop();
					}
					else
						break;
				}
				SqStack.Push(a[i]);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			cout<<a[i].data<<"-->"<<a[i].next<<endl;
		}
		if(t>0)
			cout<<endl;
	}
	return 0;
}
