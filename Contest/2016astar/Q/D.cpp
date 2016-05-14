#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

const int mod = 1e9 + 13;

char s[45];
map<string, int> mp;

int main(){
    int n;
    while(~scanf("%d", &n)){
        mp.clear();
    for(int i = 0; i < n; ++i){
        scanf("%s", s);
        sort(s, s + strlen(s));
        printf("%d\n", mp[(string)(s)]);
        mp[(string)(s)]++;
    }
    }
    return 0;
}
