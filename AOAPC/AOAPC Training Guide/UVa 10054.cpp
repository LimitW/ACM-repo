//============================================================================
// Name        : UVa 10054.cpp
// Author      : LimitW
// Date        : 2014.11.4
// Version     :
// Copyright   : UVa 10054 AOAPC
// Description : Eulerian Circuit
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
const int maxn = 1e3 + 10;

int mp[60][60];
int deg[60];
stack<pii> st;

void euler(int u){
    for(int v = 1; v <= 50; v++)
    {
        if(mp[u][v])
        {
            mp[u][v]--; mp[v][u]--;
            euler(v);
            st.push(make_pair(u,v));
        }
    }
}

int main(){
    int T; scanf("%d",&T);
    for(int CaseNo = 1; CaseNo <= T; CaseNo++){
        memset(mp,0,sizeof(mp));
        memset(deg,0,sizeof(deg));
        printf("Case #%d\n",CaseNo);
        int n; scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            int u , v;
            scanf("%d%d",&u,&v);
            mp[u][v]++; mp[v][u]++; //There are cases that edges are repeating
            deg[u]++; deg[v]++;
        }
        int fail = 0;
        for(int i = 1; i <= 50; i++)
        {
            if(deg[i] % 2 == 1){
                fail = 1; break;
            }
        }
        if(fail){
            printf("some beads may be lost\n");
            if(CaseNo != T) printf("\n");
            continue;
        }
        for(int i = 1; i <= 50; i++){
            if(deg[i]) { euler(i); break; }
        }
        for(int i = 0; i < n; i++)
        {
            printf("%d %d\n",st.top().first,st.top().second);
            st.pop();
        }
        if(CaseNo != T) printf("\n");
    }
    return 0;
}
