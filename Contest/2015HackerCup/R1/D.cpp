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

const int maxn = 2e5 + 5;

int id[maxn];
vector<int> v[maxn];

bool cmp(vector<int> a,vector<int> b){
	return a.size() > b.size();
}

int main(){
	freopen("corporate_gifting_example_input.txt","r",stdin);
	freopen("D.txt","w",stdout);
	int T; scanf("%d",&T);
	for(int kase = 1; kase <= T; kase++)
	{
		int n; scanf("%d",&n);
		for(int i = 0; i < n; i++) scanf("%d",id[i]);
		sort(id,id+n);
		for(int i = 0; i < n; i++)
			v[id[i]].push_back(i);
		sort(v,v+n,cmp);
		LL ans = 0;
		printf("Case #%d: %d\n",kase,ans);
	}
    return 0;
}

