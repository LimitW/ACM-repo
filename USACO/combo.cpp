/*
ID: LimitW
PROG: combo
LANG: C++11
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
#include <fstream>

using namespace std;

const int INF = 0x3f3f3f3f;

int lock[2][3];
int n;
bool ok1(int a,int b){
    return (abs(a-b) >= n-2) || (abs(a-b) <= 2);
}
bool all_ok(int a,int b,int c,int x,int y,int z){
    return ok1(a,x) && ok1(b,y) && ok1(c,z);
}

int main(){
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);
    scanf("%d",&n);
    for(int j = 0; j < 2; j++)
        for(int i = 0; i < 3; i++)
            scanf("%d",&lock[j][i]);
    int ans = 0;
    for(int a1 = 1; a1 <= n; a1++)
        for(int a2 = 1; a2 <= n; a2++)
            for(int a3 = 1; a3 <= n; a3++)
            {
                if(all_ok(a1,a2,a3,lock[0][0],lock[0][1],lock[0][2]) || all_ok(a1,a2,a3,lock[1][0],lock[1][1],lock[1][2]))
                    ans++;
            }
    printf("%d\n",ans);
    return 0;
}
