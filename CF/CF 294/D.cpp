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

int key[26] , a[maxn];
map<long long,int> mp[26];

int main(){
	for(int i = 0; i < 26; i++) cin >> key[i];
	string s; cin >> s;
	int n  = s.length();
	long long sum = 0 , ans = 0;
	for(int i = 0; i < n; i++){
		a[i] = s[i] - 'a';
		sum += (long long) key[a[i]];
		ans += (long long) mp[a[i]][sum-key[a[i]]];
		mp[a[i]][sum]++;
	}
	printf("%lld\n",ans);
    return 0;
}
