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

pair<int,int> a[110];
vector<int> p;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i].first);
		a[i].second = i+1;
	}
	sort(a,a+n);
	int ans = 0;
	for(int i = 0; i < n; i++)
		if(k >= a[i].first)  { k -= a[i].first; ans++; p.push_back(a[i].second); }
		else break;
	printf("%d\n",ans);
	for(int i = 0; i < p.size() - 1; i++)
		printf("%d ",p[i]);
	if(ans > 0) printf("%d\n",p.back());
    return 0;
}
