/*
 * Title:Alice's Print Service
 * Author:LimitW
 * Date:2014.7.28
 * Source:2013 ChangShaSite A
 * Note:C输入输出 upper_bound
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

const int maxn = 100100;

long long price[maxn],limit[maxn];
long long min_total[maxn];

int main(){
	int T;
	cin>>T;
	while(T--){
		long long n,m;
		scanf("%I64d%I64d",&n,&m);
		int i;
		for(i = 0;i < n;i++){
            scanf("%I64d%I64d",&limit[i],&price[i]);
		}
		min_total[n-1] = (limit[n-1]*price[n-1]);
		for(i=n-2;i>=0;i--){
			long long tmp = (limit[i] * price[i]);
			min_total[i] = min(tmp,min_total[i+1]);
		}
		long long choice;
		long long pages;
		for(i=0;i<m;i++){
			scanf("%I64d",&pages);
			int num;
			num = upper_bound(limit,limit+n,pages) - limit;
			num--;
            if(num == n-1)
            	choice = (pages * price[n-1]);
            else
            	choice = min(pages * price[num],min_total[num+1]);
            printf("%I64u\n",choice);
		}
	}
    return 0;
}