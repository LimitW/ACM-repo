/*
 * Title:Lake Counting
 * Author:LimitW
 * Date:2014.7.29
 * Source:poj 2386
 * Note:dfs
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
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>

using namespace std;

const int maxn = 100 + 10;

const int dir[8][2] = {0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};

char farm[maxn][maxn];
bool Map[maxn][maxn];

int N,M;

void dfs(int x,int y){
	if(Map[x][y] == 0)
		return;
	Map[x][y] = 0;
	int i;
	for(i=0;i<8;i++){
		int nx = x + dir[i][0],ny = y + dir[i][1];
		if(nx < 0 || nx >= N || ny < 0 || ny >= M)
			continue;
		dfs(nx,ny);
	}
}

int main(){
	memset(Map,0,sizeof(Map));
	cin>>N>>M;
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<M;j++){
			cin>>farm[i][j];
			if(farm[i][j] == 'W')
				Map[i][j] = 1;
		}
	int ans = 0;
	for(i=0;i<N;i++)
		for(j=0;j<M;j++){
			if(Map[i][j] == 1){
				dfs(i,j);
				ans++;
			}
		}
	cout<<ans<<endl;
	return 0;
}