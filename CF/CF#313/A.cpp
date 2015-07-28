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
const int mod = 1e9 + 7;

int main(){
	int n; cin >> n;
	bool flag = 0;
	for(int i = 0; i < n; ++i){
		int tmp; cin >> tmp;
		if(tmp == 1) flag = 1;
	}
	if(flag) cout << "-1" << endl;
	else cout << "1" << endl;
    return 0;
}

