#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char in[1000];
	while(scanf("%s",in) != EOF)
	{
		int size=strlen(in);
		int i;
		for(i=0;i<size;i++)
			in[i]-=7;
		cout<<in;
		memset(in,0,sizeof(in));
	}
	return 0;
}