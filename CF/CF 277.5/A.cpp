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

int a[3010];
vector<pii> v;
int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = n-1; i >= 0; i--)
	{
		int mapos = i;
		for(int j = i-1; j >= 0; j--)
			if(a[mapos] < a[j]) mapos = j;
		if(i != mapos) v.push_back(make_pair(mapos,i));
		swap(a[mapos],a[i]);
	}
	printf("%d\n",v.size());
	for(int i = 0; i < v.size(); i++)
		printf("%d %d\n",v[i].first,v[i].second);
	return 0;
}
