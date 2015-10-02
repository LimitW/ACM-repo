//枚举
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;	

bool gragh[20][20],paint[20][20];
int n,count;

bool allYellow(){
	count=0;
	int i,j;
    for( i=1;i<=n;i++)
        for( j=1;j<=n;j++){
            if(gragh[i][j]^paint[i][j]^paint[i-1][j]^paint[i][j-1]^paint[i+1][j]^paint[i][j+1])
                return 0;	
			if(paint[i][j])
				count++;
        }
    return 1;
}

int main()
{
	int t,T;
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>n;
		int i,j,k;
		char str[20];
		memset(gragh,0,sizeof(gragh));
        for(i=1;i<=n;i++)
		{
            scanf("%s",str+1);
            for(j=1;j<=n;j++)
                gragh[i][j]=(str[j]=='w');
        }
		int maxn=1<<n;
		int flag=0,ans=300;
		for(i=0;i<maxn;i++)
		{
		memset(paint,0,sizeof(paint));
            int tmp=i;
            for(int k=1;k<=n;k++)
			{
                paint[1][k]=tmp&1;
                tmp>>=1;
            }
		for(j=2;j<=n;j++)
			for(k=1;k<=n;k++)
				 if(gragh[j-1][k]^paint[j-1][k]^paint[j-1][k+1]^paint[j-1][k-1]^paint[j-2][k])
					 paint[j][k]=1; 
		if(allYellow())
		{
			flag=1;
			if(ans>count)
			ans=count;
		}
		}
		if(flag)
			cout<<ans<<endl;
		else
			cout<<"inf"<<endl;
	}
	return 0;
}