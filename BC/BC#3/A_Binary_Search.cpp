/*
 * Title:Task schedule
 * Author:LimitW
 * Date:2014.8.7
 * Source:BestCoder Round #3 A
 * Note:二分解法
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
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>

using namespace std;
const int maxn = 1e5 +10;

int t[maxn];
int ans[maxn];

//二分查找AC

int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&t[i]);
		sort(t,t+n);
		for(i=0;i<m;i++){
			int q;
			scanf("%d",&q);
			int num = lower_bound(t,t+n,q) - t; // (1,2,3,4) lower_bound(2) -> 2, upper_bound(2) -> 3
			if(num == n || t[num] != q)
				printf("%d\n",q);
			else{
				int low = num + 1,high = n;
				while(low < high){
					int mid = (low + high) / 2;
					if(t[mid] - q == mid - num)
						low = mid + 1;
					else
						high = mid;
				    }
				printf("%d\n",t[low-1]+1);
			}
		}
	}
	return 0;
}


