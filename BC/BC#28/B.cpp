//dfs
//Fibonacci is not prime
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

const int maxn = 1000000000;

int a[100];
int c = 2;
vector<int> b;

void init(){
	a[0] = 1; a[1] = 1;
	for( ; a[c-1] <= maxn; c++)
		a[c] = a[c-1] + a[c-2];
	a[--c] = 0;
}

bool dfs(int r,int x){
	if(x == 1) return 1;
	for(int i = r; i > 1; i--){
		if(x % a[i] == 0){
			if(dfs(i , x / a[i]))
				return 1;
		}
	}
	return 0;
}

int main(){
	init();
	int T; scanf("%d",&T);
	for(int kase = 0; kase < T; kase++){
		int n; scanf("%d",&n);
		if(n <= 1){
			printf("Yes\n");
			continue;
		}
		if(!dfs(c-1,n)) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
