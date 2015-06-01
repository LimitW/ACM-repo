#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int i;
	for(i=0;i<N;i++)
	{
		if(i==0)
			getchar();
		else
			cout<<endl;
		int m,n;
		cin>>m>>n;
		while(n)
		{
		int j,k;
		for(j=1;j<=m;j++)
		{
			for(k=j;k>0;k--)
				cout<<j;
			cout<<endl;
		}
		for(j=m-1;j>0;j--)
		{
			for(k=j;k>0;k--)
				cout<<j;
			cout<<endl;
		}
		n--;
		if(n!=0)
		cout<<endl;
		}
	}
	//system("pause");
	return 0;
}
