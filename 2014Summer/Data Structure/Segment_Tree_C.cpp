/*
 * Title:Buy Tickets
 * Author:LimitW
 * Date:2014.8.15
 * Source:poj 2828
 * Note:线段树 单点更新
   思路：倒序插入.插入一点即使其前面有pos个空位,node[i]记录该节点共有多少空位
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

struct TNode
{
	int pos,value;
}p[200010];

int node[200010<<2];

void buildtree(int i,int left,int right){
	node[i] = right - left + 1;
	if(left == right) return;
	int mid = (left + right) >> 1;
	buildtree(i << 1,left,mid);
	buildtree(i << 1 | 1,mid+1,right);
}

int query(int i,int pos,int left,int right){
	node[i]--;
	if(left == right) return left;
	int mid = (left + right) >> 1;
	if(node[i<<1] >= pos) return query(i<<1,pos,left,mid);
	else return query(i<<1|1,pos-node[i<<1],mid+1,right);
}

int main(){
	int n;
	int num[200010];
	memset(num,0,sizeof(num));
	while(scanf("%d",&n) != EOF){
		int i;
		for(i=0;i<n;i++){
			scanf("%d%d",&p[i].pos,&p[i].value);
		}
		buildtree(1,1,n);
		for(i=n-1;i>=0;i--){
			num[query(1,p[i].pos+1,1,n)] = p[i].value;
		}
		for(i=1;i<n;i++)
			printf("%d ",num[i]);
		printf("%d\n",num[n]);
	}
	return 0;
}