/*
ID: LimitW
PROG: dualpal
LANG: C++11
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <fstream>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	int n,s;
	while(scanf("%d%d",&n,&s) != EOF)
	{
		int pre = s;
		for(int i = 0; i < n; i++)
			for(int t = pre+1; ; t++)
			{
				int count = 0;
				for(int b = 2; b <= 10; b++)
				{
					int tmp = t; string s = "";
					while(tmp > 0)
					{
						int bit = tmp % b; tmp /= b;
						s = (char) (bit+'0') + s;
					}
					int flag = 1;
					for(int l = 0; l < s.length()/2; l++)
						if(s[l] != s[s.length()-1-l])
						{ flag = 0; break; }
					if(flag) count++;
				}
				if(count >= 2)
				{ pre = t; printf("%d\n",pre); break; }
			}
	}
    return 0;
}
