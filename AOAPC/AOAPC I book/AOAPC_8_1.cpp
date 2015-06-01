/*
 * Title:
 * Author:LimitW
 * Date:2014.8.17
 * Source:AOAPC I 8-1
 * Note:最大连续和 分治复杂度O(nlogn) 附O(n)算法
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

int maxsum(int *a,int left,int right){
	if(left == right) return max(0,a[left]);
	int mid = (left+right)/2;
	int maxleft = maxsum(a,left,mid); //分治，左侧最大
	int maxright = maxsum(a,mid+1,right);//分治，右侧最大
	int ans = max(maxleft,maxright);
	int i;
	int maxleftbordersum = 0,leftbordersum = 0;//合并：从分界点开始向左的最大连续和
	for(i = mid; i >= left; i--){
		leftbordersum += a[i];
		maxleftbordersum = max(maxleftbordersum,leftbordersum);
	}
	int maxrightbordersum = 0,rightbordersum = 0;//合并：从分界点开始向右的最大连续和
	for(i = mid+1; i <= right; i++){
		rightbordersum += a[i];
		maxrightbordersum = max(maxrightbordersum,rightbordersum);
	}
	return max(ans,maxleftbordersum+maxrightbordersum);
}

int main(){
	int A[] = {1,2,-3,-4,5};
	cout<<maxsum(A,0,4)<<endl;
	system("pause");
	return 0;
}

/* O(n)算法
int maxsum(const long * tmp,int num)
{
	int max=0,sum=0;
	for(int i=0;i<num;i++)
	{
		sum+=tmp[i];
		if(max<sum) max=sum;
		else if(sum<0) sum=0;
	}
	return max;
}*/