#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

long long a, b, c;
long long p, q, m, k;
long long pm, kq;

pair<long long, long long> f(long long a, long long b, long long c){
    long long del = b * b - 4 * a * c;
    if(del < 0)
        return make_pair(-1, -1);
    long long ddel = sqrt(del);
    if(ddel * ddel != del)
        return make_pair(-1, -1);
    long long l, r;
    l = (-b - ddel) / 2 / a;
    if(l * 2 * a != -b - ddel) l = -1;
    r = (ddel - b) / 2 / a;
    if(r * 2 * a != -b + ddel) r = -1;
    return make_pair(l, r);
}

bool ok(long long x, long long y){
    if(x < 0 || y < 0) return false;
    if(x % k == 0 && y % m == 0) return true;
    if(x % m == 0 && y % k == 0) return true;
    return false;
}

int main(){
    int T; scanf("%d", &T);
    for(int kase = 1; kase <= T; ++kase){
        scanf("%I64d%I64d%I64d", &a, &b, &c);
        bool flag = 0;
        for(int i = 1; i * i <= c; ++i){
            if(c % i != 0) continue;
            k = i, m = c / i;
            pair<long long, long long> res = f(1, -b, k * m * a);
            if(ok(res.first, b - res.first) || ok(res.second, b - res.second)){
                puts("YES");
                flag = 1;
                break;
            }
        }
        if(!flag)
            puts("NO");
    }
    //system("pause");
    return 0;
}
