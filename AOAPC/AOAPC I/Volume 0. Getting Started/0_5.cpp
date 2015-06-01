#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char str[1000];
	while(fgets(str,1000,stdin) != NULL)
	{
		int i;
		int sum=0;
		int flag=0;
		for(i=0;i<strlen(str)-1;i++)
		{
			if( (flag==0) && (( str[i]<='Z' && str[i]>='A') || (str[i]<='z' && str[i]>='a')) )
			{
				sum++;
				flag=1;
			}
			if(!( str[i]<='Z' && str[i]>='A') && !(str[i]<='z' && str[i]>='a'))
				flag=0;
		}
		cout<<sum<<endl;
	}
	return 0;
}