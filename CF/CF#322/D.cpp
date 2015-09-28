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
const double pi = acos(-1.0);
const long double eps = 1e-9;
const int mod = 1e9 + 7;
const int maxn = (1 << 10) + 3;

int x[3], y[3];
char mp[210][210];

void paint(int i, int p, int bd, int a, int b){
	for(int j = x[i]; j < p; ++j){
		for(int k = 0; k < bd; ++k)
			mp[j][k] = 'A' + a;
		for(int k = bd; k < p; ++k)
			mp[j][k] = 'A' + b;
	}
}

int main(){
	int sz = 0, mx = -1;
	for(int i = 0; i < 3; ++i){
		cin >> x[i] >> y[i];
		if(x[i] > y[i]) swap(x[i], y[i]);
		sz += x[i] * y[i];
		mx = max(mx, max(x[i], y[i]));
	}
	int p = sqrt(sz * 1.0);
	if(p * p != sz || mx > p){
		puts("-1");
		return 0;
	}
	bool flag = 0;
	for(int i = 0; i < 3 && !flag; ++i){
		if(y[i] == p){
			int a = 0, b = 1;
			if(a == i) a = 2;
			if(b == i) b = 2;
			if(y[a] == p && y[b] == p && x[a] + x[b] == p - x[i]){
				flag = 1;
				for(int j = 0; j < p; ++j){
					for(int k = x[i]; k < x[i] + x[a]; ++k)
						mp[k][j] = 'A' + a;
					for(int k = x[i] + x[a]; k < p; ++k)
						mp[k][j] = 'A' + b;
				}
			}
			else if(x[a] == p - x[i] && x[b] == p - x[i] && y[a] + y[b] == p){
				flag = 1;
				paint(i, p, y[a], a, b);
			}
			else if(x[a] == p - x[i] && y[b] == p - x[i] && y[a] + x[b] == p){
				flag = 1;
				paint(i, p, y[a], a, b);
			}
			else if(y[a] == p - x[i] && x[b] == p - x[i] && x[a] + y[b] == p){
				flag = 1;
				paint(i, p, x[a], a, b);
			}
			else if(y[a] == p - x[i] && y[b] == p - x[i] && x[a] + x[b] == p){
				flag = 1;
				paint(i, p, x[a], a, b);
			}
			if(flag){
				for(int j = 0; j < p; ++j){
					for(int k = 0; k < x[i]; ++k){
						mp[k][j] = 'A' + i;
					}
				}
			}
		}
	}
	if(!flag) puts("-1");
	else{
		printf("%d\n", p);
		for(int i = 0; i < p; ++i){
			for(int j = 0; j < p; ++j)
				putchar(mp[i][j]);
			puts("");
		}
	}
    return 0;
}

