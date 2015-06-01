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
#include <utility>
#include <bitset>
#include <algorithm>

using namespace std;
const int maxn = 100+5;
#define pii pair<int,int>
pair<int,pii> d[maxn];

bool cmp(pair<int,pii> a, pair<int,pii> b){
	return (a.first > b.first) || (a.first == b.first && a.second.first < b.second.first) || (a.first == b.first && a.second.first == b.second.first && a.second.second < b.second.second);
}

int main(){
	int n;
	while(scanf("%d",&n) == 1){
	for(int i = 0; i< n; i++){
		int f,s; scanf("%d%d",&f,&s);
		d[i] = make_pair(f - s, make_pair(s,i));
	}
	sort(d,d+n,cmp);
	for(int i = 0; i < n; i++){
		printf("%d%c",d[i].second.second,i == n-1? '\n' : ' ');
	}
	}
	return 0;
}

