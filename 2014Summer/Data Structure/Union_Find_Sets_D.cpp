/*
 * Title:Wireless Network
 * Author:LimitW
 * Date:2014.8.2
 * Source:poj 2236
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

const int maxn = 1e3 +10;

int x[maxn],y[maxn];
int status[maxn];

int parent[maxn];

int distance2(int x1,int y1,int x2,int y2){
	return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

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
}

int main(){
	memset(status,0,sizeof(status));
	int n,d;
	scanf("%d%d",&n,&d);
	int i;
	for(i=0;i<n;i++){
		parent[i] = i;
	}
	for(i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
	char op;
	while(cin>>op){
		if(op == 'O'){
			int repairNo;
			scanf("%d",&repairNo);
			status[repairNo-1] = 1;
            for(i=0;i<n;i++){
                if(i != repairNo-1 && status[i]){
                    int k = distance2(x[i],y[i],x[repairNo-1],y[repairNo-1]) - d*d;
                    if(k<=0) Union(i,repairNo-1);
                }
            }
        }
		if(op == 'S'){
			int findNo1,findNo2;
			scanf("%d%d",&findNo1,&findNo2);
			if(status[findNo1-1] && status[findNo2-1] && Find_Set(findNo1-1) == Find_Set(findNo2-1))
                printf("SUCCESS\n");
			else printf("FAIL\n");
		}
	}
	return 0;
}