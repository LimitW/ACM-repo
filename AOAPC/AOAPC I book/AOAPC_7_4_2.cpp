/*
 * Title:AOAPC_7_4_2.cpp
 * Author:LimitW
 * Date:2014.8.8
 * Source:AOAPC I
 * Note:素数环
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

int n;
int A[100],isp[200],vis[100];

bool is_prime(int x){
	int i;
	for(i=2;i*i<=x;i++){
		if(x % i == 0)
            return 0;
	}
	return 1;
}

void dfs(int cur){
	int i;
	if(cur == n && isp[A[0] + A[n-1]]){
		for(i=0;i<n;i++)
			printf("%d ", A[i]);
		printf("\n");
	}
	else
		for(i=2;i<=n;i++){
			if(!vis[i] && isp[i + A[cur-1]]){
				A[cur] = i;
				vis[i] = 1;
				dfs(cur+1);
				vis[i] = 0;
			}
		}
}

int main(){
	cin>>n;
	int i;
	for(i=2;i<=n*2;i++)
        isp[i] = is_prime(i); //生成素数表
	for(i=0;i<n;i++)
        A[i] = i + 1;
	memset(vis,0,sizeof(vis));
	dfs(1);
	system("pause");
	return 0;
}