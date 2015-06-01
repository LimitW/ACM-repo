/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.8.22
 * Source:AOAPC I
 * Note:表达式树
*************************************************/

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

const int INF = 0x3f3f3f3f;

const int maxn = 1000;

char s[maxn];
int lch[maxn],rch[maxn];//每个节点的左右编号和字符
char op[maxn];
int nc = 0; //节点数

//每次找到最后计算的运算符再递归建树
int build_tree(char* s,int x,int y){
	int i, c1 = -1, c2 = -1, p = 0;
	int u;
	if(y - x == 1){
		u = ++nc;
		lch[u] = rch[u] = 0;
		op[u] = s[x];
		return u;
	}
	for(i = x; i < y; i++){
		switch(s[i]){
			case '(': p++; break;
			case ')': p--; break;
			case '+': case '-': if(!p) c1 = i; break;
			case '*': case '/': if(!p) c2 = i; break;
		}
	}
	if(c1 < 0) c1 = c2;
	if(x1 < 0) build_tree(s,x+1,y-1);
	u = ++nc;
	lch[u] = build_tree(s,x,c1);
	rch[u] = build_tree(s,c1+1,y);
	op[u] = s[c1];
	return u;
}

int main(){
	return 0;
}