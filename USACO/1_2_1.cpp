/*
ID: LimitW
PROG: milk2
LANG: C++11
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <fstream>

using namespace std;

const int INF = 0x3f3f3f3f;

struct interval
{
	int x,y;
	bool operator < (const interval& a) const {
		if(x != a.x) return x < a.x;
		else return y < a.y;
	}
}a[5010];

int main(){
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int n;
    fin >> n;
    for(int i = 0; i < n; i++)
    	fin >> a[i].x >> a[i].y;
    sort(a,a+n);
    int ans1 = a[0].y - a[0].x , ans2 = 0;
    int tmp1 = ans1 , tmp2 = ans2;
    int l = a[0].x;
    int r = a[0].y;
    for(int i = 1; i < n; i++)
    {
        if(a[i].y <= r) continue;
    	if(a[i].x <= r)
            tmp1 = a[i].y - l;
    	else{
            tmp2 = a[i].x - r;
            l = a[i].x;
        }
        r = a[i].y;
        ans1 = max(ans1,tmp1);
        ans2 = max(ans2,tmp2);
    }
    fout << ans1 << ' ' << ans2 << endl;
    return 0;
}