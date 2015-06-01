/*
 * Title:AOAPC_7_4_3.cpp
 * Author:LimitW
 * Date:2014.8.8
 * Source:AOAPC I
 * Note:困难的串
*/

#include <iostream>
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
#include <bitset>
#include <algorithm>

using namespace std;
int n,L;
int cnt;
int S[80];
int dfs(int cur){
	int i,j,k;
	if(cnt++ == n){
		for(i=0;i<cur;i++)
			printf("%c",'A'+S[i]);
		printf("\n");
		return 0;
	}
	for(i=0;i<L;i++){
		S[cur] = i;
		int ok = 1;
		for(j=1;j*2<=cur+1;j++){
			int equal = 1;
			for(k=0;k<j;k++)
				if(S[cur-k] != S[cur-k-j]) { equal = 0; break; }
			if(equal) { ok = 0; break; }
		}
		if(ok) if(!dfs(cur+1)) return 0;
	}
	return 1;
}

int main(){
	cnt = 0;
	memset(S,0,sizeof(S));
	cin>>n>>L;
	dfs(1);
	system("pause");
	return 0;
}