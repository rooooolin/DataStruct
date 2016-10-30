#include <iostream>
using namespace std;
int main(int argv,char *argc[])
{
	int m,n;
	while (cin>>m>>n)
	{
		int a[100][100],b[100][100];
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin>>a[i][j];
			}
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				b[j][i]=a[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if(j<m-1)
					cout<<b[i][j]<<" ";
				else
					cout<<b[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}


}