/*
 * Title:
 * Author:LimitW
 * Date:2014.8.21
 * Source:Codeforces round 262 B
 * Note:数学 枚举
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

const int maxx = 1e9;

long long modpow(int i,int a){
	long long ans = 1;
	while(a--) ans *= i;
	return ans;
}

long long get_s(long long x){
	long long sum = 0;
	while(x){
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	vector<int> v;
	int i;
	for(i = 1; i <= 90; i++){
		long long x = b * modpow(i,a) + c;
		if(i == get_s(x) && x < maxx && x > 0)
			v.push_back(x);
	}
	int n = v.size();
	sort(v.begin(),v.end());
	printf("%d\n",n);
	for(i = 0; i < n - 1; i++)
		printf("%d ",v[i]);
	if(n) printf("%d\n",v[n-1]);
	return 0;
}