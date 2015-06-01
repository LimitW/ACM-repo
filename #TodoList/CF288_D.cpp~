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

const int maxn = 2e5 + 4;

int ind[64*64] , otd[64*64] , vis[64*64];
vector<int> ans;
vector<int> g[maxn];

void dfs(int u){
	while(!g[u].empty()){
		int v = g[u].back();
		g[u].pop_back();
		dfs(v);
	}
	ans.push_back(u);
	return ;
}

int val(char x){
	if(x <= 'z' && x >= 'a') return x - 'a';
	else if(x <= 'Z' && x >= 'A') return x - 'A' + 26;
	return x - '0' + 52;
}

char rev(int x){
	if(x <= 25 && x >= 0) return (char) (x + 'a');
	else if(x <= 51 && x >= 26) return (char) (x - 26 + 'A');
	return (char) (x - 52 + '0');
}

void print(int x){
	printf("%c",rev(x));
}

int main(){
	int n; scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		string s; cin >> s;
		int pre = val(s[0]) * 64 + val(s[1]) , suf = val(s[1]) * 64 + val(s[2]);
		otd[pre]++;	ind[suf]++;
		g[pre].push_back(suf);
	}
	int fail = 0 , s = -1 , t  = -1;
	for(int i = 0; i < 64 * 64; i++){
		if(ind[i] == otd[i]) continue;
		else if(ind[i] == otd[i] + 1){
			if(t == -1) t = i;
			else { fail = 1; break; }
		}
		else if(ind[i]  + 1 == otd[i]){
			if(s == -1) s = i;
			else { fail = 1; break; }
		}
		else{
			printf("NO\n"); return 0;
		}
	}
	if(fail) { printf("NO\n"); return 0; }
	if(s == -1){
		for(int i = 0 ; i < 64 * 64; i++)
			if(otd[i] > 0 && i != t) { s = i; break; }
	}
	dfs(s);
	if(ans.size() != n+1) { printf("NO\n"); return 0; }
	printf("YES\n");
	reverse(ans.begin(),ans.end());
	print(ans[0] / 64);
	for(int i = 0; i < ans.size(); i++)
		print(ans[i] % 64);
	puts("");
	return 0;
}
