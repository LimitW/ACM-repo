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

const int INF = 0x3f3f3f3f;

int n,m;
int beginpx,beginpy,endpx,endpy;
int maze[110][110],fa[110][110],vis[110][110];
int last_dir[110][110];
int path[110*110];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
char name[4] = {'d','u','r','l'};

int bfs(int x,int y){
	memset(fa,0,sizeof(fa));
	memset(vis,0,sizeof(vis));
	memset(path,0,sizeof(path));
	memset(last_dir,0,sizeof(last_dir));
	queue<int> q;
	int u = x * m + y;
	q.push(u);
	while(!q.empty()){
		u = q.front();
		q.pop();
		x = u / m; y = u % m;
		if(x == endpx && y == endpy)
			return 1;
		for(int i = 0 ;i < 4; i++){
			int nx = x + dir[i][0] , ny = y + dir[i][1];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && maze[nx][ny] && !vis[nx][ny])
			{
				int v = nx * m + ny;
				q.push(v);
				vis[nx][ny] = 1;
				fa[nx][ny] = u;
				last_dir[nx][ny] = i;
			}
		}
	}
	return 0;
}

void print_path(int x,int y){
	int c = 0;
	for(;;){
		int fx = fa[x][y] / m;
		int fy = fa[x][y] % m;
		if(fx == beginpx && fy == beginpy)
        {
            path[c++] = last_dir[x][y];
			break;
        }
		path[c++] = last_dir[x][y];
		x = fx; y = fy;
	}
	while(c--)
		putchar(name[path[c]]);
    printf("\n");
}

int main(){
	cin >> n >> m;
	cin >> beginpx >> beginpy >> endpx >> endpy;
	for(int i = 0; i < n ; i++)
		for(int j = 0 ; j < m; j++)
			scanf("%d",&maze[i][j]);
	if(bfs(beginpx,beginpy))
		print_path(endpx,endpy);
	else
		printf("No solution\n");
	system("pause");
	return 0;
}
/*
6 5
0 0 5 4
1 1 0 1 1
1 0 1 1 1
1 0 1 0 0
1 0 1 1 1
1 1 1 0 1
1 1 1 1 1
*/