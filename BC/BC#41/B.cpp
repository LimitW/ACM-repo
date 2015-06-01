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
#include <fstream>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const long long INFL = 1LL << 62;
char s[200010];
map<string,int> mp;

long long gcd(long long a,long long b){
    return b == 0 ? a : gcd(b,a%b);
}

int main(){
    int T; scanf("%d",&T);
    for(int kase = 0; kase < T; ++kase){
        mp.clear();
    	int n; scanf("%d",&n);
        int o = 0 , e = 0;
        for(int i = 0; i < n; ++i){
            scanf("%s",s);
            ++mp[string(s)];
            if(strlen(s) % 2 == 0) o++;
            else e++;
        }
        int p = o * e , q = n * (n-1) / 2;
        for(map<string,int>::iterator it = mp.begin(); it != mp.end(); ++it){
            p += it->second * (it->second-1) / 2;
        }
        if(p == 0) puts("0/1");
        else {
        	int x = gcd(p,q);
        	printf("%d/%d\n",p/x,q/x);
        }
    }
    return 0;
}

