#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <bitset>
#include <functional>
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>
const int INF = 0x3f3f3f3f;

bool is_prime(int x){
    for(int i  = 2; i * i <= x; i++)
        if(x % i == 0) return 0;
    return 1;
}

bool Prime[10010];
vector<int> v;

int main(){
    for(int i = 1; i <= 10000; i++)
        if(is_prime(i)) {
        v.push_back(i); Prime[i] = 1;
        }
        else Prime[i] = 0;
    int x;
    while(scanf("%d",&x) != EOF){
        int ans = 0;
        for(int i = 1; i < v.size(); i++){
            if(v[i] >= x) continue;
            for(int j = i; j < v.size(); j++){
                if(x - (v[i] + v[j])  < v[j]) break;
                if( Prime[ x - v[i] - v[j]] ) ans++;
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}
