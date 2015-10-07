#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long quickpow(long long m,long long n){
    long long ans = 1;
    while(n){
        if(n&1) ans = ans * m % mod;
        n >>= 1;
        m = m * m % mod;
    }
    return ans;
}

int main(){
    long long n; cin >> n;
    long long ans = quickpow(3, 3 * n) - quickpow(7, n);
    ans = (ans + mod) % mod;
    cout << ans << '\n';
    return 0;
}
