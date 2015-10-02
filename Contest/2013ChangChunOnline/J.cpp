/*
 * Title:Flyer
 * Author:LimitW
 * Date:2014.8.15
 * Source:2013 ChangChunSite online J
 * Note:二分
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

const int maxn = 20005;
long long a[maxn],b[maxn],c[maxn];

long long find(int n,long long mid){//学号在1-k的区间内共发了多少张传单
	long long k,sum = 0;
	int i;
	for(i=0;i<n;i++){
		k = min(mid,b[i]);
		if(k >= a[i])
			sum += (k - a[i]) / c[i] + 1;
	}
	return sum;
}

int main(){
    int n;
	while(scanf("%d",&n)!=EOF){
		int i;
		for(i=0;i<n;i++)
			scanf("%I64d%I64d%I64d",&a[i],&b[i],&c[i]);
		long long left = 0;
		long long right = 1ll << 31;
		long long mid;
		while(left < right){
			mid = (left + right) / 2;
			if(find(n,mid) % 2) right = mid;
			else left = mid + 1;
		}
		if(left == 1ll << 31)
			printf("DC Qiang is unhappy.\n");
		else{
			while(find(n,left) % 2 == 0) left--;
			printf("%I64d %I64d\n",left,find(n,left)-find(n,left-1));
		}
	}
	return 0;
}