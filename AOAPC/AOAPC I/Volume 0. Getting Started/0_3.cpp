#include<iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int t;
	for(t=1;t<=T;t++)
	{
		int n;
		cin>>n;
		int i,j;
		int **a;
		a=new int*[n];
		for(i=0;i<n;i++)
			a[i]=new int[4];
		for(i=0;i<n;i++)
			for(j=0;j<4;j++)
				a[i][j]=0;
		for(j=0;j<n;j++)
		{
			cin>>a[j][0]>>a[j][1]>>a[j][2];
			a[j][3]=a[j][0]*a[j][2];
		}
		int sum=0;
		for(j=0;j<n;j++)
			sum+=a[j][3];
		cout<<sum<<endl;
		for(i=0;i<n;i++)
			delete []a[i];
		delete []a;
	}
	return 0;
}
		