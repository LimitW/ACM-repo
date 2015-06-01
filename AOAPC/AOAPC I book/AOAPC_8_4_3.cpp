/*
 * Title:乘船问题
 * Author:LimitW
 * Date:2014.8.19
 * Source:AOAPC I
 * Note:贪心
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

using namespace std;

int main(){
	int n,w[100],C;
	cin>>n>>C;
	int i,j;
	for(i=0;i<n;i++)
		cin>>w[i];
	sort(w,w+n);
	if(w[n-1] > C){
		printf("-1\n");
		return 0;
	}
	int ans = 0, res = n, single = 0;
	i = 0;
	j = n - 1;
	while(res && i <= j){
		if(w[i] + w[j] <= C && i != j){
			i++; j--;
			ans += (single + 1);
			res -= (single + 2);
			single = 0;
		}
		else{ j--; single++; }
	}
	ans += single;
	printf("%d\n",ans);
	return 0;
}