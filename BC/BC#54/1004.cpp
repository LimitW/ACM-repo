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

int euler(int x){
	int res = x;
	for(int i = 2; i * i <= x; ++i){
		if(x % i == 0){
			res = res / i * (i - 1);
			while(x % i == 0) x /= i;
		}
	}
	if(x > 1) res = res / x * (x - 1);
	return res;
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int n; cin >> n;
		cout << euler(n + 1) << '\n';
	}
	return 0;
}


