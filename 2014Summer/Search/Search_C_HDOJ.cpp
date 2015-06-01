/*
 * Title:Eight
 * Author:LimitW
 * Date:2014.8.8
 * Source:hdoj 1043
 * Note:八数码问题 单向bfs+hash超时 需A*
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
#define M 600000
using namespace std;

const int fac[]={1,1,2,6,24,120,720,5040,40320,362880}; // 0-9阶乘
const int dir[4][2] = {-1,0,1,0,0,-1,0,1};
const char print_d[5] = "udlr";

int hash[M];
int flag;
struct node
{
	int x,y;
	int pre;
	int opr;
	char now[10];
	int hash_statu;
}q[500000];
char Map[10];

int check(node t){
	return strcmp(t.now,"123456789");
}

void print(node t){
    if(t.pre != -1)
		print(q[t.pre]);
	if(t.opr != -1)
		cout<<print_d[t.opr];
}

int get_hash(char *s) // Cantor展开
{
    int sum=0;
    for(int i=0;i<9;i++)
    {
        int num=0;
        for(int j=i+1;j<9;j++)
          if(s[j]<s[i])
            num++;
        sum+=(num*fac[9-i-1]);
    }
    return sum;
}

void bfs(int x,int y){
	memset(hash,0,sizeof(hash));
	flag = 0;
	int head=0,rear=0;
	node init;
	init.x = x; init.y = y;
	init.pre = -1;
	init.opr = -1;
	int i;
	for(i=0;i<9;i++)
		init.now[i] = Map[i];
	init.now[9] = '\0';
	init.hash_statu = get_hash(init.now);
	hash[init.hash_statu] = 1;
	q[rear++] = init;
	while(head < rear){
		node t = q[head];
		if( check(t) == 0 ) { flag = 1; print(t); return; }
        int d;
        for(d=0;d<4;d++){
            node tmp = t;
            int nx = tmp.x + dir[d][0], ny = tmp.y + dir[d][1];
            if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3){
                tmp.now[3*t.x+t.y] = tmp.now[3*nx+ny]; tmp.now[3*nx+ny] = '9';
                tmp.opr = d; tmp.pre = head; tmp.hash_statu = get_hash(tmp.now);
                tmp.x = nx; tmp.y = ny;
                if(!hash[tmp.hash_statu]){
                    q[rear++] = tmp;
                    hash[tmp.hash_statu] = 1;
                }
            }
        }
        head++;
    }
}

int main(){
	while(cin>>Map[0]){
		int i;
		int x0,y0;
		if(Map[0] == 'x'){ x0 = 0; y0 = 0;}
		for(i=1;i<9;i++){
			cin>>Map[i];
			if(Map[i]=='x'){
				x0 = i / 3;
				y0 = i % 3;
				Map[i] = '9';
			}
		}

		bfs(x0,y0);
		if(flag) printf("\n");
		else printf("unsolvable\n");
    	}
	return 0;
}