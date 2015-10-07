#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main(){
    int n, t;
    cin >> n >> t;
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    for(int i = 0; i < n; ++i)
        if(a[i] == b[i]) ++cnt;
    string c = a;
    int cnta = n - cnt - t, cntb = n - cnt - t;
    for(int i = 0; i < n; ++i){
        if(a[i] != b[i]){
            if(cnta > 0) --cnta;
            else if(cntb > 0) --cntb, c[i] = b[i];
            else{
                char x = a[i], y = b[i];
                if(x > y) swap(x, y);
                if(y - x == 1){
                    if(y == 'z') c[i] = 'x';
                    else c[i] = y + 1;
                }
                else {
                    c[i] = x + 1;
                }
            }
        }
    }
    for(int i = 0; i < n; ++i){
        if(a[i] == b[i]){
            if(cnta < 0){
                ++cnta;
                if(a[i] == 'z') c[i] = 'x';
                else c[i] = a[i] + 1;
            }
        }
    }
    int fa = 0, fb = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] != c[i]) ++fa;
        if(b[i] != c[i]) ++fb;
    }
    if(fa != fb || fa != t) cout << "-1" << '\n';
    else cout << c << '\n';
    return 0;
}

