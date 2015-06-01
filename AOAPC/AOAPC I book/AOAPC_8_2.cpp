/*
 * Title:
 * Author:LimitW
 * Date:2014.8.17
 * Source:AOAPC I 8-2
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

void merge_sort(int *a,int left,int right,int *t){
	if(right > left){
		int mid = (right+left)/2;
		int p = left, q = mid+1, i = left;
		merge_sort(a,left,mid,t);
		merge_sort(a,mid+1,right,t);
		while(p <= mid || q <= right){
			if(q > right || (p <= mid && a[p] <= a[q]))
				t[i++] = a[p++];
			else if(p > mid || (q <= right && a[p] > a[q]))
				t[i++] = a[q++];
		}
		for(i=left;i<=right;i++){
			a[i] = t[i];
		}
	}
}

int main(){
	int a[4]={3,1,2,4};
	int t[4];
	merge_sort(a,0,3,t);
	int i;
	for(i=0;i<4;i++)
		cout<<a[i]<<' ';
	cout<<endl;
	system("pause");
	return 0;
}