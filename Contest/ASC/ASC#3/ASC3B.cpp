//============================================================================
// Name        : B.cpp
// Author      : LimitW
// Date        :
// Version     :
// Copyright   : ASC #3 B
// Description : Bigraph Maximal Matching , KM
//============================================================================

#include <iostream>
#include <iomanip>
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
#include <utility>
#include <bitset>
#include <functional>
#include <algorithm>
#include <fstream>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

struct son{
    int id , val;
}f[405];

bool g[405][405];
int lx[405] , ly[405];
bool vis[405];
int n;

int cmp_val(son a,son b){
    return a.val > b.val || (a.val == b.val && a.id < b.id);
}

bool match(int u){
    for(int v = 1; v <= n; v++)
    {
        if(g[u][v] && !vis[v]){
            vis[v] = true;
            if(ly[v] == -1 || match(ly[v])){
                ly[v] = u; lx[u] = v;
                return true;
            }
        }
    }
    return false;
}

void KM(){
    memset(lx,-1,sizeof(lx));
    memset(ly,-1,sizeof(ly));
    for(int i = 1; i <= n; i++)
    {
        int u = f[i].id;
        if(lx[u] == -1){
            memset(vis,0,sizeof(vis));
            match(u);
        }
    }
}

int main(){
    int T; scanf("%d",&T);
    while(T--)
    {
        memset(g,0,sizeof(g));
        scanf("%d",&n);
        for(int i = 1; i <= n; i++){
            f[i].id =  i;
            scanf("%d",&f[i].val);
        }
        for(int i = 1; i <= n; i++)
        {
            int m; scanf("%d",&m);
            for(int j = 0; j < m; j++)
            {
                int girl; scanf("%d",&girl);
                g[i][girl] = true;
            }
        }
        sort(f+1,f+n+1,cmp_val);
        KM();
        for(int i = 1; i < n; i++){
            if(lx[i] == -1) lx[i] = 0;
            printf("%d ", lx[i]);
        }
        printf("%d\n",lx[n] != -1? lx[n] : 0);
        printf("\n");
    }
    return 0;
}
