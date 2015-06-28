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

int main(){
	int n; string s;
	cin >> n;
	cin >> s;
	int a = 0 ,b = 0;
	for(int i = 0; i < n; ++i){
	    if(s[i] == '1') a++;
        else b++;
	}
	cout << n - 2*min(a,b) << '\n';
    return 0;
}
