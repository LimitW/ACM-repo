/************************************************
 * Title:
 * Author:LimitW
 * Date:
 * Source:
 * Note:
*************************************************/

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

using namespace std;

const int INF = 0x3f3f3f3f;

int C(int n,int un){
    int ans  =  1;
    for(int i = 2; i <= n ;i++)
        ans *= i;
    for(int i = 2; i <= un; i++)
        ans /= i;
    for(int i = 2; i <= n - un; i++)
        ans /= i;
    return ans;
}

int main(){
	string a,b;
	cin >> a >> b;
	int an = 0,un = 0;
	int n = a.length();
	for(int i = 0; i < n; i++)
	{
		if(a[i] == '+') an++;
		else an--;
		if(b[i] == '?') un++;
	}
	int p[10];
	memset(p,0,sizeof(p));
	for(int i = 0; i <= un; i++){
        for(int j = 0; j < n; j++)
        {
            if(b[j] == '+') p[i]++;
            if(b[j] == '-') p[i]--;
        }
        p[i] += i;
        p[i] -= (un - i);
	}
	double ans = 0;
	for(int i = 0; i <= un; i++)
		if(p[i] == an) ans += C(un,i);
	ans /= (1<<un);
	printf("%.9lf\n",ans);
	return 0;
}