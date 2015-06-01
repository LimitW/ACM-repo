#include <iostream>
#include <iomanip>
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
#include <utility>
#include <bitset>
#include <functional>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
	long long n;
	int kase = 0;
	while(cin >>n)
	{
		vector<long long> p,ans;
		for(long long i = 1; i <= sqrt(n); i++)
			if(n % i == 0) {
				p.push_back(i);
				if(n/i != i) p.push_back(n/i);
		}
		sort(p.begin(),p.end());
		unique(p.begin(),p.end());
		for(int i = 0; i < p.size(); i++)
			if((p[i]^n) <= n && (p[i]^n) > 0 && __gcd(p[i]^n,n) == p[i]) ans.push_back(p[i]^n);
		sort(ans.begin(),ans.end());
		unique(ans.begin(),ans.end());
		printf("Case #%d:\n",++kase);
		printf("%d\n",ans.size());
		for(int i = 0; i < ans.size(); i++)
			printf("%I64d%c",ans[i],i == ans.size() -1 ?  '\n':' ');
		if(!ans.size()) puts("");
	}
    return 0;
}
