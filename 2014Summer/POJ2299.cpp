/*
 * Title:
 * Author:LimitW
 * Date:2014.8.17
 * Source:poj 2299
 * Note:分治 归并排序 逆序对数
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

long long a[500010],t[500010];
long long cnt;

long long merge_sort(long long *a,int left,int right,long long *t){
	if(right > left){
		int mid = (right+left)/2;
		int p = left, q = mid+1, i = left;
		merge_sort(a,left,mid,t);
		merge_sort(a,mid+1,right,t);
		while(p <= mid || q <= right){
			if(q > right || (p <= mid && a[p] <= a[q]))
				t[i++] = a[p++];
			else if(p > mid || (q <= right && a[p] > a[q])){
				t[i++] = a[q++];
				if(p <= mid)
					cnt += (mid - p + 1);
			}
		}
		for(i=left;i<=right;i++){
			a[i] = t[i];
		}
	}
	return cnt;
}

int main(){
	int n;
	while(cin>>n && n){
		int i;
		for(i=0;i<n;i++)
			scanf("%I64d",&a[i]);
		cnt = 0;
		cout<<merge_sort(a,0,n-1,t)<<endl;
	}
	return 0;
}
