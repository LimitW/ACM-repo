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

map<int, string> mp;

int main(){
    int T; scanf("%d", &T);
    while(T--){
        mp.clear();
        int n; scanf("%d", &n); getchar();
        char k[200];
        for(int i = 0; i < n; ++i){
            gets(k);
            int l = strlen(k) - 5, y = 0, len = strlen(k);
            for(int j = l + 1; j < len; ++j){
                y = y * 10 + (k[j] - '0');
            }
            k[l] = 0;
            mp[y] = string(k);
        }
        map<int, string>::iterator it = mp.end();
        while(--it != mp.begin())
            cout << it->second << '\n';
        cout << it->second << '\n';
    }
    return 0;
}
