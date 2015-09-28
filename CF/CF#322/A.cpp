#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
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
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const long double eps = 1e-9;
const int mod = 1e9 + 7;
const int maxn = (1 << 10) + 3;

int main(){
    int a, b; cin >> a >> b;
    cout << min(a, b) << ' ' << (max(a, b) - min(a, b)) / 2 << '\n';
    return 0;
}
