/*
 * Title:The Game
 * Author:LimitW
 * Date:2014.8.6
 * Source:poj 1101
 * Note:bfs
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
const int maxn = 75 + 5;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
struct node
{
	int x,y;
	int is_line;
	int now_line;
};
char MAP[maxn][maxn];
int maze[maxn][maxn];
int vis[maxn][maxn];
int w,h;
int ans;

int bfs(int x1,int y1,int x2,int y2){
	ans = 10000;
	queue <node> q;
	node init;
	init.x = x1;
	init.y = y1;
	vis[init.x][init.y] = 1;
	init.is_line = -1;
	init.now_line = 0;
	q.push(init);
	while(!q.empty()){
		node t = q.front();
		if(t.x == x2 && t.y == y2)
			ans = t.now_line;
		q.pop();
		int i;
		for(i=0;i<4;i++){
            node tmp = t;
			int nx = tmp.x + dir[i][0], ny = tmp.y + dir[i][1];
			if(!vis[nx][ny] && nx <= w+1 && nx >= 0 && ny <= h+1 && ny >= 0){
				if(tmp.is_line != i) tmp.now_line++;
                if(tmp.now_line >= ans)
                    continue;
                vis[nx][ny] = 1;
                tmp.is_line = i; tmp.x = nx; tmp.y = ny;
                q.push(tmp);
			}
		}
	}
	return ans;
}

int main(){
	int CaseNo = 1;
	while(cin>>w>>h && !(w == 0 && h == 0)){
		memset(maze,0,sizeof(maze));
		int i,j;
		for(j=1;j<=h;j++){
            getchar();
			for(i=1;i<=w;i++){
				MAP[i][j] = getchar();
				if(MAP[i][j] == 'X')
					maze[i][j] = 1;
			}
        }
		for(i=0;i<=w+1;i++)
			for(j=0;j<=h+1;j++)
				vis[i][j] = maze[i][j];
		int x1,y1,x2,y2;
		int PairNo = 1;
		printf("Board #%d:\n",CaseNo++);
		while(cin>>x1>>y1>>x2>>y2 && !(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)){
            for(i=0;i<=w+1;i++)
			    for(j=0;j<=h+1;j++)
				    vis[i][j] = maze[i][j];
			maze[x1][y1] = vis[x1][y1] = 0; maze[x2][y2] = vis[x2][y2] = 0;
			bfs(x1,y1,x2,y2);
			if(ans == 10000) printf("Pair %d: impossible.\n",PairNo++);
			else printf("Pair %d: %d segments.\n",PairNo++,ans);
			maze[x1][y1] = vis[x1][y1] = 1; maze[x2][y2] = vis[x2][y2] = 1;
		}
		cout<<endl;
	}
	return 0;
}