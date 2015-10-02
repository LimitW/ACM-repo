/*
 * Title:Physical Examination
 * Author:LimitW
 * Date:2014.8.18
 * Source:2012 JinHuaSite A
 * Note:贪心 水题
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
struct qu{
	long long a,b;
}q[100010];
const long long MOD = 365*24*60*60;

int cmp(qu a, qu b){
	return a.a*b.b < b.a*a.b;
}

int main(){
	int n;
	while(cin>>n && n){
		int i;
		for(i=0;i<n;i++)
			scanf("%I64d%I64d",&q[i].a,&q[i].b);
		sort(q,q+n,cmp);
		long long sum = q[0].a;
		for(i=1;i<n;i++){
			sum += sum * q[i].b + q[i].a;
			sum %= MOD;
		}
		printf("%I64d\n",sum);
	}
	return 0;
}