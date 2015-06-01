/*
 * Title:Radar Installation
 * Author:LimitW
 * Date:2014.8.19
 * Source:poj 1328
 * Note:贪心
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

using namespace std;

struct bracket{
	double x1,x2;
}b[1010];

int cmp(bracket a,bracket b){
    if(a.x2 != b.x2)
    	return a.x2 < b.x2;
    else
    	return a.x1 > b.x1;
}

int main(){
	int n;
	double d;
	int CaseNo = 1;
	while(scanf("%d%lf",&n,&d) && (n || d)){
		int fail = 0;
		int i;
		for(i=0;i<n;i++){
			double x,y;
			scanf("%lf%lf",&x,&y);
			if(y > d){ fail = 1; }
			else{
				b[i].x1 = x - sqrt(d*d-y*y);
				b[i].x2 = x + sqrt(d*d-y*y);
			}
		}
		if(fail){
			printf("Case %d: -1\n",CaseNo++);
			continue;
		}
		sort(b,b+n,cmp);
		int ans = 1;
		double tmp = b[0].x2;
		for(i=1;i<n;i++){
			if(tmp <= b[i].x2 && tmp >= b[i].x1){
				continue;
			}
			else{
				ans++;
				tmp = b[i].x2;
			}
		}
		printf("Case %d: %d\n",CaseNo++,ans);
	}
	return 0;
}

/*错解
int vis[1010];

int cmp(Point a,Point b){
    return a.y > b.y;
}

double dis(Point a,Point b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int is_end(int n){
    int i;
    for(i=0;i<n;i++)
        if(!vis[i])
            return 0;
    return 1;
}

int main(){
	int n;
	double d;
	int CaseNo = 1;
	while(cin >> n >> d && (n || d)){
		memset(vis,0,sizeof(vis));
		int i;
		for(i=0;i<n;i++)
			cin>>p[i].x>>p[i].y;
		sort(p,p+n,cmp);
		if(p[0].y > d){
			printf("Case %d: -1\n",CaseNo++);
			continue;
		}
		int ans = 1;
		Point c;
		c.x = p[0].x; c.y = 0.0;
		vis[0] = 1;
		while(!is_end(n)){
            for(i=1;i<n;i++){
                if(dis(c,p[i]) <= d && !vis[i])
                    vis[i] = 1;
            }
            for(i=1;i<n;i++){
                if(!vis[i]){
                    vis[i] = 1;	ans++;
                    c.x = p[i].x;
                    break;
                }
            }
		}
		printf("Case %d: %d\n",CaseNo++,ans);
	}
	return 0;
}*/