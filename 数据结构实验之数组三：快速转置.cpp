#include <iostream>
using namespace std;
typedef struct
{
	int x,y,data;
}Traid;
int main(int argv,char *argc[])
{
	int mu,nu,tu;
	Traid a[51];
	while (cin>>mu>>nu>>tu)
	{
		for (int i = 0; i < tu; i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].data;
		}
		for (int i = 0; i < tu; i++)
		{
			int temp=a[i].x;
			a[i].x=a[i].y;
			a[i].y=temp;
		}
		for (int i = 0; i < tu-1; i++)
		{
			for (int j = i+1; j < tu; j++)
			{
				if(a[i].x<a[j].x)
				{
					Traid tmp;
					tmp=a[i];
					a[i]=a[j];
					a[j]=tmp;
				}
			}
		}
		for (int i = tu-1; i >=0; i--)
		{
			cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].data<<endl;
		}
	}

	return 0;
}