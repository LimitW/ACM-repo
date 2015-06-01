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
const int maxn = 1e5 + 10;
int a[maxn];

int main(){
	multiset<int> mp;
	int n; scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
		mp.insert(a[i]);
	}
	for(int i = 0; i < n-1; i++){
		int tmp; scanf("%d",&tmp);
		mp.erase(mp.lower_bound(tmp));
	}
	int f = *mp.begin();
	mp.clear();
	printf("%d\n",f);
	for(int i = 0; i < n; i++){
		mp.insert(a[i]);
	}
	mp.erase(mp.lower_bound(f));
	for(int i = 0; i < n-2; i++){
		int tmp; scanf("%d",&tmp);
		mp.erase(mp.lower_bound(tmp));
	}
	printf("%d\n",*mp.begin());
    return 0;
}
