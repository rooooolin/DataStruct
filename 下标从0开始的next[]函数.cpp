    #include<iostream>  
    #include<cstring>  
#include <string>
    #include<cstdio>  
    using namespace std;  
    int nextj[100];  
    int n;  
    void Next(string a)  
    {  
       int i,j;  
       nextj[0]=-1;  
       nextj[1]=0;  
       for(i=2;i<n;i++)  
       {  
           j=nextj[i-1];  
           while(j!=-1 && a[i-1]!=a[j])  
           {  
               j=nextj[j];  
           }  
           nextj[i]=j+1;  
       }  
	   for(i=0;i<n-1;i++)  
            cout<<nextj[i]+1<<" ";  
            cout<<nextj[i]+1<<endl;
    }  
    int main()  
    {  
        int i;  
       string a;  
       while(cin>>a)  
       {  
           n=a.size();  
           //cout<<n<<endl;  
           Next(a);  
             
       }  
       return 0;  
    }  