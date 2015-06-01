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

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

map< int , vector<int> > mp;

int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		int v; scanf("%d",&v);
		mp[v].push_back(i+1);
	}
	int ans = min(mp[1].size() , mp[2].size());
	if(mp[3].size() < ans) ans = mp[3].size();
	printf("%d\n",ans);
	for(; ans > 0; ans--)
	{
		printf("%d %d %d\n",mp[1][ans-1],mp[2][ans-1],mp[3][ans-1]);
	}
    return 0;
}
