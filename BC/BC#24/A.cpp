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

int mpow(int n){
	int ans = 1;
	for(int i = 0; i < n; i++) ans *= 2;
	return ans;
}

int rev(int x){
	if(x == 0) return 0;
	string s = "";
	int ans = x , t = 0 , p = 0;
	while(ans > 0){
		char bit = '0' + ans % 2;
		ans >>= 1;
		s += bit;
	}
	while(s[t] == '0') t++;
	for(int i = s.length() - 1; i >= t; i--){
		ans += (s[i]-'0') * mpow(p);
		p++;
	}
	return ans;
}

int main(){
	int T; scanf("%d",&T);
	for(int i = 0;i < T; i++){
		int x; scanf("%d",&x);
		printf("%d\n",rev(x));
	}
    return 0;
}

