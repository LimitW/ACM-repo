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
const int maxn = 1e6+10;

struct edge{
    int next,to;
}node[maxn];
int head[maxn];
int ans = 0;

int dfs(int now)
{
    int first = 0,second = 0,l;
    int p = head[now];
    while(p){
        l = dfs(node[p].to) +1;
        if(l > first){ second = first; first = l; }
        else if(l > second) second = l;
        p = node[p].next;
    }
    ans = max(first+second,ans);
    return first;
}

int main(){
    int n;
    scanf("%d",&n);
    memset(head,0,sizeof(head));
    for(int i = 1; i < n; i++)
    {
        int to,from;
        scanf("%d%d",&from,&to);
        node[i].to = to;
        node[i].next = head[from];
        head[from] = i;
    }
    dfs(1);
    cout << ans << endl;
	return 0;
}