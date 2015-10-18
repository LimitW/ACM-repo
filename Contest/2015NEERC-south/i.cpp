#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int cnt[110];

int main(){
    memset(cnt, 0, sizeof(cnt));
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; ++i){
        int v; cin >> v;
        ++cnt[v];
    }
    int ave = n / k;
    int ans = 0;
    for(int i = 1; i <= k; ++i){
        if(cnt[i] > ave){
            int tmp = cnt[i] - ave;
            ans += tmp;
            for(int j = i + 1; j <= k && tmp > 0; ++j){
                if(cnt[j] < ave){
                    int ch = min(tmp, ave - cnt[j]);
                    tmp -= ch;
                    cnt[j] += ch;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
