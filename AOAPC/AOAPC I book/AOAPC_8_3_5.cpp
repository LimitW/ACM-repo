/*
 * Title:
 * Author:LimitW
 * Date:2014.8.18
 * Source:AOAPC I
 * Note:二分 最大值最小化
*/
//将一个包含n个正整数的序列划分为k个连续的子序列，第i个序列的各数之和为S(i)，使S(i)尽量小。

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

int n,m;
int a[100010];

int is_part(int x){
	int seg = 0, sum = 0;
	int i;
	for(i = 0; i < n; i++){
		if(a[i] > x) return 0;
		if(a[i] + sum > x){
			sum = a[i];
			seg++;
			if(seg > m - 1) return 0;
		}
		else sum += a[i];
	}
	return 1;
}

int main(){
	cin >> n >> m;
	int minv = 1 << 31;
	int maxv = 0;
	int i;
	for(i = 0; i < n; i++){
		cin >> a[i];
		minv = min(minv,a[i]);
		maxv += a[i];
	}
	int l = minv,r = maxv;
	while(l < r){
		int mid = (l + r) / 2;
		if(is_part(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n",l);
	return 0;
}