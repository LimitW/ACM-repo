#include <iostream>

using namespace std;

const int k=2005;

int Lucy(int n)
{
	if(n>=50025002)
		return(n-5);
	else
	{
		while(n<50025002)
		{
			n+=k;
			n-=5;
		}
		return n-5;
	}
}

int main()
{
	int n;
	while(cin>>n)
	cout<<Lucy(n)<<endl;
	return 0;
}
