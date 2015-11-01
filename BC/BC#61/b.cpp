#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, s, t;
    while(~scanf("%d%d%d", &n, &s, &t)){
        if((s == 1 && t == n) || (s == n && t == 1)) puts("0");
        else if(s == t) puts("-1");
        else if(t == 1 || t == n){
            if(t == 1){
                if(s == 2) puts("1");
                else puts("2");
            }
            else{
                if(s == n - 1) puts("1");
                else puts("2");
            }
        }
        else if(s == 1 || s == n) puts("1");
        else if(s == t - 1 || s == t + 1) puts("1");
        else puts("2");
    }
    return 0;
}
