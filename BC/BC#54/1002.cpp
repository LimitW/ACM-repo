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

map<int, int> mp;

int main(){
    int T; scanf("%d", &T);
    while(T--){
        mp.clear();
        int n; scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            int v; scanf("%d", &v);
            int tmp = v;
            for(int j = 2; j * j <= v; ++j){
                while(tmp % j == 0){
                    ++mp[j];
                    tmp /= j;
                }
            }
            if(tmp != 1) ++mp[tmp];
        }
        map<int, int>::iterator it = mp.begin();
        long long ans = -1;
        if(it->second >= 2) ans = (long long)(it->first) * (long long)(it->first);
        else {
            if(it != mp.end()) ++it;
            if(it != mp.end()){
                ans = (long long)(it->first) * (long long)(mp.begin()->first);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
