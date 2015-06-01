/*
ID: LimitW
PROG: friday
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

int is_leap(int x)
{
	x += 1900;
	if((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
		return 1;
	else return 0;
}

int main(){
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n;
    fin >> n;
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int ans[7];
    memset(ans,0,sizeof(ans));
    int start = 0;
    for(int i = 0; i < n; i++)
    {
    	if(is_leap(i)) month[1] = 29;
    	else month[1] = 28;
    	for(int m = 0; m < 12; m++)
    	{
    		start += 12;
    		start %= 7;
    		ans[start]++;
    		start += month[m] - 12;
    		start %= 7;
    	}
    }
    fout << ans[5] << ' ' << ans[6] << ' ';
    for(int i = 0; i < 4; i++)
    	fout << ans[i] << ' ';
    fout << ans[4] << endl;
    return 0;
}