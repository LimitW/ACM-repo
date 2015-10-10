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

const int INF = 0x3f3f3f3f;
const int maxn = 100 + 3;

int a[20];

int main(){
    int T; scanf("%d", &T);
    while(T--){
        int n; scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        int tp = n;
        for(int i = n; i >= 0; --i){
            if(a[i] == tp) --tp;
        }
        cout << tp << '\n';
    }
    return 0;
}

