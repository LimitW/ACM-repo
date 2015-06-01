#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;

struct nct {
    int a[4];
    bool operator < (nct b) const {
        return (a[0] < b.a[0]) || (a[0] == b.a[0] && a[1] < b.a[1]) || (a[0] == b.a[0] && a[1] == b.a[1] && a[2] < b.a[2]) || (a[0] == b.a[0] && a[1] == b.a[1] && a[2] == b.a[2] && a[3] < b.a[3]);
    }
    bool operator == (nct b) const {
        return a[0] == b.a[0] && a[1] == b.a[1] && a[2] == b.a[2] && a[3] == b.a[3];
    }
};

vector<nct> al,ans;

int main(){
    int T; cin >> T;
    for(int kase = 1; kase <= T; ++kase){
        al.clear();
        int n,m; cin >> n >> m;
        printf("Case #%d:\n",kase);
        for(int i = 0; i < n + m; ++i){
            string s; cin >> s; s += '.';
            int tmp = 0 , cnt = 0 , l = s.length();
            nct x;
            for(int j = 0; j < l; ++j){
                if(s[j] == '.'){
                    x.a[cnt++] = tmp; tmp = 0; continue;
                }
                tmp = tmp * 10 + s[j] - '0';
            }
            if(i < n) al.push_back(x);
            else {
                ans.clear();
                for(int j = 0; j < n; ++j){
                    nct c;
                    for(int z = 0; z < 4; ++z){
                        c.a[z] = x.a[z] & al[j].a[z];
                    }
                    ans.push_back(c);
                }
                sort(ans.begin(),ans.end());
                int res = 1 , sz = ans.size();
                for(int j = 1; j < sz; ++j)
                    if(ans[j] == ans[j-1]) continue;
                    else ++res;
                printf("%d\n",res);
            }
        }
    }
    return 0;
}

