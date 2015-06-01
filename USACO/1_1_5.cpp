/*
ID: LimitW
PROG: beads
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

int main(){
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int n;
    fin >> n;
    string s;
    fin >> s;
    s = s + s;
    int ans = 0;
    for(int i = 0; i < s.length() / 2; i++)
    {
    	if(s[i] == 'w') continue;
    	if(i > 0 && s[i] == s[i-1]) continue;
    	char color = s[i];
    	int tmp = 0;
    	int flag = 0;
    	for(int j = i; j < s.length(); j++)
    	{
    		if(s[j] == color || s[j] == 'w') tmp++;
    		else break;
    	}
    	color = color == 'r' ? 'b' : 'r';
    	for(int j = i - 1; j >= 0; j--)
    	{
    		if(s[j] == color || s[j] == 'w') tmp++;
    		else break;
    	}
    	ans = max(tmp,ans);
    }
    if(ans > n || ans == 0) ans = n;
    fout << ans << endl;
    return 0;
}