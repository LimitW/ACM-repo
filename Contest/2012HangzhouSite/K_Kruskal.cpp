/*
 * Title:Outlets
 * Author:LimitW
 * Date:2014.8.4
 * Source:2012 HangZhouSite K
 * Note:Kruskal算法 最小生成树
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

int p[55];

struct Point{
	int x,y;
}point[55];

struct edge
{
	int Beginpoint,Endpoint;
	double edgeLength;
}e[55*55];

bool cmp(const edge a,const edge b){
	return a.edgeLength < b.edgeLength;
}

double d(Point a,Point b){
	return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

int find(int x){
	if(p[x] == x)
		return x;
	return find(p[x]);
}

int main(){
	int N;
	while(cin>>N && N){
		int NikeNo,AppleNo;
		scanf("%d%d",&NikeNo,&AppleNo);
		int i,j;
		int EdgeNo = 0;
		for(i=1;i<=N;i++){
			scanf("%d%d",&point[i].x,&point[i].y);
			for(j=1;j<i;j++){
				e[EdgeNo].Beginpoint = i;
				e[EdgeNo].Endpoint = j;
				e[EdgeNo++].edgeLength = d(point[i],point[j]);
			}
		}
		sort(e,e+EdgeNo,cmp);
		for(i=1;i<=N;i++) p[i] = i;
		double ans = d(point[NikeNo],point[AppleNo]);
	    p[AppleNo] = NikeNo;
	    int u,v;
	    for(i=0;i<EdgeNo;i++){
	    	u = find(e[i].Beginpoint);
	    	v = find(e[i].Endpoint);
	    	if(u!=v){
	    		p[v] = u;
	    		ans += e[i].edgeLength;
	    	}
	    }
	    printf("%.2lf\n",ans);
	}
	return 0;
}