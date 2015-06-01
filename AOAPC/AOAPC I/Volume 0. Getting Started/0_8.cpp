#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char s[133];
	while(gets(s) != NULL)
	{
		int i;
		int num=0;
		for(i=0;i<strlen(s);i++)
		{
			char c;
			if(s[i]=='!')
			{
				cout<<endl;
				continue;
			}
			else if (s[i] == '\n')
			{
				putchar('\n');
				continue;
			}
			else if( ((int)s[i]-48)>=0 && ((int)s[i]-48)<=9 )
			{
				num=num+(int)s[i]-48;
				continue;
			}
			else
			{
				c=s[i];
			}
			for(;num;num--)
			{
				if(c=='b')
					cout<<' ';
				else
					cout<<c;
			}
			num=0;
		}
		cout<<endl;
	}
	return 0;
}