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

int a[10][10];
int b[2000] , c = 0;

void dfs(int front,int cur,int tar){
	if(cur == tar) {
		b[c++] = front; return;
	}
	for(int i = front % 10; i > 0; i--){
		if(!a[front % 10][i]) continue;
		dfs(front*10+i,cur+1,tar);
	}
}

int main(){
	memset(a,0,sizeof(a));
	for(int i = 1; i < 10; i++) {
		a[i][1] = 1; a[i][i] = 1;
	}
	a[4][2] = 1; a[6][3] = 1; a[6][2] = 1; a[8][4] = 1; a[8][2] = 1; a[9][3] = 1;
	for(int len = 1; len  < 10; len++)
		for(int i = 1; i < 10; i++) dfs(i,1,len);
	//cout << c << endl;
	sort(b,b+c);
	int T; scanf("%d",&T);
	for(int kase = 0; kase < T; kase++){
		int l , r; scanf("%d%d",&l,&r);
		int x = upper_bound(b,b+c,l) - b , y = upper_bound(b,b+c,r) - b;
		int ans = y - x;
		if(x > 0 && b[x-1] == l) ans++;
		printf("%d\n",ans);
	}
    return 0;
}

