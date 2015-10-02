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

#define LL long long

int a[100010],t[100010];

LL cnt;

LL merge_sort(int *a,int left,int right,int *t){
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
					cnt += (LL)(mid - p + 1);
			}
		}
		for(i=left;i<=right;i++){
			a[i] = t[i];
		}
	}
	return cnt;
}

int main(){
	int n , k;
	while(cin >> n >> k){
		for(int i = 0;i < n; i++)
			scanf("%d",&a[i]);
		cnt = 0;
		LL ans =  merge_sort(a,0,n-1,t) - k;
		if(ans < 0) ans = 0;
		cout<< ans <<endl;
	}
	return 0;
}
