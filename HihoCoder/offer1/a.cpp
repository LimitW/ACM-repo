#include <bits/stdc++.h>

using namespace std;

int vis[10];

bool check(){
	int row = vis[0] + vis[1] + vis[2];
	for(int i = 0; i < 3; ++i){
		if(row != vis[i*3] + vis[i*3+1] + vis[i*3+2])
			return false;
	}
	row = vis[0] + vis[3] + vis[6];
	for(int i = 0; i < 3; ++i){
		if(row != vis[i] + vis[i+3] + vis[i+6])
			return false;
	}
	if(vis[0] + vis[8] != vis[2] + vis[6])
		return false;
	return true;
}

int hs[10];
int ans;

int nxt[10], sz;
int res[10];

void dfs(int nt){
	if(ans > 1) return;
	if(nt == sz){
		if(check()){
			++ans;
			for(int i = 0; i < 10; ++i)
				res[i] = vis[i];
		}
		return;
	}
	for(int j = 1; j <= 9; ++j){
		if(!hs[j]){
			vis[nxt[nt]] = j, hs[j] = 1;
			dfs(nt + 1);
			vis[nxt[nt]] = hs[j] = 0;
		}
	}
}

int main(){
	memset(hs, 0, sizeof(hs));
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j){
			cin >> vis[3 * i + j];
			++hs[vis[3 * i + j]];
		}
	sz = 0;
	for(int i = 0; i < 9; ++i){
		if(!vis[i]) nxt[sz++] = i;
	}
	dfs(0);
	if(ans == 1){
		for(int i = 0; i < 3; ++i){
			printf("%d %d %d\n", res[i*3], res[i*3+1], res[i*3+2]);
		}
	}
	else if(ans > 1) puts("Too Many");
	return 0;
}

