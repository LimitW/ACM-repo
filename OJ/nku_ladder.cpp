//nkoj 1023
/*#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char ch;
	long long t=0,ans=0;
	while(scanf("%c",&ch)!=EOF)
	{
		if(ch>='0' && ch<='9')
			t=t*10+ch-'0';
		if(ch==' ')
		{
			ans+=t;
			t=0;
		}
		if(ch=='\n')
		{
			ans+=t;
			cout<<ans<<endl;
			ans=t=0;
		}
	}
	return 0;
}*/
//nkoj 2207
/*
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
long long a,b;
while(scanf("%lld %lld",&a,&b) && !(a==0 && b==0))
cout<<a*b<<endl;
return 0;
} */
//nkoj 1541
/*
#include<iostream>
using namespace std;
int main()
{
	int L,N;
	cin>>L>>N;
	bool *road;
	road=new bool[L+1];
	int i;
	for(i=0;i<=L;i++)
		road[i]=1;
	for(i=0;i<N;i++)
	{
		int dis1,dis2;
		cin>>dis1>>dis2;
		int j;
		for(j=dis1;j<=dis2;j++)
			road[j]=0;
	}
	int ans=0;
	for(i=0;i<=L;i++)
		if(road[i]==1)
			ans++;
	cout<<ans<<endl;
	delete []road;
	return 0;
}*/
//nkoj 1395
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char ch;
	int ans=0,n=0;
	while(scanf("%c",&ch) && ch!='#')
	{
		n++;
		if(ch>='A' && ch<='Z')
			ans+=n*(ch-'A'+1);
		if(ch=='\n')
		{
			cout<<ans<<endl;
			ans=0;
			n=0;
		}
	}
	return 0;
}