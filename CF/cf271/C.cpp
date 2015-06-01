/************************************************
 * Title:
 * Author:LimitW
 * Date:
 * Source:
 * Note:
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

//BFS 31ms 200KB
struct point
{
    double x,y;
    int RotateN;
};

struct mat{
    point p[4],h[4];
    int ans;
    int State;
};

mat m[110];
bool vis[4000];

int getState(mat x)
{
    int s = x.p[0].RotateN * 1000 + x.p[1].RotateN * 100 + x.p[2].RotateN * 10 + x.p[3].RotateN;
    return s;
}

int getAns(mat x){
    int ans = 0;
    for(int i = 0; i < 4; i++)
        ans += x.p[i].RotateN;
    return ans;
}

double dist2(point a,point b)
{
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

point rotate(point a,point b){
    point c;
    c.x = b.x - (a.y - b.y);
    c.y = b.y + (a.x - b.x);
    c.RotateN = a.RotateN + 1;
    return c;
}

bool is_square(point a,point b,point c,point d){
    point m;
    m.x = (a.x + b.x + c.x + d.x) / 4;
    m.y = (a.y + b.y + c.y + d.y) / 4;
    point p[4];
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    if (dist2(m, p[0]) == 0) {
        return false;
    }
    for (int i = 0; i < 4; i++) {
        if (dist2(m, p[i]) != dist2(m, p[0])) {
        return false;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (dist2(p[i], p[j]) == 0) {
                return false;
            }
            double smul = (p[i].x - m.x) * (p[j].x - m.x) + (p[i].y - m.y) * (p[j].y - m.y);
            double vmul = (p[i].x - m.x) * (p[j].y - m.y) - (p[i].y - m.y) * (p[j].x - m.x);
            if (smul != 0 && vmul != 0) {
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 4; j++){
            scanf("%lf%lf%lf%lf",&m[i].p[j].x,&m[i].p[j].y,&m[i].h[j].x,&m[i].h[j].y);
            m[i].p[j].RotateN = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        memset(vis,0,sizeof(vis));
        queue<mat> q;
        m[i].ans = 0;
        m[i].State = 0;
        vis[m[i].State] = 1;
        q.push(m[i]);
        int fail = 1;
        while(!q.empty()){
            mat t = q.front();
            if(is_square(t.p[0],t.p[1],t.p[2],t.p[3])){
                fail = 0;
                printf("%d\n",t.ans);
                break;
            }
            q.pop();
            vis[t.State] = 1;
            for(int j = 0; j < 4; j++)
            {
                mat tmp = t;
                if(tmp.p[j].RotateN >= 3) continue;
                tmp.p[j] = rotate(tmp.p[j],tmp.h[j]);
                tmp.State = getState(tmp);
                tmp.ans = getAns(tmp);
                if(!vis[tmp.State])
                { q.push(tmp); vis[tmp.State] = 1; }
            }
        }
        if(fail) printf("-1\n");
    }
    return 0;
}

/* enum 78ms 0KB
struct point
{
	double x,y;
};

struct mat{
	point a[4],h[4];
};

mat p[110];

double dist(point a,point b)
{
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

point rotate(point a,point b){
	point c;
	c.x = b.x - (a.y - b.y);
	c.y = b.y + (a.x - b.x);
	return c;
}

bool is_sq(mat x) {
    point a = x.a[0], b = x.a[1], c = x.a[2], d = x.a[3];
    point m;
    m.x = (a.x + b.x + c.x + d.x) / 4;
    m.y = (a.y + b.y + c.y + d.y) / 4;
    point p[4];
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    if (dist(m, p[0]) == 0) {
        return false;
    }
    for (int i = 0; i < 4; i++) {
        if (dist(m, p[i]) != dist(m, p[0])) {
        return false;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (dist(p[i], p[j]) == 0) {
                return false;
            }
            double smul = (p[i].x - m.x) * (p[j].x - m.x) + (p[i].y - m.y) * (p[j].y - m.y);
            double vmul = (p[i].x - m.x) * (p[j].y - m.y) - (p[i].y - m.y) * (p[j].x - m.x);
            if (smul != 0 && vmul != 0) {
                return false;
            }
        }
    }
    return true;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
        for(int j = 0; j < 4; j++)
            scanf("%lf%lf%lf%lf",&p[i].a[j].x,&p[i].a[j].y,&p[i].h[j].x,&p[i].h[j].y);
	int ans = INF;
	for(int Case = 0; Case < n; Case++){
        int ans = INF;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                for(int k = 0; k < 4; k++)
                    for(int w = 0; w < 4; w++)
                    {
                        mat tmp = p[Case];
                        for(int i1 = 1; i1 <= i; i1++)
                            tmp.a[0] = rotate(tmp.a[0],tmp.h[0]);
                        for(int j1 = 1; j1 <= j; j1++)
                            tmp.a[1] = rotate(tmp.a[1],tmp.h[1]);
                        for(int k1 = 1; k1 <= k; k1++)
                            tmp.a[2] = rotate(tmp.a[2],tmp.h[2]);
                        for(int w1 = 1; w1 <= w; w1++)
                            tmp.a[3] = rotate(tmp.a[3],tmp.h[3]);
                        if(is_sq(tmp)){
                            ans = min(ans,i + j + k + w);
                        }
                    }
		if(ans == INF) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}*/