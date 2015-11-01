#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > h[1010];
int a[110];

int main(){
    int n;
    while(~scanf("%d", &n)){
        for(int i = 0; i <= 1000; ++i) h[i].clear();
        for(int i = 0; i < n; ++i){
            scanf("%d", a + i);
        }
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                int v = abs(a[i] - a[j]);
                h[v].push_back(make_pair(i,j));
            }
        }
        bool flag = 0;
        for(int i = 0; i < n && !flag; ++i){
            if(h[a[i]].size() != 0){
                for(int j = 0; j < h[a[i]].size(); ++j){
                    if(h[a[i]][j].first != i && h[a[i]][j].second != i)
                    {    flag = 1; break; }
                }
            }
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
