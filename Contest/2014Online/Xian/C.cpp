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
const int maxn = 5e4 + 10;
int a[maxn],b[maxn];

int cmp(const int a,const int b){
	return a > b;
}

int main(){
	int n;
	while(cin >> n){
		for(int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		memset(b,0,sizeof(b));
		int l = 0;
		for(int i = 0; i < n - 1; i++)
		{
			if(a[i] == a[i+1]) b[l]++;
			else l++;
		}
		l++;
		if(n == 1) { b[0] = 1; l = 1; }
		for(int i = 0; i < l; i++)
			b[i]++;
        if(n == 1) { b[0] = 1; l = 1; }
		for(int i = 0; i < l; i++)
            cout << b[i] << ' ';
        cout <<endl;
		long long sum = 0;

		printf("%I64d\n",sum);
	}
	return 0;
}
/*
10
3 4 2 4 4 2 4 3 2 2
*/