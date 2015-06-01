/*#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
bool check(bool *s,int n)
{
	int i;
	for(i=0;i<n;i++)
		if(s[i]==1)
			return 0;
	return 1;
}
int comp(const void* a,const void *b)
{
return*(char*)a-*(char*)b;
}
int main()
{
	
	int n;
	while(cin>>n && n!=-1)
	{
		cout<<"Round "<<n<<endl;
		char str[1000];
		cin>>str;
		int len1=strlen(str);
		char guess[1000];
		cin>>guess;
		int len2=strlen(guess);
		qsort(guess,len2,sizeof(char),comp);
		int i,j,k;
 		for(i=0;i<len2;i++)
		{
			if(guess[i]==guess[i+1])
			{
				for(j=i;j<len2-1;j++)
					guess[j]=guess[j+1];
				guess[j]='\0';
				len2--;
				i--;	
			}
		}		
		bool word[1000];
		memset(word,1,sizeof(word));
		int ans,wrong;
		wrong=0;
		for(j=0;j<len2;j++)
		{
			char cmp;
			cmp=guess[j];
			int tmp=0;
			for(k=0;k<len1;k++)
			{
				if(cmp==str[k])
				{
					word[k]=0;
					tmp=1;
				}
				if(tmp==0 && k==len1-1)
					wrong++;
			}
			if(wrong>=7)
			{
				ans=-1;
				break;
			}
			if(check(word,len1))
			{
				ans=1;
				break;
			}
		}
		if(wrong<7 && !check(word,len1))
			ans=0;
		if(ans==1)
			cout<<"You win."<<endl;
		if(ans==0)
			cout<<"You chickened out."<<endl;
		if(ans==-1)
			cout<<"You lose."<<endl;

	}
	return 0;
}*/
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
bool check(bool *s,int n)
{
	int i;
	for(i=0;i<n;i++)
		if(s[i]==1)
			return 0;
	return 1;
}

int main()
{
	
	int n;
	while(cin>>n && n!=-1)
	{
		cout<<"Round "<<n<<endl;
		char str[1000];
		cin>>str;
		int len1=strlen(str);
		char guess[1000];
		cin>>guess;
		int len2=strlen(guess);
		int j,k;	
		bool word[1000];
		memset(word,1,sizeof(word));
		int ans,wrong;
		wrong=0;
		for(j=0;j<len2;j++)
		{
			char cmp;
			cmp=guess[j];
			int tmp=0;
			for(k=0;k<len1;k++)
			{
				if(cmp==str[k])
				{
					word[k]=0;
					tmp=1;
				}
				if(tmp==0 && k==len1-1)
					wrong++;
			}
			if(wrong>=7)
			{
				ans=-1;
				break;
			}
			if(check(word,len1))
			{
				ans=1;
				break;
			}
		}
		if(wrong<7 && !check(word,len1))
			ans=0;
		if(ans==1)
			cout<<"You win."<<endl;
		if(ans==0)
			cout<<"You chickened out."<<endl;
		if(ans==-1)
			cout<<"You lose."<<endl;

	}
	return 0;
}

