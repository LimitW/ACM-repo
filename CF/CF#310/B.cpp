#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
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
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

int a[1010];

void rot(int i,int n,int r){
    if(r == 1){
        a[i] += 1;
        a[i] %= n;
    }
    else{
        a[i] -= 1;
        if(a[i] < 0) a[i] = n - 1;
    }
}


int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int s = 0; s < n; ++s){
        bool fail = 0;
        for(int i = 1; i <= n; ++i){
            if(i & 1) rot(i-1,n,1);
            else rot(i-1,n,-1);
        }
        for(int i = 0; i < n; ++i){
            if(a[i] != i){
                fail = 1;
                break;
            }
        }
        if(!fail){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
