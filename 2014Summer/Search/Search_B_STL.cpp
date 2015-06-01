/*
 * Title:Jugs
 * Author:LimitW
 * Date:2014.8.5
 * Source:poj 1606
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

const int maxn = 100 + 10;

string output[7] = {"","fill A","fill B","pour A B","pour B A","empty A","empty B"};

struct Node{
	int a,b;
};

struct Path{
	int a,b,opr;
}path[maxn][maxn];

int vis[maxn][maxn];
int Ca,Cb,N;

void print(int x,int y);
void bfs(){
	queue <Node> q;
	Node t;
	t.a = 0;
	t.b = 0;
	vis[t.a][t.b] = 1;
	q.push(t);
	while(!q.empty()){
		Node tmp = q.front();
		if(tmp.b == N){
			print(tmp.a,tmp.b);
			return;
		}
		q.pop();
		Node op = tmp;

		op.a = Ca;
		op.b = tmp.b;
		if(!vis[op.a][op.b]){
			vis[op.a][op.b] = 1;
			q.push(op);
			path[op.a][op.b].a = tmp.a;
			path[op.a][op.b].b = tmp.b;
			path[op.a][op.b].opr = 1;
 		}

		op.a = tmp.a;
		op.b = Cb;
		if(!vis[op.a][op.b]){
			vis[op.a][op.b] = 1;
			q.push(op);
			path[op.a][op.b].a = tmp.a;
			path[op.a][op.b].b = tmp.b;
			path[op.a][op.b].opr = 2;
 		}

		if(tmp.a + tmp.b <= Cb){
			op.a = 0;
			op.b = tmp.a + tmp.b;
		}
		else{
			op.a = tmp.a - (Cb - tmp.b);
			op.b = Cb;
		}
		if(!vis[op.a][op.b]){
			vis[op.a][op.b] = 1;
			q.push(op);
			path[op.a][op.b].a = tmp.a;
			path[op.a][op.b].b = tmp.b;
			path[op.a][op.b].opr = 3;
 		}

		if(tmp.a + tmp.b <= Ca){
			op.b = 0;
			op.a = tmp.a + tmp.b;
		}
		else{
			op.b = tmp.a - (Ca - tmp.b);
			op.a = Ca;
		}
		if(!vis[op.a][op.b]){
			vis[op.a][op.b] = 1;
			q.push(op);
			path[op.a][op.b].a = tmp.a;
			path[op.a][op.b].b = tmp.b;
			path[op.a][op.b].opr = 4;
 		}
		
		op.a = 0;
		op.b = tmp.b;
		if(!vis[op.a][op.b]){
			vis[op.a][op.b] = 1;
			q.push(op);
			path[op.a][op.b].a = tmp.a;
			path[op.a][op.b].b = tmp.b;
			path[op.a][op.b].opr = 5;
 		}

		op.a = tmp.a;
		op.b = 0;
		if(!vis[op.a][op.b]){
			vis[op.a][op.b] = 1;
			q.push(op);
			path[op.a][op.b].a = tmp.a;
			path[op.a][op.b].b = tmp.b;
			path[op.a][op.b].opr = 6;
 		}
	}
}

void print(int x,int y){
	if(x == 0 && y == 0){
		return;
	}
	int nx = path[x][y].a;
	int ny = path[x][y].b;
	print(nx,ny);
	cout<<output[path[x][y].opr]<<endl;
}

int main(){
	while(cin>>Ca>>Cb>>N){
		memset(vis,0,sizeof(vis));
		memset(path,0,sizeof(path));
		bfs();
		cout<<"success"<<endl;
	}
	return 0;
}