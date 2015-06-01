#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int comp(const void *a,const void *b)
{
	return*(int*)a-*(int*)b;
}
int main()
{		
	int n;
	while(scanf("%d",&n) != 0)
	{
	int num[14];
	memset(num,0,sizeof(num));
	int i;
	for(i=0;i<n;i++)
	{
		getchar();
		char left[26];
		fgets(left,26,stdin);
		int j;
		for(j=0;j<25;j++)
		{
			if(left[j] == ' ')
				num[i]++;
		}
	}
	qsort(num,n,sizeof(int),comp);
	int result=0;
	for(i=1;i<n;i++)
		result=result+(num[i]-num[0]);
	cout<<result<<endl;
	}
	return 0;
}