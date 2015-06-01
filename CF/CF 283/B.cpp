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

string s;
int bit[2010] , ans[1010] , Ans[1010];
int main(){
	int n; scanf("%d",&n);
	cin >> s;
	for(int i = 0; i < n; i++){
		bit[i] = s[i] - '0';
		bit[i+n] = bit[i];
		Ans[i] = 9;
	}
	for(int i = 0; i < n; i++){
		int x = (10 - bit[i]) % 10;
		bool ok = 0;
		for(int j = 0; j < n; j++){
			ans[j] = (bit[i+j] + x) % 10;
			if(ans[j] < Ans[j]) ok = 1;
			if(ans[j] > Ans[j] && !ok) break;
		}
		if(ok) for(int j = 0; j < n; j++) Ans[j] = ans[j];
	}
	for(int i = 0; i < n; i++)
		printf("%d",Ans[i]);
	puts("");
    return 0;
}
