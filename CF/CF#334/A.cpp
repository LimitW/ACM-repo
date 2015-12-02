#include <bits/stdc++.h>

using namespace std;
int f(int x, int m, int w){
    return max(150 * x, (500 - 2 * m) * x - 50 * w);
}

int main(){
    int t[5], p[5];
    int sum = 0;
    for(int i = 0; i < 5; ++i){
        cin >> t[i];
    }
    for(int i = 0; i < 5; ++i){
        cin >> p[i];
    }
    for(int i = 0; i < 5; ++i){
        sum += f(i+1, t[i], p[i]);
    }
    int x, y; cin >> x >> y;
    sum += 100 *x - 50 * y;
    cout << sum << '\n';
    return 0;
}
