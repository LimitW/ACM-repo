/*
 * Title:Jugs
 * Author:LimitW
 * Date:2014.7.30
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

struct Node{
	int a,b;
	int oper;
	int pre;
}q[maxn * maxn];

string output[7] = {"","fill A","fill B","pour A B","pour B A","empty A","empty B"};

int Ca,Cb,N;

int head,tail;

int ans[maxn*maxn];

int vis[maxn][maxn];

void print(){
	int i = 1;
	ans[0]  = q[head].oper;
	head = q[head].pre;
	while(head){
		ans[i++] = q[head].oper;
		head = q[head].pre;
	}
	int j;
	for(j = i-1;j>=0;j--)
		cout<<output[ans[j]]<<endl;
	cout<<"success"<<endl;
}

void bfs(){
	head = tail = 0;
	q[tail].a = 0;
	q[tail].b = 0;
	vis[0][0] = 1;
	tail++;
	while(head != tail){
		Node t;
		if(q[head].b == N){
			print();
			return;
		}
		//fill a
		t.a = Ca;
		t.b = q[head].b;
		if(!vis[t.a][t.b]){
			vis[t.a][t.b] = 1;
			t.oper = 1;
			t.pre = head;
			q[tail++] = t;
		}
		//fill b
		t.a = q[head].a;
		t.b = Cb;
		if(!vis[t.a][t.b]){
			vis[t.a][t.b] = 1;
			t.oper = 2;
			t.pre = head;
			q[tail++] = t;
		}
		//pour a b
		if(q[head].a + q[head].b <= Cb){
			t.a = 0;
			t.b = q[head].a + q[head].b;
		}
		else{
			t.a = q[head].a - (Cb - q[head].b);
			t.b = Cb;
		}
		if(!vis[t.a][t.b]){
			vis[t.a][t.b] = 1;
			t.oper = 3;
			t.pre = head;
			q[tail++] = t;
		}
		//pour b a
		if(q[head].a + q[head].b <= Ca){
			t.b = 0;
			t.a = q[head].a + q[head].b;
		}
		else{
			t.b = q[head].b - (Ca - q[head].a);
			t.a = Ca;
		}
		if(!vis[t.a][t.b]){
			vis[t.a][t.b] = 1;
			t.oper = 4;
			t.pre = head;
			q[tail++] = t;
		}
		//empty a
		t.a = 0;
		t.b = q[head].b;
		if(!vis[t.a][t.b]){
			vis[t.a][t.b] = 1;
			t.oper = 5;
			t.pre = head;
			q[tail++] = t;
		}
		//empty b
		t.a = q[head].a;
		t.b = 0;
		if(!vis[t.a][t.b]){
			vis[t.a][t.b] = 1;
			t.oper = 6;
			t.pre = head;
			q[tail++] = t;
		}
		head++;
	}
}

int main(){
	while(cin>>Ca>>Cb>>N){
		memset(vis,0,sizeof(vis));
		bfs();
	}
	return 0;
}