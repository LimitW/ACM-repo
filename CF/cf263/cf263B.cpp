/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.8.27
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

const int maxn = 1e5;

long long c[26];
char s[maxn+10];

int main(){
    memset(c,0,sizeof(c));
    long long n,k;
    cin >> n >> k;
    cin >> s;
    for(int i = 0; i < n; i++){
        c[s[i]-'A']++;
    }
    sort(c,c+26);
    long long sum = 0;
    int t = 25;
    while(k > 0 && t >= 0){
        k -= c[t];
        if(k >= 0) sum = sum + (c[t]*c[t]);
        else sum = sum + ((k+c[t])*(k+c[t]));
        t--;
    }
    printf("%I64d\n", sum);
    return 0;
}