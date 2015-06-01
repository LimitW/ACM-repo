/*
 * Title:The Suspects
 * Author:LimitW
 * Date:2014.8.2
 * Source:poj 1611
 * Note:数据结构 并查集
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

const int maxn = 3e5 + 10;

//算导 并查集
//parent[]存放元素x父节点
int parent[maxn];
int num[maxn];

//初始化集合元素，每元素独立为一个集合
/*void Make_Set(int x){
	parent[x] = x;
	rank[x] = 0;
}*/

//查找一个元素所在的集合，返回其父节点
int Find_Set(int x){
	if(parent[x] != x){
		parent[x] = Find_Set(parent[x]);
	}
	return parent[x];
}

void Union(int x,int y){
	x = Find_Set(x);
	y = Find_Set(y);
	if(x == y) return;
	parent[y] = x;
	num[x] += num[y];
}

int main(){
	int n,m;
	while(cin>>n>>m&&(n||m)){
		int i;
		for(i=0;i<n;i++){
			parent[i] = i;
			//rank[i] = 0;
			num[i] = 1;
		}
		for(i=0;i<m;i++){
			int groupn;
			scanf("%d",&groupn);
			int a,b;
			if(groupn>=1)
				scanf("%d",&a);
			groupn--;
			for(;groupn>0;groupn--){
				scanf("%d",&b);
				Union(a,b);
			}
		}
		int k = Find_Set(0);
		printf("%d\n",num[k]);
	}
	return 0;
}