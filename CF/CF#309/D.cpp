#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
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
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

LL fib[52];
vector<int> ans;

int main(){
	fib[1] = 1; fib[2] = 1;
	for(int i = 3; i <= 50; ++i)
		fib[i] = fib[i-1] + fib[i-2];
	LL n,k; cin >> n >> k;
	for(int i = 1; i <= n; ){
		if(k > fib[n+1-i]){
			k -= fib[n+1-i];
			ans.push_back(i+1);
			ans.push_back(i);
			i += 2;
		}
		else {
			ans.push_back(i);
			++i;
		}
	}
	int sz = ans.size();
	for(int i = 0; i < sz; ++i)
		printf("%d%c",ans[i],i == sz-1?'\n':' ');
	return 0;
}

