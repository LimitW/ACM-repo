#include<cstring>
#include<iostream>
using namespace std;

int main()
{
	char s[102][102];
	int i=0;
	memset(s,0,sizeof(s));
	while(gets(s[i]) != NULL)
	{
		i++;
	}// pe wa 无数次的根源 （s[i++]和 {i++})
	int n;
	n=i;
	int len=0;
	for(i=0;i<n;i++)
	{
		if(len < strlen(s[i]))
			len=strlen(s[i]);
	}
	int j;	
	for(j=0;j<len;j++)	
	{
		for(i=n-1;i>=0;i--)
		{
			if(s[i][j] != '\0')	
				cout<<s[i][j];
			else   
				cout<<' ';
		}
		cout<<endl;
	}
	return 0;
}