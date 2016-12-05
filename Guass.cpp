#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

class Metrix{
public:
	template<typename T>
	static void Print(double a[3][4])
	{
		for (double(*p)[4]=a;p!=a+3;p++)
		{
			for (double *q=*p;q!=*p+4;q++)
				cout<<setiosflags(ios::fixed)<<setprecision(4)<<*q<<" ";
			cout<<endl;
		}

	}
	static void Back(double a[3][4])
	{
		int i=0;
		for(double(*p)[4]=a;p!=a+3;p++)
		{
			double temp=(*p)[i++];
			for(double *q=*p;q!=*p+4;q++)
			{
				(*q)/=temp;
			}
		}
		cout<<endl;
		cout<<"对角元素置1："<<endl;
		Metrix::Print<double>(a);
		cout<<endl;
		cout<<"回代过程："<<endl;
		for(int i=1; i<3; i++)
		{
			for(int j=i-1; j>=0; j--)
			{
				double temp=a[j][i];
				for(int p=i; p<4; p++)
				{
					a[j][p]-=(temp*a[i][p]);
				}
			}
			Metrix::Print<double>(a);
			cout<<endl;
		}
	}
};


int main(int argv,char *argc[])
{

	double a[3][4];
	int MaxLineNum=0,max,flag=0,k=-1;
	
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<4;j++)
			cin>>a[i][j];
	}

	cout<<"输入的方程组为："<<endl;
	Metrix::Print<double>(a);
	cout<<endl;
	cout<<"高斯消去步骤如下："<<endl;

	try
	{
		flag=0;
		while ((k++)<2)
		{
			cout<<endl;
			max=a[k][k];
			for (int i = k; i < 3; i++)
			{
				if(a[i][k]>max)
				{
					max=a[i][k];
					flag=1;
					MaxLineNum=i;
				}
			}
			if(!flag)
				MaxLineNum=k;
			if(max==0)
			{
				flag=0;
				break;
			}

			else if(k!=MaxLineNum)
			{
				for (int i = 0; i < 4; i++)
				{
					a[k][i]+=a[MaxLineNum][i];
					a[MaxLineNum][i]=a[k][i]-a[MaxLineNum][i];
					a[k][i]-=a[MaxLineNum][i];
				}
			}
			cout<<"主元素："<<"a["<<MaxLineNum<<"]["<<k<<"]="<<max<<endl;
			cout<<"交换矩阵的第"<<MaxLineNum<<"行与第"<<k<<"行得"<<endl;

			Metrix::Print<double>(a);
			for (int i = k; i < 2; i++)
			{
				double temp=a[i+1][k];
				for (int j = k; j < 4; j++)
				{
					a[i+1][j]-=((temp/a[k][k])*a[k][j]);
				}
			}
			cout<<"消去后得新矩阵："<<endl;
			Metrix::Print<double>(a);
		}
		if(!flag)
			cout<<"系数为奇异矩阵，该方程组无解"<<endl;
		else
		{
			Metrix::Back(a);
			Metrix::Print<double>(a);
			cout<<endl<<"方程组解为"<<endl;
			int i=1;
			for(double(*p)[4]=a;p!=a+3;p++)
				cout<<"x"<<i++<<"="<<(*p)[3]<<endl;
		}
	}
	catch(exception e)
	{
		throw e;
	}

	return 0;
}
